// SetProp3.cpp : implementation file
//

#include "stdafx.h"
#include "mjantivirus.h"
#include "SetProp3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetProp3 property page

IMPLEMENT_DYNCREATE(CSetProp3, CPropertyPage)

CSetProp3::CSetProp3() : CPropertyPage(CSetProp3::IDD)
{
	//{{AFX_DATA_INIT(CSetProp3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CSetProp3::~CSetProp3()
{
}

void CSetProp3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetProp3)
	DDX_Control(pDX, IDC_PROP3_CHECK4, m_prop3_check4);
	DDX_Control(pDX, IDC_PROP3_CHECK3, m_prop3_check3);
	DDX_Control(pDX, IDC_PROP3_CHECK2, m_prop3_check2);
	DDX_Control(pDX, IDC_PROP3_CHECK1, m_prop3_check1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetProp3, CPropertyPage)
	//{{AFX_MSG_MAP(CSetProp3)
	ON_BN_CLICKED(IDC_PROP3_CHECK1, OnProp3Check1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetProp3 message handlers

void CSetProp3::Serialize(CArchive& ar) 
{
	if (ar.IsStoring())
	{	// storing code
		ar<<this->m_prop3_check1.GetCheck()
		  <<this->m_prop3_check2.GetCheck()
		  <<this->m_prop3_check3.GetCheck()
		  <<this->m_prop3_check4.GetCheck();
	}
	else
	{	// loading code
		BOOL setting;
		ar>>setting;
		this->m_prop3_check1.SetCheck(setting);
		ar>>setting;
		this->m_prop3_check2.SetCheck(setting);
		ar>>setting;
		this->m_prop3_check3.SetCheck(setting);
		ar>>setting;
		this->m_prop3_check4.SetCheck(setting);
		if(this->m_prop3_check1.GetCheck())
		{
			this->m_prop3_check2.EnableWindow(FALSE);
			this->m_prop3_check3.EnableWindow(FALSE);
			this->m_prop3_check4.EnableWindow(FALSE);
			this->m_prop3_check2.SetCheck(FALSE);
			this->m_prop3_check3.SetCheck(FALSE);
			this->m_prop3_check4.SetCheck(FALSE);
		}
	}
}

void CSetProp3::OnProp3Check1() 
{
	// TODO: Add your control notification handler code here
	if(this->m_prop3_check1.GetCheck())
	{
		this->m_prop3_check2.EnableWindow(FALSE);
		this->m_prop3_check3.EnableWindow(FALSE);
		this->m_prop3_check4.EnableWindow(FALSE);
		this->m_prop3_check2.SetCheck(FALSE);
		this->m_prop3_check3.SetCheck(FALSE);
		this->m_prop3_check4.SetCheck(FALSE);
	}
	else
	{
		this->m_prop3_check2.EnableWindow();
		this->m_prop3_check3.EnableWindow();
		this->m_prop3_check4.EnableWindow();
		this->m_prop3_check2.SetCheck(FALSE);
		this->m_prop3_check3.SetCheck(FALSE);
		this->m_prop3_check4.SetCheck(FALSE);
	}
}
