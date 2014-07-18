#include "User.h"

User::User(){}

User::~User() {}

User::User(int id_userP, QString lastnameP,QString firstnameP,QString usernameP,QString locationP,QString emailP,QString urlP,QString companyP, QString lastConnexionP)
{
    id_user = id_userP;
    lastname = lastnameP;
    firstname = firstnameP;
    username = usernameP;
    location = locationP;
    email = emailP;
    url = urlP;
    company = companyP;
    lastConnexion = lastConnexionP;
}

string User::getNewPassword()
{
     return md5("123456");
}

User User::getUserWithId(int id_user) {

    QString str_query;
    str_query.append("SELECT id_user, lastname, firstname, username, location, email, url, company, lastConnexion FROM user WHERE id_user = ");
    str_query.append(QString::number(id_user));

    QSqlQuery query(str_query);

    int number_id_user = query.record().indexOf("id_user");
    int number_lastname = query.record().indexOf("lastname");
    int number_firstname = query.record().indexOf("firstname");
    int number_username = query.record().indexOf("username");
    int number_location = query.record().indexOf("location");
    int number_email = query.record().indexOf("email");
    int number_url = query.record().indexOf("url");
    int number_company = query.record().indexOf("company");
    int number_lastConnexion = query.record().indexOf("lastConnexion");

    if(query.next()) {
         int id_user = query.value(number_id_user).toInt();
         QString lastname = query.value(number_lastname).toString();
         QString firstname = query.value(number_firstname).toString();
         QString username = query.value(number_username).toString();
         QString location = query.value(number_location).toString();
         QString email = query.value(number_email).toString();
         QString url = query.value(number_url).toString();
         QString company = query.value(number_company).toString();
         QString lastConnexion = query.value(number_lastConnexion).toString();

         User u(id_user, lastname, firstname, username, location, email, url, company, lastConnexion);

         return u;
    }

    User u;

    return u;
}

User User::getUserWithLogin(string login) {

    QString str_query;
    str_query.append("SELECT id_user, lastname, firstname, username, location, email, url, company, lastConnexion FROM user WHERE username = '");
    str_query.append(login.c_str());
    str_query.append("'");

    QSqlQuery query(str_query);

    int number_id_user = query.record().indexOf("id_user");
    int number_lastname = query.record().indexOf("lastname");
    int number_firstname = query.record().indexOf("firstname");
    int number_username = query.record().indexOf("username");
    int number_location = query.record().indexOf("location");
    int number_email = query.record().indexOf("email");
    int number_url = query.record().indexOf("url");
    int number_company = query.record().indexOf("company");
    int number_lastConnexion = query.record().indexOf("lastConnexion");

    if(query.next()) {
         int id_user = query.value(number_id_user).toInt();
         QString lastname = query.value(number_lastname).toString();
         QString firstname = query.value(number_firstname).toString();
         QString username = query.value(number_username).toString();
         QString location = query.value(number_location).toString();
         QString email = query.value(number_email).toString();
         QString url = query.value(number_url).toString();
         QString company = query.value(number_company).toString();
         QString lastConnexion = query.value(number_lastConnexion).toString();

         User u(id_user, lastname, firstname, username, location, email, url, company, lastConnexion);

         return u;
    }

    User u;

    return u;
}
