// SetPasswordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mjantivirus.h"
#include "SetPasswordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetPasswordDlg dialog


CSetPasswordDlg::CSetPasswordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetPasswordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetPasswordDlg)
	//}}AFX_DATA_INIT
}


void CSetPasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetPasswordDlg)
	DDX_Control(pDX, IDC_EDIT1, m_edt_password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetPasswordDlg, CDialog)
	//{{AFX_MSG_MAP(CSetPasswordDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetPasswordDlg message handlers

void CSetPasswordDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CFile setcodefile;
	if(setcodefile.Open("Setting\\Password.dat",CFile::modeCreate | CFile::modeWrite))
	{
		setcodefile.SeekToBegin();
		CArchive ar(&setcodefile,CArchive::store);
		CString getpassword;
		this->m_edt_password.GetWindowText(getpassword);
		getpassword.TrimLeft();
		getpassword.TrimRight();
		if(getpassword=="")
		{
			MessageBox("请设置密码！！！");
			this->m_edt_password.SetFocus();
			return;
		}
		ar<<getpassword;
		ar.Close();
		setcodefile.Close();
	}
	else
	{
		MessageBox("打开Setting\\Password.dat文件出错！！");
	}
	this->EndDialog(1);
}

