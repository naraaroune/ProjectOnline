#ifndef MODIFIERWINDOW_H
#define MODIFIERWINDOW_H

#include <QtSql/QSqlError>
#include <QMainWindow>
#include <QLineEdit>
#include <QMessageBox>
#include <iostream>
#include <QtSql/qsqlquery.h>
#include <QtSql/qsqldatabase.h>
#include <QDialog>
#include "qdatetime.h"
#include "User.h"

namespace Ui {
class ModifierWindow;
}

class ModifierWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierWindow(User user, QWidget *parent = 0);
    ~ModifierWindow();
    QSqlDatabase db;

private slots:
    void on_dialog_rejected();

    void on_dialog_accepted();

private:
    Ui::ModifierWindow *ui;
    bool isLabel(QString str);
    bool isText(QString str);
    bool isMail(QString str);
    User userConnected;

};

#endif // MODIFIERWINDOW_H
