#ifndef INSCRIPTIONWINDOW_H
#define INSCRIPTIONWINDOW_H

#include <QtSql/QSqlError>
#include <QMainWindow>
#include <QMessageBox>
#include "User.h"
#include <iostream>
#include <QtSql/qsqlquery.h>
#include <QtSql/qsqldatabase.h>
#include "qdatetime.h"
#include <QDialog>

namespace Ui {
class InscriptionWindow;
}

class InscriptionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InscriptionWindow(QWidget *parent = 0);
    ~InscriptionWindow();
    QSqlDatabase db;

private slots:
   void on_dialog_rejected();
   void on_dialog_accepted();

private:
    Ui::InscriptionWindow *ui;
    bool isLabel(QString str);
    bool isText(QString str);
    bool isMail(QString str);
    bool isLoginExist(QSqlDatabase db, QString str);

};

#endif // INSCRIPTIONWINDOW_H
