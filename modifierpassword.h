#ifndef MODIFIERPASSWORD_H
#define MODIFIERPASSWORD_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <QtSql/qsqlquery.h>
#include <QtSql/qsqldatabase.h>
#include <iostream>
#include "md5.h"
#include "User.h"

namespace Ui {
class modifierPassword;
}

class modifierPassword : public QDialog
{
    Q_OBJECT

public:
    explicit modifierPassword(User user, QWidget *parent = 0);
    ~modifierPassword();
    QSqlDatabase db;

private slots:
    void on_dialog_rejected();

    void on_dialog_accepted();

private:
    Ui::modifierPassword *ui;
    bool modifierPassword::isEqualsPassword(QString str, QString str_);
    bool modifierPassword::isPassword(QString str);
    bool modifierPassword::isCorrectPassword(int id_user, QString password);
    User userConnected;

};

#endif // MODIFIERPASSWORD_H
