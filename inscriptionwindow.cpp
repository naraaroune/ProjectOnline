#include "inscriptionwindow.h"
#include "ui_inscriptionwindow.h"

InscriptionWindow::InscriptionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InscriptionWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QMYSQL");
}

InscriptionWindow::~InscriptionWindow()
{
    delete ui;
}


bool InscriptionWindow::isLabel(QString str) {
   bool answer = (str.size() >= 3 && str.size() < 64);
   if(!answer)
       QMessageBox::information(this, "Mauvaise saisie", "Vous n'avez pas correctement rempli le formulaire, entre 3 et 64 caractères pour des champs de types varchar") ;
   return answer;
}

bool InscriptionWindow::isText(QString str) {
    bool answer = (str.size() >= 3 && str.size() < 1024);
    if(!answer)
        QMessageBox::information(this, "Mauvaise saisie", "Vous n'avez pas correctement rempli le formulaire, entre 3 et 1024 caractères pour des champs de types texte") ;
    return answer;
}

bool InscriptionWindow::isMail(QString str) {

   QString strPatt = "^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,4})$";
   QRegExp rx(strPatt);

   bool answer = rx.exactMatch(str);
   if(!answer)
       QMessageBox::information(this, "Mauvaise saisie", "Vous n'avez pas correctement rempli le formulaire, veuillez saisir un mail en bonne forme svp") ;
   return answer;
}

bool InscriptionWindow::isLoginExist(QSqlDatabase db, QString str) {

    QString str_query("SELECT id_user FROM user WHERE username = '");
    str_query.append(str.toStdString().c_str());
    str_query.append("'");

    QSqlQuery query(str_query);

    return query.next();
}

void InscriptionWindow::on_dialog_accepted()
{
    QString lastName = ui->editName->text();
    if(!isLabel(lastName))
        return;
    QString firstName = ui->editFirstName->text();
    if(!isLabel(firstName))
        return;
    QString login = ui->editLogin->text();
    if(!isLabel(login))
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

    db.setHostName("localhost");
    db.setDatabaseName("ProjectOnline");
    db.setUserName("root");
    db.setPassword("");

    if(db.open())
    {
        if(isLoginExist(db, login)) {
            QMessageBox::information(this, "Erreur de saisie", "Erreur lors de l'insertion des données en Base de données, le login existe deja pour un autre utilisateur") ;
            return;
        }

        QString str_query;
        str_query.append("INSERT INTO user VALUES (''");
        str_query.append(", '" + lastName + "'");
        str_query.append(", '" + firstName + "'");
        str_query.append(", '" + login + "'");
        str_query.append(", '");
        str_query.append(User::getNewPassword().c_str()); str_query.append("'");
        str_query.append(", '" + location + "'");
        str_query.append(", '" + mail + "'");
        str_query.append(", '" + url + "'");
        str_query.append(", '" + company + "'");
        str_query.append(", '" + now + "')");

        cout<<str_query.toStdString();

        QSqlQuery query;
        query.prepare(str_query);

        if(!query.exec()) {
            QMessageBox::information(this, "Erreur du serveur", "Erreur lors de l'insertion des données en Base de données, veuillez contactez l'administrateur") ;
        }
        else {
            QMessageBox::information(this, "Insertion réussie", "L'utilisateur a bien été enregistré !") ;

            this->hide();
        }

    }  else {
        QMessageBox::information(this, "Erreur interne", "Base de données inaccessible.") ;
        this->hide();
    }
}

void InscriptionWindow::on_dialog_rejected()
{
    db.close();
    this->hide();
}
