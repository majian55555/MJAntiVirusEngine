// FolderEncryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mjantivirus.h"
#include "FolderEncryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFolderEncryDlg dialog


CFolderEncryDlg::CFolderEncryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFolderEncryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFolderEncryDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFolderEncryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFolderEncryDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFolderEncryDlg, CDialog)
	//{{AFX_MSG_MAP(CFolderEncryDlg)
	ON_BN_CLICKED(ID_ADD, OnAdd)
	ON_BN_CLICKED(IDC_BTENCRY, OnBtencry)
	ON_BN_CLICKED(IDC_BTUNENCRY, OnBtunencry)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFolderEncryDlg message handlers

void CFolderEncryDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	BROWSEINFO bi;   
	char buffer[MAX_PATH];   
	ZeroMemory(buffer,MAX_PATH);   
	bi.hwndOwner=GetSafeHwnd();   
	bi.pidlRoot=NULL;   
	bi.pszDisplayName=buffer;   
	bi.lpszTitle="选择一个文件夹";   
	bi.ulFlags=BIF_EDITBOX;   
	bi.lpfn=NULL;   
	bi.lParam=0;   
	bi.iImage=0; 
	LPITEMIDLIST pList=NULL;   
	if((pList=SHBrowseForFolder(&bi))!=NULL)   
	{
		char path[MAX_PATH];   
		ZeroMemory(path,MAX_PATH);   
		SHGetPathFromIDList(pList,path); 
		GetDlgItem(IDC_EDDIR)->SetWindowText(path);
	}
}

void CFolderEncryDlg::OnBtencry() 
{
	// TODO: Add your control notification handler code here
	CString strpath,despath;
	GetDlgItem(IDC_EDDIR)->GetWindowText(strpath);
	if(strpath!="")
	{
		despath.Format("%s.{d6277990-4c6a-11cf-8d87-00aa0060f5bf}",strpath);
		MessageBox("加密成功！！！");
		GetDlgItem(IDC_EDDIR)->SetWindowText("");
	}
	else
	{
		MessageBox("请选择文件夹！！！");
	}
}

void CFolderEncryDlg::OnBtunencry() 
{
	// TODO: Add your control notification handler code here
	CString strpath,despath;
	GetDlgItem(IDC_EDDIR)->GetWindowText(strpath);
	if(strpath!="")
	{
		int pos=strpath.Find(".");
		despath=strpath.Left(pos);
		if(despath.IsEmpty())
		{
			MessageBox("解密失败！！！");
			return;
		}
		::rename(strpath,despath);
		MessageBox("解密成功！！！");
		GetDlgItem(IDC_EDDIR)->SetWindowText("");
	}
	else
	{
		MessageBox("请选择文件夹！！！");
	}
}

BOOL CFolderEncryDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	GetDlgItem(ID_ADD)->SetFocus();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
