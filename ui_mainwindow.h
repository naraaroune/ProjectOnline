/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *actionA_Propos;
    QAction *actionModifier_Donnees;
    QAction *actionModifier_Password;
    QWidget *centralwidget;
    QPushButton *pushButtonUploadFolder;
    QPushButton *pushButtonUploadFile;
    QLabel *labelPassword;
    QPushButton *pushButtonDownload;
    QLabel *labelUsername;
    QListWidget *listWidget;
    QPushButton *pushButtonNewFolder;
    QPushButton *pushButtonRename;
    QPushButton *pushButtonConnect;
    QLineEdit *lineEditUsername;
    QPushButton *pushButtonDelete;
    QLineEdit *lineEditPassword;
    QPushButton *pushButtonOpen;
    QPushButton *pushButtonSuscribe;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuOutil;
    QMenu *menuAide;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(475, 491);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionModifier_Donnees = new QAction(MainWindow);
        actionModifier_Donnees->setObjectName(QStringLiteral("actionModifier_Donnees"));
        actionModifier_Password = new QAction(MainWindow);
        actionModifier_Password->setObjectName(QStringLiteral("actionModifier_Password"));
        actionA_Propos = new QAction(MainWindow);
        actionA_Propos->setObjectName(QStringLiteral("actionA_Propos"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButtonUploadFolder = new QPushButton(centralwidget);
        pushButtonUploadFolder->setObjectName(QStringLiteral("pushButtonUploadFolder"));
        pushButtonUploadFolder->setGeometry(QRect(350, 190, 111, 23));
        pushButtonUploadFile = new QPushButton(centralwidget);
        pushButtonUploadFile->setObjectName(QStringLiteral("pushButtonUploadFile"));
        pushButtonUploadFile->setGeometry(QRect(350, 150, 111, 23));
        labelPassword = new QLabel(centralwidget);
        labelPassword->setObjectName(QStringLiteral("labelPassword"));
        labelPassword->setGeometry(QRect(80, 160, 51, 16));
        pushButtonDownload = new QPushButton(centralwidget);
        pushButtonDownload->setObjectName(QStringLiteral("pushButtonDownload"));
        pushButtonDownload->setGeometry(QRect(350, 110, 111, 23));
        labelUsername = new QLabel(centralwidget);
        labelUsername->setObjectName(QStringLiteral("labelUsername"));
        labelUsername->setGeometry(QRect(80, 120, 51, 16));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(30, 70, 301, 321));

        pushButtonRename = new QPushButton(centralwidget);
        pushButtonRename->setObjectName(QStringLiteral("pushButtonRename"));
        pushButtonRename->setGeometry(QRect(350, 310, 111, 23));


        pushButtonNewFolder = new QPushButton(centralwidget);
        pushButtonNewFolder->setObjectName(QStringLiteral("pushButtonNewFolder"));
        pushButtonNewFolder->setGeometry(QRect(350, 270, 111, 23));


        pushButtonConnect = new QPushButton(centralwidget);
        pushButtonConnect->setObjectName(QStringLiteral("pushButtonConnect"));
        pushButtonConnect->setGeometry(QRect(210, 30, 101, 23));
        lineEditUsername = new QLineEdit(centralwidget);
        lineEditUsername->setObjectName(QStringLiteral("lineEditUsername"));
        lineEditUsername->setGeometry(QRect(160, 120, 113, 20));
        pushButtonDelete = new QPushButton(centralwidget);
        pushButtonDelete->setObjectName(QStringLiteral("pushButtonDelete"));
        pushButtonDelete->setGeometry(QRect(350, 230, 111, 23));




        lineEditPassword = new QLineEdit(centralwidget);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));
        lineEditPassword->setGeometry(QRect(160, 160, 113, 20));
        pushButtonOpen = new QPushButton(centralwidget);
        pushButtonOpen->setObjectName(QStringLiteral("pushButtonOpen"));
        pushButtonOpen->setGeometry(QRect(350, 70, 111, 23));
        pushButtonSuscribe = new QPushButton(centralwidget);
        pushButtonSuscribe->setObjectName(QStringLiteral("pushButtonSuscribe"));
        pushButtonSuscribe->setGeometry(QRect(350, 30, 111, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 475, 21));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuOutil = new QMenu(menubar);
        menuOutil->setObjectName(QStringLiteral("menuOutil"));
        menuAide = new QMenu(menubar);
        menuAide->setObjectName(QStringLiteral("menuAide"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuOutil->menuAction());
        menubar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionQuitter);
        menuOutil->addAction(actionModifier_Donnees);
        menuOutil->addAction(actionModifier_Password);
        menuAide->addAction(actionA_Propos);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        actionModifier_Donnees->setText(QApplication::translate("MainWindow", "Modifier Donnees", 0));
        actionModifier_Password->setText(QApplication::translate("MainWindow", "Modifier Password", 0));
        actionA_Propos->setText(QApplication::translate("MainWindow", "A Propos", 0));
        pushButtonUploadFolder->setText(QApplication::translate("MainWindow", "Upload Folder", 0));
        pushButtonUploadFile->setText(QApplication::translate("MainWindow", "Upload File", 0));
        labelPassword->setText(QApplication::translate("MainWindow", "Password", 0));
        pushButtonDownload->setText(QApplication::translate("MainWindow", "T\303\251l\303\251charger", 0));
        labelUsername->setText(QApplication::translate("MainWindow", "Username", 0));
        pushButtonNewFolder->setText(QApplication::translate("MainWindow", "Cr\303\251er Dossier", 0));
        pushButtonRename->setText(QApplication::translate("MainWindow", "Renomer", 0));
        pushButtonConnect->setText(QApplication::translate("MainWindow", "Se connecter", 0));
        pushButtonDelete->setText(QApplication::translate("MainWindow", "Supprimer", 0));
        pushButtonOpen->setText(QApplication::translate("MainWindow", "Ouvrir", 0));
        pushButtonSuscribe->setText(QApplication::translate("MainWindow", "S'inscrire", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuOutil->setTitle(QApplication::translate("MainWindow", "Outil", 0));
        menuAide->setTitle(QApplication::translate("MainWindow", "Aide", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
