// DlgComputerInfo.cpp : implementation file
//

#include "stdafx.h"
#include "mjantivirus.h"
#include "DlgComputerInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgComputerInfo dialog


CDlgComputerInfo::CDlgComputerInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgComputerInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgComputerInfo)
	//}}AFX_DATA_INIT
}


void CDlgComputerInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgComputerInfo)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgComputerInfo, CDialog)
	//{{AFX_MSG_MAP(CDlgComputerInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgComputerInfo message handlers
//_declspec(dllimport) ComputerInfo* GetComputerInfo(void);
BOOL CDlgComputerInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	HINSTANCE hInst=LoadLibrary("dll//AntiVirusDLL2.dll");
	if(hInst==NULL)
	{
		AfxMessageBox("打开DLL失败！");
		return FALSE;
	}
	typedef ComputerInfo* (*GetComputerInfo)(void);
	GetComputerInfo GetCptInfoProcAdd=(GetComputerInfo)GetProcAddress(hInst,"GetComputerInfo");
	if(!GetCptInfoProcAdd)
	{
		AfxMessageBox("获取DLL函数地址失败！");
		return FALSE;
	}
	ComputerInfo* cptinfo=GetCptInfoProcAdd();
	FreeLibrary(hInst);
	//ComputerInfo* cptinfo=GetComputerInfo();
	((CEdit*)CWnd::GetDlgItem(IDC_EDIT_CPTINFO1))->SetWindowText(cptinfo->computername);
	((CEdit*)CWnd::GetDlgItem(IDC_EDIT_CPTINFO2))->SetWindowText(cptinfo->sysplatform);
	((CEdit*)CWnd::GetDlgItem(IDC_EDIT_CPTINFO3))->SetWindowText(cptinfo->cpuspeed);
	((CEdit*)CWnd::GetDlgItem(IDC_EDIT_CPTINFO4))->SetWindowText(cptinfo->totalmem);
	((CEdit*)CWnd::GetDlgItem(IDC_EDIT_CPTINFO5))->SetWindowText(cptinfo->aviliblemen);
	((CEdit*)CWnd::GetDlgItem(IDC_EDIT_CPTINFO6))->SetWindowText(cptinfo->aviliblemempersent);
	((CEdit*)CWnd::GetDlgItem(IDC_EDIT_CPTINFO7))->SetWindowText(cptinfo->ipaddress);
	((CEdit*)CWnd::GetDlgItem(IDC_EDIT_CPTINFO8))->SetWindowText(cptinfo->macaddress);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
