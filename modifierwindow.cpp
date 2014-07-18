#include "modifierwindow.h"
#include "ui_modifierwindow.h"

ModifierWindow::ModifierWindow(User user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifierWindow)
{
    ui->setupUi(this);
    userConnected = user;
    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setDatabaseName("ProjectOnline");
    db.setUserName("root");
    db.setPassword("");

    if(db.open())
    {
        User u = User::getUserWithId(userConnected.id_user);

        if(u.id_user == NULL) {
            QMessageBox::information(this, "Erreur interne", "Le systeme n'a pu récuperer les données utilisateurs sur la base de données.") ;
            this->hide();
        } else {

            ui->editName->setText(u.lastname);
            ui->editFirstName->setText(u.firstname);
            ui->editCompany->setText(u.company);
            ui->editMail->setText(u.email);
            ui->editUrl->setText(u.url);
            ui->editLocation->setText(u.location);

        }
    } else {
        QMessageBox::information(this, "Erreur interne", "Base de données inaccessible.") ;
        this->hide();
    }
}

ModifierWindow::~ModifierWindow()
{
    delete ui;
}

bool ModifierWindow::isLabel(QString str) {
   bool answer = (str.size() >= 3 && str.size() < 64);
   if(!answer)
       QMessageBox::information(this, "Mauvaise saisie", "Vous n'avez pas correctement rempli le formulaire, entre 3 et 64 caractères pour des champs de types varchar") ;
   return answer;
}

bool ModifierWindow::isText(QString str) {
    bool answer = (str.size() >= 3 && str.size() < 1024);
    if(!answer)
        QMessageBox::information(this, "Mauvaise saisie", "Vous n'avez pas correctement rempli le formulaire, entre 3 et 1024 caractères pour des champs de types texte") ;
    return answer;
}

bool ModifierWindow::isMail(QString str) {

   QString strPatt = "^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,4})$";
   QRegExp rx(strPatt);

   bool answer = rx.exactMatch(str);
   if(!answer)
       QMessageBox::information(this, "Mauvaise saisie", "Vous n'avez pas correctement rempli le formulaire, veuillez saisir un mail en bonne forme svp") ;
   return answer;
}

void ModifierWindow::on_dialog_rejected()
{
    db.close();
    this->hide();
}

void ModifierWindow::on_dialog_accepted()
{
    QString lastName = ui->editName->text();
    if(!isLabel(lastName))
        return;
    QString firstName = ui->editFirstName->text();
    if(!isLabel(firstName))
        return;
    QString company = ui->editCompany->text();
    if(company.size() > 0 && !isLabel(company))
        return;
    QString mail = ui->editMail->text();
    if(!isMail(mail))
        return;
    QString url = ui->editUrl->text();
    if(url.size() > 0 && !isText(url))
        return;
    QString location = ui->editLocation->text();
    if(!isLabel(location))
        return;

    QDateTime *dt = new QDateTime();
    QString now = dt->currentDateTime().toString("dd/MM/yyyy hh:mm:ss");

    User u =  userConnected;

    QString str_query;
    str_query.append("UPDATE user SET ");
    str_query.append("lastName = '" + lastName + "'");
    str_query.append(", firstName = '" + firstName + "'");
    str_query.append(", location ='" + location + "'");
    str_query.append(", email = '" + mail + "'");
    str_query.append(", url = '" + url + "'");
    str_query.append(", company = '" + company + "' ");
    str_query.append(" WHERE id_user = " + QString::number(u.id_user));

    QSqlQuery query;

    query.prepare(str_query);

    std::cout << str_query.toStdString();

    if(!query.exec()) {
        QMessageBox::information(this, "Erreur du serveur", "Erreur lors de la mise à jour des données en Base de données, veuillez contactez l'administrateur") ;
    }
    else {
        QMessageBox::information(this, "Mise à jour", "Les données utilisateur ont été mis a jour !") ;
        this->hide();
    }

}
