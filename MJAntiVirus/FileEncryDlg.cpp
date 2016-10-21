// FileEncryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mjantivirus.h"
#include "FileEncryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileEncryDlg dialog


CFileEncryDlg::CFileEncryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileEncryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileEncryDlg)
	//}}AFX_DATA_INIT
}


void CFileEncryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileEncryDlg)
	DDX_Control(pDX, IDC_FILEPATH, m_filepath);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFileEncryDlg, CDialog)
	//{{AFX_MSG_MAP(CFileEncryDlg)
	ON_BN_CLICKED(IDC_BTOPEN, OnBtopen)
	ON_BN_CLICKED(IDC_BTENCRY, OnBtencry)
	ON_BN_CLICKED(IDC_BTUNENCRY, OnBtunencry)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileEncryDlg message handlers

void CFileEncryDlg::OnBtopen() 
{
	// TODO: Add your control notification handler code here
	CFileDialog log(TRUE,"文件",NULL,OFN_HIDEREADONLY,"FILE(*.txt)|*.txt||",NULL);
	if(log.DoModal()==IDOK)
	{
		CString tmp,str,path;
		path=log.GetPathName();
		strpathtemp=log.GetFileName();
		int pos=path.Find(strpathtemp);
		strpathtemp=path.Left(pos);
		CStdioFile file;
		try
			{
			int i=file.Open(path,CFile::modeRead);
			if(i==0)
				return;
			}
		catch(CFileException *e)
			{
				TCHAR szBuf[256]; 
				e->GetErrorMessage(szBuf,256,NULL);
				MessageBox(szBuf,_T("Warning"));
				e->Delete();
			}
		while(1)
		{
			DWORD i=file.ReadString(str);
			if(i==0)
				break;
			tmp+=str;
			tmp+="\r\n";
		}
		GetDlgItem(IDC_EDBODY)->SetWindowText(tmp);
		m_filepath.SetWindowText(path);
	}
}

void CFileEncryDlg::OnBtencry() 
{
	// TODO: Add your control notification handler code here
	CString path,desname;
	m_filepath.GetWindowText(path);
	if(path.IsEmpty())
		return;
	desname.Format("%smingrisofttemp.txt",strpathtemp);
	HANDLE handle=::CreateFile(desname,GENERIC_WRITE,FILE_SHARE_WRITE,0,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,NULL);
	if(handle)
		::CloseHandle(handle);
	CFile readfile,writefile;
	int i=readfile.Open(path,CFile::modeRead);
	writefile.Open(desname,CFile::modeCreate|CFile::modeReadWrite);
	if(i==0)
		return;
	char buf[128];
	char desbuf[128];
	while(1)
	{
		ZeroMemory(buf,128);
		ZeroMemory(desbuf,128);
		DWORD i=readfile.Read(buf,128);
		for(DWORD p=0;p<i;p+=1)
		{
			char m=buf[p];
			desbuf[p]=m^2;
		}
		writefile.Write(desbuf,i);
		if(i==0)
			break;
	}
	readfile.Close();
	writefile.Close();
	::DeleteFile(path);
	::rename(desname,path);
	AfxMessageBox("加密完成");
//显示加密后的TXT文件
	CString tmp,str;
	CStdioFile file;
		try
			{
			int i=file.Open(path,CFile::modeRead);
			if(i==0)
				return;
			}
		catch(CFileException *e)
			{
				TCHAR szBuf[256]; 
				e->GetErrorMessage(szBuf,256,NULL);
				MessageBox(szBuf,_T("Warning"));
				e->Delete();
			}
	while(1)
		{
			DWORD i=file.ReadString(str);
			if(i==0)
				break;
			tmp+=str;
			tmp+="\r\n";
		}
		GetDlgItem(IDC_EDBODY)->SetWindowText(tmp);
		m_filepath.SetWindowText(path);
}

void CFileEncryDlg::OnBtunencry() 
{
	// TODO: Add your control notification handler code here
	CString path,desname;
	m_filepath.GetWindowText(path);
	if(path.IsEmpty())
		return;
	desname.Format("%smingrisofttemp.txt",strpathtemp);
	HANDLE handle=::CreateFile(desname,GENERIC_WRITE,FILE_SHARE_WRITE,0,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,NULL);
	if(handle)
		::CloseHandle(handle);
	CFile readfile,writefile;
	int i=readfile.Open(path,CFile::modeRead);
	writefile.Open(desname,CFile::modeCreate|CFile::modeReadWrite);
	if(i==0)
		return;
	char buf[128];
	char desbuf[128];
	while(1)
	{
		ZeroMemory(buf,128);
		ZeroMemory(desbuf,128);
		DWORD i=readfile.Read(buf,128);
		for(DWORD p=0;p<i;p+=1)
		{
			char m=buf[p];
			desbuf[p]=m^2;
		}
		writefile.Write(desbuf,i);
		if(i==0)
			break;
	}
	readfile.Close();
	writefile.Close();
	::DeleteFile(path);
	::rename(desname,path);
	AfxMessageBox("解密完成");
//显示解密后的TXT文件
	CString tmp,str;
	CStdioFile file;
		try
			{
			int i=file.Open(path,CFile::modeRead);
			if(i==0)
				return;
			}
		catch(CFileException *e)
			{
				TCHAR szBuf[256]; 
				e->GetErrorMessage(szBuf,256,NULL);
				MessageBox(szBuf,_T("Warning"));
				e->Delete();
			}
	while(1)
		{
			DWORD i=file.ReadString(str);
			if(i==0)
				break;
			tmp+=str;
			tmp+="\r\n";
		}
		GetDlgItem(IDC_EDBODY)->SetWindowText(tmp);
		m_filepath.SetWindowText(path);
}

BOOL CFileEncryDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	GetDlgItem(IDC_BTOPEN)->SetFocus();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
