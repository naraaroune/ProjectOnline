#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QProgressBar>
#include <QSysInfo>
#include <QDir>
#include <iostream>
#include <QFile>
#include "qdatetime.h"
#include <QtDebug>
#include <QSqlError>

#include <qapplication.h>
#include <qsqlquery.h>
#include <qsqldatabase.h>

using namespace  std;
using std::ifstream;
using std::ofstream;
#include <fstream>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setConnectedAtDb(false);
    hideOrDisplay();

    this->ui->lineEditPassword->setEchoMode(QLineEdit::Password);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: CompareFiles(string filename1,string filename2,string outputFileName)
{
    ifstream file1,file2;

    file1.open(filename1,ios::binary);
    file2.open(filename2,ios::binary);
    ofstream fichier(outputFileName, ios::out);
//---------- compare number of lines in both files ------------------
    int c1,c2;
    c1 = 0; c2 = 0;
    string str;
    while(!file1.eof())
    {
        getline(file1,str);
        c1++;
    }
    file1.clear();   //  sets a new value for the error control state
    file1.seekg(0,ios::beg);
    while(!file2.eof())
    {
        getline(file2,str);
        c2++;
    }
    file2.clear();
    file2.seekg(0,ios::beg);

    if(c1 != c2)
    {
        fichier << "Different number of lines in files!" << "\n";
        fichier << "file1 has " << c1 << " lines and file2 has " << c2 << " lines" << "\n";

        cout << "Different number of lines in files!" << "\n";
        cout << "file1 has " << c1 << " lines and file2 has " << c2 << " lines" << "\n";
    }
//---------- compare two files line by line ------------------
    char string1[256], string2[256];
    int j = 0;
    while(!file1.eof())
    {
        file1.getline(string1,256);
        file2.getline(string2,256);
        j++;
        if(strcmp(string1,string2) != 0)
        {
            fichier << j << "-the strings are not equal" << "\n";
            fichier << "   " << string1 << "\n";
            fichier << "   " << string2 << "\n";

            cout << j << "-the strings are not equal" << "\n";
            cout << "   " << string1 << "\n";
            cout << "   " << string2 << "\n";
        }
    }
    fichier.close();
}

void MainWindow :: hideOrDisplay()
{
    if (getConnectedAtDb())
    {
        ui->labelUsername->setVisible(false);
        ui->labelPassword->setVisible(false);
        ui->lineEditUsername->setVisible(false);
        ui->lineEditPassword->setVisible(false);
        ui->pushButtonSuscribe->setVisible(false);

        ui->pushButtonRename->setVisible(true);
        ui->pushButtonUploadFolder->setVisible(true);
        ui->pushButtonUploadFile->setVisible(true);
        ui->listWidget->setVisible(true);
        ui->pushButtonDownload->setVisible(true);
        ui->pushButtonDelete->setVisible(true);
        ui->pushButtonNewFolder->setVisible(true);
        ui->pushButtonOpen->setVisible(true);
    }
    else
    {
        ui->labelUsername->setVisible(true);
        ui->labelPassword->setVisible(true);
        ui->lineEditUsername->setVisible(true);
        ui->lineEditPassword->setVisible(true);
        ui->pushButtonSuscribe->setVisible(true);

        ui->pushButtonRename->setVisible(false);
        ui->pushButtonUploadFolder->setVisible(false);
        ui->pushButtonUploadFile->setVisible(false);
        ui->listWidget->setVisible(false);
        ui->pushButtonDownload->setVisible(false);
        ui->pushButtonDelete->setVisible(false);
        ui->pushButtonNewFolder->setVisible(false);
        ui->pushButtonOpen->setVisible(false);
    }
}

bool MainWindow :: getConnectedAtDb()
{
    return connectedAtDb;
}

void MainWindow :: setConnectedAtDb(bool value)
{
    connectedAtDb=value;
}


void MainWindow :: deleteFile(QString path)
{
    QDir qdir(path);
    QFileInfoList fileInfoList = qdir.entryInfoList();

    for (int i = 2; i < fileInfoList.size(); i++)
    {
        QFileInfo info(fileInfoList.at(i));
        if (!info.isDir())
        {
            QFile file(info.absoluteFilePath());
            file.remove();
        }
    }
}

void MainWindow :: updateFolder(QString folder)
{
    deleteFile("../ProjectOnline/Test");
    wstring wstrFolder=folder.toStdWString();
    wstrFolder=wstrFolder.substr(wstrFolder.find_last_of(L"/")+1);

    ftp.mkdir(wstrFolder);
    ftp.cd(wstrFolder);
    QDir qdir(folder);
    QFileInfoList fileInfoList = qdir.entryInfoList();

    for (int i = 2; i < fileInfoList.size(); i++)
    {

        QFileInfo info(fileInfoList.at(i));
        cout <<"Filename: "<<info.fileName().toStdString()<<endl;
        if (info.isDir())
        {
            updateFolder(info.absoluteFilePath());
            ftp.cd(L"..");
        }
        else
        {
            ftp.upload(info.absoluteFilePath().toStdWString(),info.fileName().toStdWString());
        }
    }
}

