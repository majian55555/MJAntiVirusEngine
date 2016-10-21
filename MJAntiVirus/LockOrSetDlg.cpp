// LockOrSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mjantivirus.h"
#include "LockOrSetDlg.h"
#include "SetPasswordDlg.h"
#include "LockDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLockOrSetDlg dialog


CLockOrSetDlg::CLockOrSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLockOrSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLockOrSetDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLockOrSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLockOrSetDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLockOrSetDlg, CDialog)
	//{{AFX_MSG_MAP(CLockOrSetDlg)
	ON_BN_CLICKED(IDC_BTN_SETCODE, OnBtnSetcode)
	ON_BN_CLICKED(IDC_BTN_LOCKCPT, OnBtnLockcpt)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLockOrSetDlg message handlers


void CLockOrSetDlg::OnBtnSetcode() 
{
	// TODO: Add your control notification handler code here
	CSetPasswordDlg setcodedlg;
	setcodedlg.DoModal();
}

void CLockOrSetDlg::OnBtnLockcpt() 
{
	// TODO: Add your control notification handler code here
	CLockDlg lockdlg;
	lockdlg.DoModal();
}
