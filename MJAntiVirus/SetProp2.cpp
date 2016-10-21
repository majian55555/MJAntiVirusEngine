// SetProp2.cpp : implementation file
//

#include "stdafx.h"
#include "mjantivirus.h"
#include "SetProp2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetProp2 property page

IMPLEMENT_DYNCREATE(CSetProp2, CPropertyPage)

CSetProp2::CSetProp2() : CPropertyPage(CSetProp2::IDD)
{
	//{{AFX_DATA_INIT(CSetProp2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CSetProp2::~CSetProp2()
{
}

void CSetProp2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetProp2)
	DDX_Control(pDX, IDC_PROP2_CHECK6, m_prop2_check6);
	DDX_Control(pDX, IDC_PROP2_CHECK5, m_prop2_check5);
	DDX_Control(pDX, IDC_PROP2_CHECK4, m_prop2_check4);
	DDX_Control(pDX, IDC_PROP2_CHECK3, m_prop2_check3);
	DDX_Control(pDX, IDC_PROP2_CHECK2, m_prop2_check2);
	DDX_Control(pDX, IDC_PROP2_CHECK1, m_prop2_check1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetProp2, CPropertyPage)
	//{{AFX_MSG_MAP(CSetProp2)
	ON_BN_CLICKED(IDC_PROP2_CHECK5, OnProp2Check5)
	ON_BN_CLICKED(IDC_PROP2_CHECK6, OnProp2Check6)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetProp2 message handlers

void CSetProp2::Serialize(CArchive& ar) 
{
	if (ar.IsStoring())
	{	// storing code
		ar<<this->m_prop2_check1.GetCheck()<<this->m_prop2_check2.GetCheck()
		  <<this->m_prop2_check3.GetCheck()<<this->m_prop2_check4.GetCheck()
		  <<this->m_prop2_check5.GetCheck()<<this->m_prop2_check6.GetCheck();
	}
	else
	{	// loading code
		BOOL setting;
		ar>>setting;
		this->m_prop2_check1.SetCheck(setting);
		ar>>setting;
		this->m_prop2_check2.SetCheck(setting);
		ar>>setting;
		this->m_prop2_check3.SetCheck(setting);
		ar>>setting;
		this->m_prop2_check4.SetCheck(setting);
		ar>>setting;
		this->m_prop2_check5.SetCheck(setting);
		ar>>setting;
		this->m_prop2_check6.SetCheck(setting);
		if(this->m_prop2_check5.GetCheck())
		{
			this->m_prop2_check6.EnableWindow(FALSE);
			this->m_prop2_check6.SetCheck(FALSE);
		}
		if(this->m_prop2_check6.GetCheck())
		{
			this->m_prop2_check5.EnableWindow(FALSE);
			this->m_prop2_check5.SetCheck(FALSE);
		}
	}
}
void CSetProp2::OnProp2Check5() 
{
	// TODO: Add your control notification handler code here
	if(this->m_prop2_check5.GetCheck())
	{
		this->m_prop2_check6.EnableWindow(FALSE);
		this->m_prop2_check6.SetCheck(FALSE);
	}
	else
	{
		this->m_prop2_check6.EnableWindow();
		this->m_prop2_check6.SetCheck(FALSE);
	}
}
void CSetProp2::OnProp2Check6() 
{
	// TODO: Add your control notification handler code here
	if(this->m_prop2_check6.GetCheck())
	{
		this->m_prop2_check5.EnableWindow(FALSE);
		this->m_prop2_check5.SetCheck(FALSE);
	}
	else
	{
		this->m_prop2_check5.EnableWindow();
		this->m_prop2_check5.SetCheck(FALSE);
	}
}
