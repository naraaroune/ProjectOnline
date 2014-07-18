/********************************************************************************
** Form generated from reading UI file 'modifierwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFIERWINDOW_H
#define UI_MODIFIERWINDOW_H

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

class Ui_ModifierWindow
{
public:
    QDialogButtonBox *dialog;
    QLineEdit *editMail;
    QLabel *label_3;
    QLineEdit *editFirstName;
    QLabel *label_8;
    QLineEdit *editCompany;
    QLabel *label_6;
    QLineEdit *editLocation;
    QLineEdit *editUrl;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_7;
    QLineEdit *editName;
    QLabel *label;

    void setupUi(QDialog *ModifierWindow)
    {
        if (ModifierWindow->objectName().isEmpty())
            ModifierWindow->setObjectName(QStringLiteral("ModifierWindow"));
        ModifierWindow->resize(417, 363);
        dialog = new QDialogButtonBox(ModifierWindow);
        dialog->setObjectName(QStringLiteral("dialog"));
        dialog->setGeometry(QRect(110, 290, 161, 23));
        dialog->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        editName = new QLineEdit(ModifierWindow);
        editName->setObjectName(QStringLiteral("editName"));
        editName->setGeometry(QRect(150, 60, 161, 31));
        editFirstName = new QLineEdit(ModifierWindow);
        editFirstName->setObjectName(QStringLiteral("editFirstName"));
        editFirstName->setGeometry(QRect(150, 90, 161, 31));
        editLocation = new QLineEdit(ModifierWindow);
        editLocation->setObjectName(QStringLiteral("editLocation"));
        editLocation->setGeometry(QRect(150, 150, 161, 31));
        editUrl = new QLineEdit(ModifierWindow);
        editUrl->setObjectName(QStringLiteral("editUrl"));
        editUrl->setGeometry(QRect(150, 180, 161, 31));
        editMail = new QLineEdit(ModifierWindow);
        editMail->setObjectName(QStringLiteral("editMail"));
        editMail->setGeometry(QRect(150, 210, 161, 31));
        editCompany = new QLineEdit(ModifierWindow);
        editCompany->setObjectName(QStringLiteral("editCompany"));
        editCompany->setGeometry(QRect(150, 240, 161, 31));
        label_3 = new QLabel(ModifierWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 100, 46, 13));

        label_8 = new QLabel(ModifierWindow);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(90, 250, 61, 16));

        label_6 = new QLabel(ModifierWindow);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 220, 46, 13));


        label_2 = new QLabel(ModifierWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 70, 46, 13));
        label_5 = new QLabel(ModifierWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(90, 160, 46, 13));
        label_7 = new QLabel(ModifierWindow);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(90, 190, 46, 13));

        label = new QLabel(ModifierWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 30, 161, 20));

        retranslateUi(ModifierWindow);

        QMetaObject::connectSlotsByName(ModifierWindow);
    } // setupUi

    void retranslateUi(QDialog *ModifierWindow)
    {
        ModifierWindow->setWindowTitle(QApplication::translate("ModifierWindow", "Dialog", 0));
        label_3->setText(QApplication::translate("ModifierWindow", "Prenom", 0));
        label_8->setText(QApplication::translate("ModifierWindow", "Compagnie", 0));
        label_6->setText(QApplication::translate("ModifierWindow", "Email", 0));
        label_2->setText(QApplication::translate("ModifierWindow", "Nom", 0));
        label_5->setText(QApplication::translate("ModifierWindow", "Location", 0));
        label_7->setText(QApplication::translate("ModifierWindow", "Url", 0));
        label->setText(QApplication::translate("ModifierWindow", "Modification de donn\303\251es", 0));
    } // retranslateUi

};

namespace Ui {
    class ModifierWindow: public Ui_ModifierWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIERWINDOW_H
