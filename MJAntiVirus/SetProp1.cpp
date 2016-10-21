// SetProp1.cpp : implementation file
//

#include "stdafx.h"
#include "mjantivirus.h"
#include "SetProp1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetProp2 property page

IMPLEMENT_DYNCREATE(CSetProp1, CPropertyPage)

CSetProp1::CSetProp1() : CPropertyPage(CSetProp1::IDD)
{
	//{{AFX_DATA_INIT(CSetProp1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CSetProp1::~CSetProp1()
{
}

void CSetProp1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetProp1)
	DDX_Control(pDX, IDC_PROP1_CHECK5, m_prop1_check5);
	DDX_Control(pDX, IDC_PROP1_CHECK4, m_prop1_check4);
	DDX_Control(pDX, IDC_PROP1_CHECK3, m_prop1_check3);
	DDX_Control(pDX, IDC_PROP1_CHECK2, m_prop1_check2);
	DDX_Control(pDX, IDC_PROP1_CHECK1, m_prop1_check1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetProp1, CPropertyPage)
	//{{AFX_MSG_MAP(CSetProp1)
	ON_BN_CLICKED(IDC_PROP1_CHECK1, OnCheck1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetProp1 message handlers

void CSetProp1::OnCheck1() 
{
	// TODO: Add your control notification handler code here
	if(this->m_prop1_check1.GetCheck())
	{
		this->m_prop1_check2.EnableWindow();
		this->m_prop1_check3.EnableWindow();
		this->m_prop1_check4.EnableWindow();
		this->m_prop1_check5.EnableWindow();
		this->m_prop1_check2.SetCheck(FALSE);
		this->m_prop1_check3.SetCheck(FALSE);
		this->m_prop1_check4.SetCheck(FALSE);
		this->m_prop1_check5.SetCheck(FALSE);
	}
	else
	{
		this->m_prop1_check2.EnableWindow(FALSE);
		this->m_prop1_check3.EnableWindow(FALSE);
		this->m_prop1_check4.EnableWindow(FALSE);
		this->m_prop1_check5.EnableWindow(FALSE);
		this->m_prop1_check2.SetCheck(FALSE);
		this->m_prop1_check3.SetCheck(FALSE);
		this->m_prop1_check4.SetCheck(FALSE);
		this->m_prop1_check5.SetCheck(FALSE);
	}
}

void CSetProp1::Serialize(CArchive& ar) 
{
	if (ar.IsStoring())
	{	// storing code
		ar<<this->m_prop1_check1.GetCheck()
		  <<this->m_prop1_check2.GetCheck()
		  <<this->m_prop1_check3.GetCheck()
		  <<this->m_prop1_check4.GetCheck()
		  <<this->m_prop1_check5.GetCheck();
	}
	else
	{	// loading code
		BOOL setting;
		ar>>setting;
		this->m_prop1_check1.SetCheck(setting);
		ar>>setting;
		this->m_prop1_check2.SetCheck(setting);
		ar>>setting;
		this->m_prop1_check3.SetCheck(setting);
		ar>>setting;
		this->m_prop1_check4.SetCheck(setting);
		ar>>setting;
		this->m_prop1_check5.SetCheck(setting);
		if(!this->m_prop1_check1.GetCheck())
		{
			this->m_prop1_check2.EnableWindow(FALSE);
			this->m_prop1_check3.EnableWindow(FALSE);
			this->m_prop1_check4.EnableWindow(FALSE);
			this->m_prop1_check5.EnableWindow(FALSE);
			this->m_prop1_check2.SetCheck(FALSE);
			this->m_prop1_check3.SetCheck(FALSE);
			this->m_prop1_check4.SetCheck(FALSE);
			this->m_prop1_check5.SetCheck(FALSE);
		}
	}
}
