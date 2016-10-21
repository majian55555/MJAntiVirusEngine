// MJAntiVirusAboutDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mjantivirus.h"
#include "MJAntiVirusAboutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMJAntiVirusAboutDlg dialog


CMJAntiVirusAboutDlg::CMJAntiVirusAboutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMJAntiVirusAboutDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMJAntiVirusAboutDlg)
	//}}AFX_DATA_INIT
}


void CMJAntiVirusAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMJAntiVirusAboutDlg)
	DDX_Control(pDX, IDC_LABEL6, m_label6);
	DDX_Control(pDX, IDC_LABEL5, m_label5);
	DDX_Control(pDX, IDC_LABEL4, m_label4);
	DDX_Control(pDX, IDC_LABEL3, m_label3);
	DDX_Control(pDX, IDC_LABEL2, m_label2);
	DDX_Control(pDX, IDC_LABEL1, m_label1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMJAntiVirusAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CMJAntiVirusAboutDlg)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMJAntiVirusAboutDlg message handlers

BOOL CMJAntiVirusAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	this->m_label1.SetFontSize(20);
	this->m_label2.SetFontSize(20);
	this->m_label3.SetFontSize(20);
	this->m_label4.SetFontSize(20);
	this->m_label5.SetFontSize(20);
	this->m_label6.SetFontSize(20);
	this->m_label1.SetFontBold(TRUE);
	this->m_label2.SetFontBold(TRUE);
	this->m_label3.SetFontBold(TRUE);
	this->m_label4.SetFontBold(TRUE);
	this->m_label5.SetFontBold(TRUE);
	this->m_label6.SetFontBold(TRUE);
	this->m_label1.SetFontName("隶书");
	this->m_label2.SetFontName("隶书");
	this->m_label3.SetFontName("隶书");
	this->m_label4.SetFontName("隶书");
	this->m_label5.SetFontName("隶书");
	this->m_label6.SetFontName("隶书");
	//this->m_label1.SetTextColor(RGB(0,0,230));
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CMJAntiVirusAboutDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{ 
	HBRUSH hbr=CDialog::OnCtlColor(pDC,pWnd,nCtlColor); 
	//   TODO:   Change   any   attributes   of   the   DC   here 
	if(nCtlColor==CTLCOLOR_STATIC && pWnd->GetDlgCtrlID()==IDC_LABEL1) 
	{
		pDC->SetBkMode(TRANSPARENT); 
		return (HBRUSH)GetStockObject(NULL_BRUSH); 
	}
	if(nCtlColor==CTLCOLOR_STATIC && pWnd->GetDlgCtrlID()==IDC_LABEL2) 
	{
		pDC->SetBkMode(TRANSPARENT); 
		return (HBRUSH)GetStockObject(NULL_BRUSH); 
	} 
	if(nCtlColor==CTLCOLOR_STATIC && pWnd->GetDlgCtrlID()==IDC_LABEL3) 
	{
		pDC->SetBkMode(TRANSPARENT); 
		return (HBRUSH)GetStockObject(NULL_BRUSH); 
	} 
	if(nCtlColor==CTLCOLOR_STATIC && pWnd->GetDlgCtrlID()==IDC_LABEL4) 
	{
		pDC->SetBkMode(TRANSPARENT); 
		return (HBRUSH)GetStockObject(NULL_BRUSH); 
	} 
	if(nCtlColor==CTLCOLOR_STATIC && pWnd->GetDlgCtrlID()==IDC_LABEL5) 
	{
		pDC->SetBkMode(TRANSPARENT); 
		return (HBRUSH)GetStockObject(NULL_BRUSH); 
	} 
	if(nCtlColor==CTLCOLOR_STATIC && pWnd->GetDlgCtrlID()==IDC_LABEL6) 
	{
		pDC->SetBkMode(TRANSPARENT); 
		return (HBRUSH)GetStockObject(NULL_BRUSH); 
	} 
    return  hbr; 
	//TODO:Return a different brush if the default is not desired 
} 
