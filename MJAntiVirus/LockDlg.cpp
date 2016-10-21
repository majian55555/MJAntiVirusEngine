// LockDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mjantivirus.h"
#include "LockDlg.h"
#include "SetPasswordDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLockDlg dialog
_declspec(dllimport) void SetHook(void);
_declspec(dllimport) void UnloadHook(void);
CLockDlg::CLockDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLockDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLockDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLockDlg)
	DDX_Control(pDX, IDC_LOCK_EDIT1, m_password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLockDlg, CDialog)
	//{{AFX_MSG_MAP(CLockDlg)
	ON_BN_CLICKED(IDC_LOCK_BTN1, OnLockBtn1)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_LOCK_BTN_SCREEN, OnLockBtnScreen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLockDlg message handlers

BOOL CLockDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CFile codefile;
	if(codefile.Open("Setting\\Password.dat",CFile::modeRead | CFile::shareDenyNone))
	{
		codefile.Close();
		//加入键盘钩子和鼠标限制
		CRect rc;
		this->GetWindowRect(rc);
		rc.left = rc.left+10;
		rc.top = rc.top+30;
		rc.right = rc.right-10;
		rc.bottom = rc.bottom-10;
		::ClipCursor(&rc); //::GetCurrentThreadId()
		SetHook();
		//g_hookKeyBoard=::SetWindowsHookEx(WH_KEYBOARD,KeyHookProc,(HINSTANCE)AfxGetApp()->m_hInstance,NULL);
	}
	else
	{
		for(;;)
		{
			CSetPasswordDlg setcodedlg;
			int ret=-1;
			ret=setcodedlg.DoModal();
			if(ret==1)
				return TRUE;
			else
				MessageBox("请设置密码！！！");
		}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CLockDlg::OnLockBtn1() 
{
	// TODO: Add your control notification handler code here
	CFile codefile;
	if(codefile.Open("Setting\\Password.dat",CFile::modeRead | CFile::shareDenyNone))
	{
		//读取密码
		codefile.SeekToBegin();
		CArchive ar(&codefile,CArchive::load);
		CString password;
		ar>>password;
		ar.Close();
		codefile.Close();
		CString gettxt;
		this->m_password.GetWindowText(gettxt);
		if(gettxt==password)
		{//取消钩子和鼠标限制
			::ClipCursor(NULL);
			UnloadHook();
			this->EndDialog(1);
		}
		else
		{
			MessageBox("密码不正确！！！");
			this->m_password.SetWindowText("");
			this->m_password.SetFocus();
		}
	}
	else
	{
		MessageBox("打开Setting\\Password.dat文件出错！！");
	}
}

void CLockDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rc;
	this->GetWindowRect(rc);
	rc.left = rc.left+10;
	rc.top = rc.top+30;
	rc.right = rc.right-10;
	rc.bottom = rc.bottom-10;
	::ClipCursor(&rc); //::GetCurrentThreadId()
	CDialog::OnMouseMove(nFlags, point);
}

void CLockDlg::OnLockBtnScreen() 
{
	// TODO: Add your control notification handler code here
	this->m_screenprotectdlg.DestroyWindow();
	this->m_screenprotectdlg.Create(IDD_DLG_SCREENPROTECT,this);
	this->m_screenprotectdlg.ShowWindow(SW_SHOW);
}
