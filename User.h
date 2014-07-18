#ifndef USER_H
#define USER_H

#include<string>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QVariant>
#include "md5.h"
#include <iostream>
#include <QMessageBox>

using namespace std;

class User {
public:

    User();    
    User::User(int id_userP, QString lastnameP,QString firstnameP,QString usernameP,QString locationP,QString emailP,QString urlP,QString companyP, QString lastConnexionP);
   ~User();
    static string getNewPassword();
    static User getUserWithId(int id_user);
    static User getUserWithLogin(string login);
    QString lastname, firstname, username, location, email, url, company, lastConnexion;
    int id_user;

private:




};
#endif // USER_H
