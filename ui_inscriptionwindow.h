/********************************************************************************
** Form generated from reading UI file 'inscriptionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSCRIPTIONWINDOW_H
#define UI_INSCRIPTIONWINDOW_H

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

class Ui_InscriptionWindow
{
public:
    QLabel *label_5;
    QDialogButtonBox *dialog;
    QLineEdit *editLocation;
    QLineEdit *editMail;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *editUrl;
    QLineEdit *editFirstName;
    QLabel *label_7;
    QLabel *label_6;
    QLineEdit *editLogin;
    QLineEdit *editCompany;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_8;
    QLineEdit *editName;

    void setupUi(QDialog *InscriptionWindow)
    {
        if (InscriptionWindow->objectName().isEmpty())
            InscriptionWindow->setObjectName(QStringLiteral("InscriptionWindow"));
        InscriptionWindow->resize(398, 383);
        label_5 = new QLabel(InscriptionWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(90, 170, 46, 13));
        dialog = new QDialogButtonBox(InscriptionWindow);
        dialog->setObjectName(QStringLiteral("dialog"));
        dialog->setGeometry(QRect(110, 300, 161, 23));
        dialog->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        editName = new QLineEdit(InscriptionWindow);
        editName->setObjectName(QStringLiteral("editName"));
        editName->setGeometry(QRect(150, 70, 161, 31));
        editFirstName = new QLineEdit(InscriptionWindow);
        editFirstName->setObjectName(QStringLiteral("editFirstName"));
        editFirstName->setGeometry(QRect(150, 100, 161, 31));
        editLogin = new QLineEdit(InscriptionWindow);
        editLogin->setObjectName(QStringLiteral("editLogin"));
        editLogin->setGeometry(QRect(150, 130, 161, 31));
        editLocation = new QLineEdit(InscriptionWindow);
        editLocation->setObjectName(QStringLiteral("editLocation"));
        editLocation->setGeometry(QRect(150, 160, 161, 31));
        editUrl = new QLineEdit(InscriptionWindow);
        editUrl->setObjectName(QStringLiteral("editUrl"));
        editUrl->setGeometry(QRect(150, 190, 161, 31));
        editMail = new QLineEdit(InscriptionWindow);
        editMail->setObjectName(QStringLiteral("editMail"));
        editMail->setGeometry(QRect(150, 220, 161, 31));
        editCompany = new QLineEdit(InscriptionWindow);
        editCompany->setObjectName(QStringLiteral("editCompany"));
        editCompany->setGeometry(QRect(150, 250, 161, 31));
        label_3 = new QLabel(InscriptionWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 110, 46, 13));
        label_4 = new QLabel(InscriptionWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 140, 46, 13));


        label_7 = new QLabel(InscriptionWindow);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(90, 200, 46, 13));
        label_6 = new QLabel(InscriptionWindow);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 230, 46, 13));


        label = new QLabel(InscriptionWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 30, 161, 20));
        label_2 = new QLabel(InscriptionWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 80, 46, 13));
        label_8 = new QLabel(InscriptionWindow);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(90, 260, 61, 16));


        retranslateUi(InscriptionWindow);

        QMetaObject::connectSlotsByName(InscriptionWindow);
    } // setupUi

    void retranslateUi(QDialog *InscriptionWindow)
    {

        InscriptionWindow->setWindowTitle(QApplication::translate("InscriptionWindow", "Dialog", 0));
        label->setText(QApplication::translate("InscriptionWindow", "SERVICE DES INSCRIPTIONS", 0));
        label_2->setText(QApplication::translate("InscriptionWindow", "Nom", 0));
        label_3->setText(QApplication::translate("InscriptionWindow", "Prenom", 0));
        label_4->setText(QApplication::translate("InscriptionWindow", "Login", 0));        
        label_5->setText(QApplication::translate("InscriptionWindow", "Location", 0));
        label_7->setText(QApplication::translate("InscriptionWindow", "Url", 0));
        label_6->setText(QApplication::translate("InscriptionWindow", "Email", 0));
        label_8->setText(QApplication::translate("InscriptionWindow", "Compagnie", 0));
    } // retranslateUi

};

namespace Ui {
    class InscriptionWindow: public Ui_InscriptionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSCRIPTIONWINDOW_H
