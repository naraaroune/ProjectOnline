#ifndef _FTP_H_
#define _FTP_H_


#include <Windows.h>
#include <WinInet.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <vector>
#pragma comment (lib, "wininet.lib")
using namespace std;


/* UNICODE SUPPORT */
#if !defined(TSTR)
#if defined(UNICODE) || defined(_UNICODE_)
#define TSTR std::wstring
#else
#define TSTR std::string
#endif
#endif


#define INVALID_FILE -1


using namespace std;

class FTP
{
public:
FTP(void);
~FTP(void);


HINTERNET openFile(HINTERNET hConnect, LPCTSTR lpszFileName, DWORD dwAccess, DWORD dwFlags,DWORD_PTR dwContext);
bool connect(TSTR lpszServerName, TSTR lpszUser, TSTR lpszPassword);
bool disconnect(void);


bool upload(TSTR lpszLocation, TSTR lpszRemFile);

bool download(TSTR lpszLocation, TSTR lpszRemName);
bool downloadFolder(HINTERNET hConnection,DWORD dwFindFlags,TSTR pathFtp,TSTR pathLocal);
bool removeFolder(HINTERNET hConnection,DWORD dwFindFlags,TSTR pathFtp,TSTR pathLocal);

bool cd(TSTR lpszDirectory);
bool mkdir(TSTR lpszDirectory);
bool rmdir(TSTR lpszDirectory);
TSTR getcd(void);

bool remove(TSTR lpszFileName);
bool rename(TSTR lpszOldFileName, TSTR lpszNewFileName);
LONGLONG getfilesize(TSTR lpszFileName);

HINTERNET gethandle(void);
bool command(TSTR lpszCommand);
bool DisplayFtpDir(HINTERNET hConnection,DWORD dwFindFlags, int nListBoxId);
HINTERNET getHInternet();
HINTERNET getHFtpSession();
vector<wstring> getListFolders();
vector<wstring> getListFiles();
vector<WIN32_FIND_DATA> getListFilesFolders();
int getSizeOfListFolders();
int getSizeOfListFiles();
void clearList();
string wcharToString(WIN32_FIND_DATA file);
wstring s2ws(const std::string& s);

private:
bool m_connected;
HINTERNET m_hInternet;
HINTERNET m_hFtpSession;

vector<wstring>listFolders;
vector<wstring>listFiles;
vector<WIN32_FIND_DATA>listFilesFolders;
};



#endif
