// DlgScanSet.cpp : implementation file
//

#include "stdafx.h"
#include "MJAntiVirus.h"
#include "DlgScanSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgScanSet dialog


CDlgScanSet::CDlgScanSet() : CDialog(CDlgScanSet::IDD)
{
	//{{AFX_DATA_INIT(CDlgScanSet)
	m_scanmode = -1;
	m_scanspeed = -1;
	m_memfirstornot = -1;
	m_turnoffornot = -1;
	m_scanfile = -1;
	//}}AFX_DATA_INIT
}


void CDlgScanSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgScanSet)
	DDX_Radio(pDX, IDC_RADIO_DERDEL, m_scanmode);
	DDX_Radio(pDX, IDC_RADIO_HIGHSPEED, m_scanspeed);
	DDX_Radio(pDX, IDC_RADIO_MEMFIRST, m_memfirstornot);
	DDX_Radio(pDX, IDC_RADIO_TURNOFFAFT, m_turnoffornot);
	DDX_Radio(pDX, IDC_RADIO_ALLFILE, m_scanfile);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgScanSet, CDialog)
	//{{AFX_MSG_MAP(CDlgScanSet)
	ON_BN_CLICKED(IDC_BTN_SCANSETOK, OnBtnScansetok)
	ON_BN_CLICKED(IDC_BTN_SCANSETCANCEL, OnBtnScansetcancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgScanSet message handlers


BOOL CDlgScanSet::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CFile scansetfile;
	if(scansetfile.Open("Setting\\ScanSet.dat",CFile::modeRead | CFile::shareDenyNone))
	{
		scansetfile.SeekToBegin();
		CArchive setscanarc(&scansetfile,CArchive::load);
		this->Serialize(setscanarc);
		setscanarc.Close();
		scansetfile.Close();
	}
	else
	{
		scansetfile.Open("Setting\\ScanSet.dat",CFile::modeCreate |CFile::modeReadWrite);
		scansetfile.SeekToBegin();
		CArchive setscanarc(&scansetfile,CArchive::store);
		int i=0,j=1;
		setscanarc<<i<<j<<j<<i<<j;
		setscanarc.Close();
		scansetfile.SeekToBegin();
		CArchive setscanarc2(&scansetfile,CArchive::load);
		this->Serialize(setscanarc2);
		setscanarc2.Close();
		scansetfile.Close();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgScanSet::Serialize(CArchive& ar) 
{
	if (ar.IsStoring())
	{	// storing code
		this->UpdateData();
		this->UpdateData(FALSE);
		ar<<this->m_scanfile<<this->m_scanmode<<this->m_scanspeed<<this->m_memfirstornot<<this->m_turnoffornot;
		
	}
	else
	{	// loading code
		int scanfile=0,scanmode=0,scanspeed=0,scanmem=0,scanturnoff=0;
		ar>>this->m_scanfile>>this->m_scanmode>>this->m_scanspeed>>this->m_memfirstornot>>this->m_turnoffornot;
		switch(this->m_scanfile)
		{
			case 0:
				((CButton*)CWnd::GetDlgItem(IDC_RADIO_ALLFILE))->SetCheck(1);
				break;
			case 1:
				((CButton*)CWnd::GetDlgItem(IDC_RADIO_EXEFILE))->SetCheck(1);
				break;
			default:
				MessageBox("扫描设置文件出错！！");
				break;
		}
		switch(this->m_scanmode)
		{
			case 0:
				((CButton*)CWnd::GetDlgItem(IDC_RADIO_DERDEL))->SetCheck(1);
				break;
			case 1:
				((CButton*)CWnd::GetDlgItem(IDC_RADIO_KILLDEL))->SetCheck(1);
				break;
			case 2:
				((CButton*)CWnd::GetDlgItem(IDC_RADIO_KILLNOTE))->SetCheck(1);
				break;
			case 3:
				((CButton*)CWnd::GetDlgItem(IDC_RADIO_DERNOTE))->SetCheck(1);
				break;
			default:
				MessageBox("扫描设置文件出错！！");
				break;
		}
		switch(this->m_scanspeed)
		{
			case 0:
				((CButton*)CWnd::GetDlgItem(IDC_RADIO_HIGHSPEED))->SetCheck(1);
				break;
			case 1:
				((CButton*)CWnd::GetDlgItem(IDC_RADIO_MIDSPEED))->SetCheck(1);
				break;
			case 3:
				((CButton*)CWnd::GetDlgItem(IDC_RADIO_LOWSPEED))->SetCheck(1);
				break;
			default:
				MessageBox("扫描设置文件出错！！");
				break;
		}
		switch(this->m_memfirstornot)
		{
			case 0:
				((CButton*)CWnd::GetDlgItem(IDC_RADIO_MEMFIRST))->SetCheck(1);
				break;
			case 1:
				((CButton*)CWnd::GetDlgItem(IDC_RADIO_UNMEMFIRST))->SetCheck(1);
				break;
			default:
				MessageBox("扫描设置文件出错！！");
				break;
		}
		switch(this->m_turnoffornot)
		{
			case 0:
				((CButton*)CWnd::GetDlgItem(IDC_RADIO_TURNOFFAFT))->SetCheck(1);
				break;
			case 1:
				((CButton*)CWnd::GetDlgItem(IDC_RADIO_NONTURNOFF))->SetCheck(1);
				break;
			default:
				MessageBox("扫描设置文件出错！！");
				break;
		}
	}
}

void CDlgScanSet::OnBtnScansetok() 
{
	// TODO: Add your control notification handler code here
	CFile setscanfile;
 	if(setscanfile.Open("Setting\\ScanSet.dat",CFile::modeCreate | CFile::modeWrite))
 	{
		setscanfile.SeekToBegin();
 		CArchive setscanarc(&setscanfile,CArchive::store);
 		this->Serialize(setscanarc);
 		setscanarc.Close();
 		setscanfile.Close();
 	}
 	this->OnOK();
}

void CDlgScanSet::OnBtnScansetcancel() 
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}
