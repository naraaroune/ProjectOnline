/********************************************************************************
** Form generated from reading UI file 'modifierpassword.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFIERPASSWORD_H
#define UI_MODIFIERPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_modifierPassword
{
public:
    QDialogButtonBox *dialog;
    QLineEdit *editNewPassword;
    QLineEdit *editCheckPassword;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *editLastPassword;
    QLabel *label_9;
    QLabel *label_10;

    void setupUi(QDialog *modifierPassword)
    {
        if (modifierPassword->objectName().isEmpty())
            modifierPassword->setObjectName(QStringLiteral("modifierPassword"));
        modifierPassword->resize(389, 380);
        dialog = new QDialogButtonBox(modifierPassword);
        dialog->setObjectName(QStringLiteral("dialog"));
        dialog->setGeometry(QRect(110, 210, 161, 23));
        dialog->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        editLastPassword = new QLineEdit(modifierPassword);
        editLastPassword->setObjectName(QStringLiteral("editLastPassword"));
        editLastPassword->setGeometry(QRect(180, 90, 161, 31));
        editNewPassword = new QLineEdit(modifierPassword);
        editNewPassword->setObjectName(QStringLiteral("editNewPassword"));
        editNewPassword->setGeometry(QRect(180, 120, 161, 31));
        editCheckPassword = new QLineEdit(modifierPassword);
        editCheckPassword->setObjectName(QStringLiteral("editCheckPassword"));
        editCheckPassword->setGeometry(QRect(180, 150, 161, 31));
        label_2 = new QLabel(modifierPassword);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 90, 141, 31));
        label = new QLabel(modifierPassword);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 50, 161, 20));

        label_9 = new QLabel(modifierPassword);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 120, 131, 31));
        label_10 = new QLabel(modifierPassword);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 150, 131, 31));

        retranslateUi(modifierPassword);

        QMetaObject::connectSlotsByName(modifierPassword);
    } // setupUi

    void retranslateUi(QDialog *modifierPassword)
    {
        modifierPassword->setWindowTitle(QApplication::translate("modifierPassword", "Dialog", 0));
        label_2->setText(QApplication::translate("modifierPassword", "Tapez l'ancien mot de passe", 0));
        label->setText(QApplication::translate("modifierPassword", "Modification de donn\303\251es", 0));
        label_9->setText(QApplication::translate("modifierPassword", "Tapez le nouveau", 0));
        label_10->setText(QApplication::translate("modifierPassword", "Retapez le mot de passe", 0));
    } // retranslateUi

};

namespace Ui {
    class modifierPassword: public Ui_modifierPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIERPASSWORD_H