void MainWindow :: updateListWidget()
{
    ftp.clearList();
    ui->listWidget->clear();

    if(ftp.gethandle())
    {
        ftp.DisplayFtpDir(ftp.getHFtpSession(),INTERNET_FLAG_NEED_FILE,0);
        for(int i=0;i<ftp.getSizeOfListFiles();i++)
        {
            QListWidgetItem *newItem = new QListWidgetItem;
            wstring item=ftp.getListFiles()[i];
            newItem->setText(QString::fromWCharArray(item.c_str()));
            ui->listWidget->insertItem(i,newItem);
        }
        for(int i=0;i<ftp.getSizeOfListFolders()-1;i++)
        {
            QListWidgetItem *newItem = new QListWidgetItem;
            wstring item=ftp.getListFolders()[i+1];
            newItem->setText(QString::fromWCharArray(item.c_str()));

            newItem->setIcon(QIcon("./folder.png"));
            ui->listWidget->insertItem(i,newItem);
        }
    }
    else
        ui->listWidget->clear();
}

void MainWindow::on_pushButtonOpen_clicked()
{
     for(int i=0;i<ftp.getSizeOfListFolders()-1;i++)
    {
        QListWidgetItem *newItem = new QListWidgetItem;
        wstring item=ftp.getListFolders()[i+1];
        newItem->setText(QString::fromWCharArray(item.c_str()));
        if(newItem->text()==ui->listWidget->currentItem()->text())
        {
            ftp.cd(newItem->text().toStdWString());
            updateListWidget();
            return;
        }
    }
}

void MainWindow::on_pushButtonDownload_clicked()
{
    for(int i=0;i<ftp.getSizeOfListFolders()-1;i++)
   {
       QListWidgetItem *newItem = new QListWidgetItem;
       wstring item=ftp.getListFolders()[i+1];
       newItem->setText(QString::fromWCharArray(item.c_str()));
       if(newItem->text()==ui->listWidget->currentItem()->text())
       {//zip -r yourzipfilename.zip directoryname
           ftp.cd(newItem->text().toStdWString());
           ftp.downloadFolder(ftp.getHFtpSession(),INTERNET_FLAG_NEED_FILE,ftp.getcd(),QDir::homePath().toStdWString()+L"/Desktop");
         //  ftp.cd(L"..");

           //ftp.downloadFolder(ftp.getHFtpSession(),INTERNET_FLAG_NEED_FILE,ftp.getcd(),QDir::homePath().toStdWString()+L"/Desktop");
           return;
       }
   }
    string strPathLocal=QDir::homePath().toStdString()+"/Desktop/"+ui->listWidget->currentItem()->text().toStdString();
    wstring wstrPathLocal(strPathLocal.begin(),strPathLocal.end());
    ftp.download(ui->listWidget->currentItem()->text().toStdWString(),wstrPathLocal);
}

string MainWindow :: getUserFirstname()
{
    return userFirstname;
}
void MainWindow :: setUserFirstname(string value)
{
    userFirstname=value;
}

bool MainWindow :: connectAt()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    if(!getConnectedAtDb())
    {
        string resultUser="";
        string resultPass="";
        string resultUsername="";

        string username=ui->lineEditUsername->text().toStdString();
        string password= md5(ui->lineEditPassword->text().toStdString());


         db.setHostName("localhost");
         db.setDatabaseName("ProjectOnline");
         db.setUserName("root");
         db.setPassword("");



         if(db.open())
         {
             QSqlQuery query("SELECT * from user ");
             while(query.next())
             {

                 resultUsername=query.value(2).toString().toStdString();
                 resultUser=query.value(3).toString().toStdString();
                 resultPass=query.value(4).toString().toStdString();

                 if(resultUser == username && resultPass == password)
                 {
                      setConnectedAtDb(true);
                      userConnected = User::getUserWithLogin(username);
                      setUserFirstname(resultUsername);
                      return getConnectedAtDb();
                 }
             }
         }
         QMessageBox::information(this, "Informations erronees", "Le nom d'utilisateur et/ou le mot de passe est errone.") ;
    }
    else
    {
        db.close();
    }
    setConnectedAtDb(false);
    return getConnectedAtDb();
}

void MainWindow::on_pushButtonConnect_clicked()
{
    if(getConnectedAtDb()==false)
    {
        connectAt();
    }

     if(getConnectedAtDb())
     {
        if(ftp.gethandle() == NULL)
        {
            wstring host=L"alihome.fr";
            wstring login=L"esgi@alihome.fr";
            wstring pw=L"ProjetESGI2014";

            ftp.connect(host,login,pw);
            ui->pushButtonConnect->setText("Deconnecter");
            string strUser=getUserFirstname();
            wstring wstrUser(strUser.begin(),strUser.end());
            ftp.mkdir(wstrUser);
            ftp.cd(wstrUser);
        }
        else
        {
            ftp.disconnect();
            ui->pushButtonConnect->setText("Connecter");

            ui->lineEditPassword->clear();
            ui->lineEditUsername->clear();
            connectAt();
        }
        hideOrDisplay();
        updateListWidget();
     }
}

