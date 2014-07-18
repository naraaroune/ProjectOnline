#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ftp.h"
#include "inscriptionwindow.h"
#include "modifierwindow.h"
#include "modifierpassword.h"
#include "User.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateListWidget();
    void updateFolder(QString dir);
    string wcharToString(WIN32_FIND_DATA fileInfo);
    void CompareFiles(string filename1,string filename2,string outputFileName);
    void deleteFile(QString path);
    void hideOrDisplay();
    bool getConnectedAtDb();
    void setConnectedAtDb(bool value);
    bool connectAt();
    void removeAllFiles();
    void removeDir(wstring folder);


    string getUserFirstname();
    void setUserFirstname(string value);


private slots:

    void on_pushButtonOpen_clicked();

    void on_pushButtonDownload_clicked();

    void on_pushButtonConnect_clicked();

    void on_pushButtonNewFolder_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonUploadFile_clicked();

    void on_pushButtonUploadFolder_clicked();

    void on_pushButtonSuscribe_clicked();

    void on_actionQuitter_triggered();

    void on_actionModifier_Donnees_triggered();

    void on_actionModifier_Password_triggered();

    void on_actionA_Propos_triggered();

    void on_pushButtonRename_clicked();

private:
    Ui::MainWindow *ui;
    FTP ftp;
    bool connectedAtDb;
    User userConnected;
    string userFirstname;
};

#endif // MAINWINDOW_H
