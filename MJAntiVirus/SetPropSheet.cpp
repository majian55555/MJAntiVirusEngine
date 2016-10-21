// SetPropSheet.cpp : implementation file
//

#include "stdafx.h"
#include "MJAntiVirus.h"
#include "SetPropSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetPropSheet

IMPLEMENT_DYNAMIC(CSetPropSheet, CPropertySheet)

CSetPropSheet::CSetPropSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_setprop1);
	AddPage(&m_setprop2);
	AddPage(&m_setprop3);
}

CSetPropSheet::CSetPropSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_setprop1);
	AddPage(&m_setprop2);
	AddPage(&m_setprop3);
}

CSetPropSheet::~CSetPropSheet()
{
	delete this;
}


BEGIN_MESSAGE_MAP(CSetPropSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CSetPropSheet)
	ON_BN_CLICKED(IDC_SETDLG_BTN_OK, OnBtn_Ok)
	ON_BN_CLICKED(IDC_SETDLG_BTN_CANCEL, OnBtn_Cancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetPropSheet message handlers

void CSetPropSheet::OnBtn_Ok()
{
	CFile settingfile;
 	if(settingfile.Open("Setting\\Setting.dat",CFile::modeCreate | CFile::modeWrite))
 	{
		settingfile.SeekToBegin();
 		CArchive settingarc(&settingfile,CArchive::store);
 		this->Serialize(settingarc);
 		settingarc.Close();
 		settingfile.Close();
 	}
	HKEY sub;
	char bufname[200];
	::GetModuleFileName(NULL,bufname,200);
	CString str;
	str.Format("%s",bufname);
	CString skey="Software\\Microsoft\\Windows\\CurrentVersion\\Run";
	::RegCreateKey(HKEY_LOCAL_MACHINE,skey,&sub);	
	this->SetActivePage(&m_setprop1);
	if(this->m_setprop1.m_prop1_check1.GetCheck()==1)
	{
		::RegSetValueEx(sub,"StartAutoRun",NULL,REG_SZ,(const BYTE*)str.GetBuffer(0),str.GetLength());
	}
	else
	{
		::RegDeleteValue(sub,"StartAutoRun");
	}
	if(this->DestroyWindow()!=TRUE)
	{
		AfxMessageBox("关闭窗口失败！！！");
	}
}
void CSetPropSheet::OnBtn_Cancel()
{
	if(this->DestroyWindow()!=TRUE)
	{
		AfxMessageBox("关闭窗口失败！！！");
	}
}
BOOL CSetPropSheet::OnInitDialog() 
{
	BOOL bResult = CPropertySheet::OnInitDialog();
	
	// TODO: Add your specialized code here
	CRect* curCRect=new CRect(0,0,0,0);
	this->GetWindowRect(curCRect);
	CPoint topleft;
	topleft=curCRect->TopLeft();
	this->SetWindowPos(this,topleft.x,topleft.y,curCRect->Width(),curCRect->Height()+35,SWP_NOZORDER);
	this->m_btn_ok.Create("确定",WS_CHILD|WS_VISIBLE,CRect(70,270,140,300),this,IDC_SETDLG_BTN_OK);
	this->m_btn_ok.ShowWindow(SW_SHOW);
	this->m_btn_cancel.Create("取消",WS_CHILD|WS_VISIBLE,CRect(215,270,285,300),this,IDC_SETDLG_BTN_CANCEL);
	this->m_btn_cancel.ShowWindow(SW_SHOW);
	CFile settingfile;
 	if(settingfile.Open("Setting\\Setting.dat",CFile::modeRead))
 	{
		settingfile.SeekToBegin();
 		CArchive settingarc(&settingfile,CArchive::load);
 		this->Serialize(settingarc);
 		settingarc.Close();
 		settingfile.Close();
 	}
	if(!this->m_setprop1.m_prop1_check1.GetCheck())
	{
		this->m_setprop1.m_prop1_check2.EnableWindow(FALSE);
		this->m_setprop1.m_prop1_check3.EnableWindow(FALSE);
		this->m_setprop1.m_prop1_check4.EnableWindow(FALSE);
		this->m_setprop1.m_prop1_check5.EnableWindow(FALSE);
	}
	return bResult;
}

void CSetPropSheet::Serialize(CArchive& ar) 
{
	if (ar.IsStoring())
	{	// storing code
		CPropertyPage* oldpage=this->GetActivePage();
		this->m_setprop1.Serialize(ar);
		this->SetActivePage(&m_setprop2);
		this->m_setprop2.Serialize(ar);
		this->SetActivePage(&m_setprop3);
		this->m_setprop3.Serialize(ar);
		this->SetActivePage(oldpage);
	}
	else
	{	// loading code
		CPropertyPage* oldpage=this->GetActivePage();
		this->m_setprop1.Serialize(ar);
		this->SetActivePage(&m_setprop2);
		this->m_setprop2.Serialize(ar);
		this->SetActivePage(&m_setprop3);
		this->m_setprop3.Serialize(ar);
		this->SetActivePage(oldpage);
	}
}