void MainWindow::on_pushButtonNewFolder_clicked()
{
   ftp.mkdir(QInputDialog::getText(this,"Folder Name","Nom du dossier").toStdWString());
   updateListWidget();
}



void MainWindow:: removeDir(wstring folder)
{
    string strfolder(folder.begin(),folder.end());
    cout<<"removeDir Function     "<<strfolder<<endl;


    ftp.cd(folder);
    updateListWidget();
    wstring wstrname2=L"";

    for(int i=2;i<ftp.getListFilesFolders().size();i++)
    {
        WIN32_FIND_DATA dirInfo=ftp.getListFilesFolders()[i];
        string strname=wcharToString(dirInfo);
        string fn=strname;
        wstring wstrname(fn.begin(),fn.end());
        wstrname2=wstrname;

        cout<<"current directory: "<<strname<<endl;
        if(dirInfo.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
        {
            removeAllFiles();
            cout<<"foldername: "<<strname<<endl;
            removeDir(folder+L"/"+wstrname);
        }
        else
        {
            cout<<"filename: "<<strname<<endl;
            cout<<"remove file : "<<ftp.remove(wstrname)<<endl;
        }
    }
    ftp.cd(folder+L"/..");
    cout<<"foldername: "<<strfolder<<endl;
    cout<<"remove dir: "<<ftp.rmdir(folder)<<endl;

}

void MainWindow:: removeAllFiles()
{
    updateListWidget();
    for(int i=0;i<ftp.getSizeOfListFiles();i++)
   {
       QListWidgetItem *newItem = new QListWidgetItem;
       wstring item=ftp.getListFiles()[i];
       newItem->setText(QString::fromWCharArray(item.c_str()));
       cout<<"filename: " <<newItem->text().toStdString()<<endl;
       cout<<"remove1111: "<<ftp.remove(newItem->text().toStdWString())<<endl;
   }
    updateListWidget();
}
string MainWindow :: wcharToString(WIN32_FIND_DATA fileInfo)
{
    size_t size = wcslen(fileInfo.cFileName);
    char * buffer = new char [2 * size + 2];
    wcstombs(buffer, fileInfo.cFileName, 2 * size + 2);
    string file(buffer);
    delete [] buffer;

    return file;
}

void MainWindow:: on_pushButtonDelete_clicked()
{


    return;
    for(int i=0;i<ftp.getSizeOfListFolders()-1;i++)
      {
          QListWidgetItem *newItem = new QListWidgetItem;
          wstring item=ftp.getListFolders()[i+1];
          newItem->setText(QString::fromWCharArray(item.c_str()));
          if(newItem->text()==ui->listWidget->currentItem()->text())
          {
              wstring foldername=ui->listWidget->currentItem()->text().toStdWString();

              removeDir(L"/Eric/"+foldername);
              updateListWidget();
              return;
          }
      }
      ftp.remove(ui->listWidget->currentItem()->text().toStdWString());
      updateListWidget();
}

void MainWindow::on_pushButtonUploadFile_clicked()
{
    QString file = QFileDialog::getOpenFileName(this,tr("Choose file"));
    string strFileName=file.toStdString();
    strFileName=strFileName.substr(strFileName.find_last_of("/")+1);
    wstring wstrFileName(strFileName.begin(),strFileName.end());
    ftp.upload(file.toStdWString(),wstrFileName);
    updateListWidget();
}

void MainWindow::on_pushButtonUploadFolder_clicked()
{
    QString folder = QFileDialog::getExistingDirectory(this,tr("Choose folder"));
    if(!folder.isEmpty() || !folder.isNull())
    {
        updateFolder(folder);
        updateListWidget();
    }
    cout<<"FINI"<<endl;
}


void MainWindow::on_pushButtonSuscribe_clicked()
{
    InscriptionWindow inc;
    inc.exec();
}

void MainWindow::on_actionQuitter_triggered()
{
    deleteFile("../ProjectOnline/Test");
    this->close();
}

void MainWindow::on_actionModifier_Donnees_triggered()
{
    ModifierWindow mod(userConnected);
    mod.exec();
}

void MainWindow::on_actionModifier_Password_triggered()
{
    modifierPassword mod(userConnected);
    mod.exec();
}

void MainWindow::on_actionA_Propos_triggered()
{
    QMessageBox::information(this, "A Propos", "Created by Amir, Eric and Adil") ;
}

void MainWindow::on_pushButtonRename_clicked()
{
    wstring selectedFile =ui->listWidget->currentItem()->text().toStdWString();
    selectedFile=selectedFile.substr(selectedFile.find_last_of(L"."));
   // cout<<"extension: "<<selectedFile<<endl;
     ftp.rename(ui->listWidget->currentItem()->text().toStdWString(),QInputDialog::getText(this,"New File Name","Rename").toStdWString()+selectedFile);
     updateListWidget();
}
