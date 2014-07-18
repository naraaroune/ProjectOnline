#include "modifierpassword.h"
#include "ui_modifierpassword.h"

modifierPassword::modifierPassword(User user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifierPassword)
{
    ui->setupUi(this);
    userConnected = user;

    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setDatabaseName("ProjectOnline");
    db.setUserName("root");
    db.setPassword("");

    if(!db.open())
    {
        QMessageBox::information(this, "Erreur interne", "Base de données inaccessible") ;

        this->hide();
    }

    this->ui->editCheckPassword->setEchoMode(QLineEdit::Password);
    this->ui->editLastPassword->setEchoMode(QLineEdit::Password);
    this->ui->editNewPassword->setEchoMode(QLineEdit::Password);
}

modifierPassword::~modifierPassword()
{
    delete ui;
}

bool modifierPassword::isEqualsPassword(QString str, QString str_) {
    bool answer = (str.compare(str_) == 0);
    if(!answer)
        QMessageBox::information(this, "Mauvaise saisie", "Les mots de passe ne sont pas identiques") ;
    return answer;
}

bool modifierPassword::isPassword(QString str) {
    bool answer = (str.size() >= 3 && str.size() < 32);
    if(!answer)
        QMessageBox::information(this, "Mauvaise saisie", "Vous n'avez pas correctement rempli le formulaire, entre 3 et 32 caractères pour le mot de passe") ;
    return answer;
}

bool modifierPassword::isCorrectPassword(int id_user, QString password) {
    QString str_query("SELECT id_user FROM user WHERE id_user = ");
    str_query.append(QString::number(id_user).toStdString().c_str());
    str_query.append(" AND password = '");
    str_query.append(md5(password.toStdString().c_str()).c_str());
    str_query.append("'");
    QSqlQuery query(str_query);

    bool answer =  query.next();

    if(!answer)
        QMessageBox::information(this, "Mauvaise saisie", "Vous n'avez pas correctement rempli le formulaire, le mot de passe saisi n'est pas correct") ;
    return answer;
}

void modifierPassword::on_dialog_rejected()
{
    db.close();
    this->hide();
}

void modifierPassword::on_dialog_accepted()
{
    QString ancien_password = ui->editLastPassword->text();
    QString new_password = ui->editNewPassword->text();
    QString check_password = ui->editCheckPassword->text();

    if(isCorrectPassword(userConnected.id_user, ancien_password) && isPassword(new_password) && isEqualsPassword(new_password, check_password)) {
        QString str_query;
        str_query.append("UPDATE user SET ");
        str_query.append("password = '");
        str_query.append(md5(new_password.toStdString()).c_str());
        str_query.append("' WHERE id_user = ");
        str_query.append(QString::number(userConnected.id_user));

        QSqlQuery query;

        query.prepare(str_query);

        if(!query.exec()) {
            QMessageBox::information(this, "Erreur du serveur", "Erreur lors de la mise à jour des données en Base de données, veuillez contactez l'administrateur") ;
        }
        else {
            QMessageBox::information(this, "Mise à jour", "Les données utilisateur ont été mis a jour !") ;
            this->hide();
        }
    }

}
