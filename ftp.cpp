#include "ftp.h"

#include <wininet.h>
#include <strsafe.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#pragma comment(lib, "Wininet")
#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "user32.lib")

#define  FTP_FUNCTIONS_BUFFER_SIZE          MAX_PATH+8
#define INTERNET_FLAG_NEED_FILE         0x00000010


using namespace std;


FTP::FTP(){
    m_hInternet = InternetOpen(NULL,INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    m_connected = false;
}

FTP::~FTP()
{
    if(m_connected)
    {
        InternetCloseHandle(m_hFtpSession);
        InternetCloseHandle(m_hInternet);
    }
}

bool FTP::connect(TSTR lpszServerName, TSTR lpszUser, TSTR lpszPassword)
{
    m_hFtpSession = InternetConnect(m_hInternet,
                                        (LPTSTR)lpszServerName.c_str(),
                                        INTERNET_DEFAULT_FTP_PORT,
                                        (LPTSTR)lpszUser.c_str(),
                                        (LPTSTR)lpszPassword.c_str(),
                                        INTERNET_SERVICE_FTP,
                                        0,
                                        0);
    if (!m_hFtpSession)
            return false;

    return (m_connected = true);
}

bool FTP::disconnect()
{
    if(m_connected)
    {
        InternetCloseHandle(m_hFtpSession);
        InternetCloseHandle(m_hInternet);
        m_connected = false;
    }

    return m_connected;
}

bool FTP::upload(TSTR lpszLocation, TSTR lpszRemFile)
{
    return !m_connected ? false : FtpPutFile(m_hFtpSession,
                                             (LPTSTR)lpszLocation.c_str(),
                                             lpszRemFile.empty() ?
                                                (LPTSTR)lpszLocation.c_str()
                                                : (LPTSTR)lpszRemFile.c_str(),
                                             FTP_TRANSFER_TYPE_BINARY,
                                             0) == TRUE;
}

bool FTP::download(TSTR lpszLocation, TSTR lpszRemFile)
{
    return !m_connected ?
        false
        : FtpGetFile(m_hFtpSession,
                     (LPTSTR)lpszLocation.c_str(),
                     lpszRemFile.empty() ?
                        (LPTSTR)lpszLocation.c_str()
                        : (LPTSTR)lpszRemFile.c_str(),
                     0,
                     0,
                     FTP_TRANSFER_TYPE_BINARY,
                     0) == TRUE;
}

bool FTP::mkdir(TSTR lpszDirectory)
{
    return !m_connected ? false : FtpCreateDirectory(m_hFtpSession,(LPTSTR)lpszDirectory.c_str());
}

bool FTP::cd(TSTR lpszDirectory)
{
    return !m_connected ?
        false
        : FtpSetCurrentDirectory(m_hFtpSession,
                                 (LPTSTR)lpszDirectory.c_str()) == TRUE;
}

bool FTP::remove(TSTR lpszFileName)
{
    return !m_connected ? false : FtpDeleteFile(m_hFtpSession,(LPTSTR)lpszFileName.c_str()) == TRUE;
}

bool FTP::rename(TSTR lpszOldFileName, TSTR lpszNewFileName)
{
    return !m_connected ?
        false
        : FtpRenameFile(m_hFtpSession,
                        (LPTSTR)lpszOldFileName.c_str(),
                        (LPTSTR)lpszNewFileName.c_str()) == TRUE;
}

bool FTP::rmdir(TSTR lpszDirectory)
{
    return FtpRemoveDirectory(m_hFtpSession,(LPTSTR)lpszDirectory.c_str());
}

HINTERNET FTP::gethandle()
{
    return m_connected ? m_hFtpSession : NULL;
}

TSTR FTP::getcd()
{
    LPTSTR lpszCurrentDirectory = (LPTSTR)GlobalAlloc(GPTR, MAX_PATH + 1);
    DWORD lpdwCurrentDirectory = MAX_PATH;
    TSTR strCurrentDirectory;

    if (!FtpGetCurrentDirectory(m_hFtpSession,lpszCurrentDirectory, &lpdwCurrentDirectory))
    {
        //strCurrentDirectory = _T("ERROR-1");
        return strCurrentDirectory;
    }

    int len = (int)lpdwCurrentDirectory;
    for (int i = 0; i < len; i++)
    {
        strCurrentDirectory += lpszCurrentDirectory[i];
    }
    GlobalFree((HANDLE)lpszCurrentDirectory);

    return strCurrentDirectory;
}

LONGLONG FTP::getfilesize(TSTR lpszFileName)
{
    if(!m_connected)
        return INVALID_FILE;

    HINTERNET fHandle = FtpOpenFile(m_hFtpSession,
                                    (LPTSTR)lpszFileName.c_str(),
                                    GENERIC_READ,
                                    INTERNET_FLAG_TRANSFER_BINARY,
                                    0);
    LARGE_INTEGER llFileSize;
    DWORD dwFileSizeLow = INVALID_FILE;
    DWORD dwFileSizeHigh = INVALID_FILE;

    if(fHandle)
    {
        dwFileSizeLow = FtpGetFileSize(fHandle,&dwFileSizeHigh);
        InternetCloseHandle(fHandle);
    }

    llFileSize.LowPart = dwFileSizeLow;
    llFileSize.HighPart = dwFileSizeHigh;

    return llFileSize.QuadPart;
}

bool FTP::command(TSTR lpszCommand)
{
    return !m_connected ?
        false
        : FtpCommand(m_hFtpSession,
                     FALSE,
                     FTP_TRANSFER_TYPE_BINARY,
                     (LPTSTR)lpszCommand.c_str(),
                     0,
                     NULL) == TRUE;
}

bool FTP :: DisplayFtpDir(HINTERNET hConnection,DWORD dwFindFlags, int nListBoxId)
{
    WIN32_FIND_DATA dirInfo;
  HINTERNET       hFind;
  DWORD           dwError;
  BOOL            retVal = FALSE;
  TCHAR           szMsgBuffer[FTP_FUNCTIONS_BUFFER_SIZE];
  TCHAR           szFName[FTP_FUNCTIONS_BUFFER_SIZE];


  hFind = FtpFindFirstFile(hConnection, TEXT( "*.*" ), &dirInfo, dwFindFlags, 0);
  if ( hFind == NULL )
  {
    dwError = GetLastError();
    if(dwError == ERROR_NO_MORE_FILES)
    {
      StringCchCopy(szMsgBuffer, FTP_FUNCTIONS_BUFFER_SIZE,TEXT("No files found at FTP location specified."));
      retVal = TRUE;
      goto DisplayDirError_1;
    }
    StringCchCopy( szMsgBuffer, FTP_FUNCTIONS_BUFFER_SIZE, TEXT("FtpFindFirstFile failed."));
    goto DisplayDirError_1;
  }

  do
  {
    if(FAILED(StringCchCopy(szFName, FTP_FUNCTIONS_BUFFER_SIZE,dirInfo.cFileName)) ||
        ((dirInfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
        (FAILED(StringCchCat(szFName, FTP_FUNCTIONS_BUFFER_SIZE,TEXT(" <DIR> ")))) ))
    {

      StringCchCopy(szMsgBuffer, FTP_FUNCTIONS_BUFFER_SIZE, TEXT("Failed to copy a file or directory name."));
      retVal = FALSE;
      goto DisplayDirError_2;
    }
    wstring name = dirInfo.cFileName;

    listFilesFolders.push_back(dirInfo);

    if(dirInfo.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
       listFolders.push_back(name);
    else
        listFiles.push_back(name);
  }
  while(InternetFindNextFile(hFind, (LPVOID) &dirInfo));

  if((dwError = GetLastError()) == ERROR_NO_MORE_FILES)
  {
    InternetCloseHandle(hFind);
    return TRUE;
  }
  StringCchCopy(szMsgBuffer, FTP_FUNCTIONS_BUFFER_SIZE, TEXT( "FtpFindNextFile failed."));

DisplayDirError_2:
  InternetCloseHandle(hFind);
DisplayDirError_1:

  return retVal;
}

HINTERNET FTP :: getHInternet()
{
    return m_hInternet;
}

HINTERNET FTP :: getHFtpSession()
{
    return m_hFtpSession;
}

vector<wstring> FTP :: getListFolders()
{
    return listFolders;
}

vector<wstring> FTP::getListFiles()
{
    return listFiles;
}

vector<WIN32_FIND_DATA> FTP::getListFilesFolders()
{
    return listFilesFolders;
}

int FTP :: getSizeOfListFolders()
{
    return listFolders.size();
}

int FTP :: getSizeOfListFiles()
{
    return listFiles.size();
}




bool FTP :: downloadFolder(HINTERNET hConnection,DWORD dwFindFlags,TSTR pathFtp,TSTR pathLocal)
{
     string folder( pathFtp.begin(), pathFtp.end());
     folder=folder.substr(folder.find_last_of("/"));
     cout<<"FOLDER: "<<folder<<endl;
     wstring wstrpathFtp( pathFtp.begin(), pathFtp.end());
     cd(wstrpathFtp);

/*
    cout<<"TAILLE "<<folder.length()<<endl;
    if(folder.length()<=2)
        folder="/FTP";
*/

    string pathLocal2(pathLocal.begin(), pathLocal.end());
    string cheminLocal = pathLocal2+folder;
    cout<<"chemin local: "<<cheminLocal<< " path lcoal: "<<pathLocal2<<endl;


    if(CreateDirectory(s2ws(cheminLocal).c_str(), NULL))
    {
        pathLocal2=cheminLocal;
        cout<<"path local: "<<pathLocal2<<endl;
    }

    WIN32_FIND_DATA dirInfo;
    HINTERNET       hFind;
    DWORD           dwError;
    BOOL            retVal = FALSE;
    TCHAR           szMsgBuffer[FTP_FUNCTIONS_BUFFER_SIZE];
    TCHAR           szFName[FTP_FUNCTIONS_BUFFER_SIZE];

      hFind = FtpFindFirstFile(hConnection, TEXT("*.*"),&dirInfo, dwFindFlags, 1);
      if (hFind == NULL)
      {
        dwError = GetLastError();
        if(dwError == ERROR_NO_MORE_FILES)
        {
          StringCchCopy(szMsgBuffer, FTP_FUNCTIONS_BUFFER_SIZE,TEXT( "No files found at FTP location specified."));
          retVal = TRUE;
          goto DisplayDirError_1;
        }
        StringCchCopy(szMsgBuffer, FTP_FUNCTIONS_BUFFER_SIZE,TEXT( "FtpFindFirstFile failed."));
        goto DisplayDirError_1;
      }

      do
      {
        if(FAILED(StringCchCopy(szFName, FTP_FUNCTIONS_BUFFER_SIZE,dirInfo.cFileName)) ||
            ((dirInfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
            (FAILED(StringCchCat(szFName, FTP_FUNCTIONS_BUFFER_SIZE, TEXT(" <DIR> "))))))
        {
          StringCchCopy(szMsgBuffer, FTP_FUNCTIONS_BUFFER_SIZE, TEXT("Failed to copy a file or directory name."));
          retVal = FALSE;
          goto DisplayDirError_2;
        }

        string strFileName=wcharToString(dirInfo);
        string fn=strFileName;
        wstring wstrFilename(fn.begin(),fn.end());
        cout<<"filename: "<<strFileName<<endl;
        string strPathLocal = cheminLocal + "/" + strFileName;
        wstring wstrPathLocal(strPathLocal.begin(),strPathLocal.end());
        cout << "FULL PATH: " <<strPathLocal<<endl;

        cout <<strFileName<<endl;
        if(dirInfo.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
        {
             if(CreateDirectory(s2ws(strPathLocal).c_str(),NULL))
             {
                cout<<"DOSSIER CREER"<<endl;
                cd(dirInfo.cFileName);
                InternetCloseHandle(hFind);
                wstring cheminLocal2(cheminLocal.begin(), cheminLocal.end());
                downloadFolder(hConnection, dwFindFlags, getcd(), cheminLocal2);
             }
        }
        else
        {
            if(strFileName == "NF.xls" || strFileName == "exemple.xml" || strFileName == "LOGO-ESGI.jpg")
            {
                cout<<"DOWNLOAD FILE "<<strFileName<<" AT "<<strPathLocal<<endl;
                if(strFileName == "NF.xls")
                    cout<<"DDDDDDDL: "<<download(wstrFilename,QDir::homePath().toStdWString()+L"/Desktop/FTP/test/NF.xls")<<endl;
                if(strFileName == "exemple.xml")
                    cout<<"DDDDDDDL: "<<download(wstrFilename,QDir::homePath().toStdWString()+L"/Desktop/FTP/test/exemple.xml")<<endl;
                if(strFileName == "LOGO-ESGI.jpg")
                    cout<<"DDDDDDDL: "<<download(wstrFilename,QDir::homePath().toStdWString()+L"/Desktop/FTP/test1/LOGO-ESGI.jpg")<<endl;
            }
            else
            {
                cout<<"DOWNLOAD FILE "<<strFileName<<" AT "<<strPathLocal<<endl;
                cout<<"DL: "<<download(dirInfo.cFileName,wstrPathLocal)<<endl;
            }
        }

      }
      while(InternetFindNextFile(hFind, (LPVOID) &dirInfo));

      if((dwError = GetLastError()) == ERROR_NO_MORE_FILES)
      {
        InternetCloseHandle(hFind);
        return TRUE;
      }
      StringCchCopy(szMsgBuffer, FTP_FUNCTIONS_BUFFER_SIZE,TEXT("FtpFindNextFile failed."));

    DisplayDirError_2:
      InternetCloseHandle(hFind);
    DisplayDirError_1:

  return- retVal;

}













string FTP :: wcharToString(WIN32_FIND_DATA fileInfo)
{
    size_t size = wcslen(fileInfo.cFileName);
    char * buffer = new char [2 * size + 2];
    wcstombs(buffer, fileInfo.cFileName, 2 * size + 2);
    string file(buffer);
    delete [] buffer;

    return file;
}

wstring FTP::s2ws(const string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}
HINTERNET FTP::openFile(HINTERNET hConnect, LPCTSTR lpszFileName, DWORD dwAccess, DWORD dwFlags,DWORD_PTR dwContext)
{
    return FtpOpenFileW(hConnect,lpszFileName,dwAccess,dwFlags,dwContext);
}


void FTP :: clearList()
{
    listFolders.clear();
    listFiles.clear();
    listFilesFolders.clear();
}

