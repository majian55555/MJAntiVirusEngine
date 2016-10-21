// Test4Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test4.h"
#include "Test4Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
#include "CVirus.h"
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest4Dlg dialog

CTest4Dlg::CTest4Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTest4Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTest4Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTest4Dlg)
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTest4Dlg, CDialog)
	//{{AFX_MSG_MAP(CTest4Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest4Dlg message handlers

BOOL CTest4Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTest4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTest4Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTest4Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTest4Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CDWordArray ar1;
	ar1.Add(0x58354F21);
	ar1.Add(0x50254041);
	ar1.Add(0x505B345C);
	ar1.Add(0x505A5835);
	ar1.Add(0x3428505E);
	ar1.Add(0x29374343);
	ar1.Add(0x29377D24);
	ar1.Add(0x45494341);
	//CDWordArray ar2;
	//ar2.Copy(ar1);
	//CString str;
	//str.Format("%d",ar1.GetSize());
	//MessageBox(str);
	//str.Format("%d",ar1[0]);
	//MessageBox(str);
	CObArray obarray1;
	CVirusSignature vs1;
	vs1.vsCreate(0x00000000,ar1.GetSize(),ar1);
	obarray1.Add(&vs1);
	CVirus virus1;
	virus1.vCreate("eicar",1,obarray1);
	CString str;
	//str.Format("%d",((CVirusSignature*)obarray1[0])->GetvsSize());
	MessageBox(virus1.GetvName());
	str.Format("%d",virus1.GetvsCount());
	MessageBox(str);
	if(virus1.WriteToFile(_T("data\\")))
		MessageBox("Write successful!");
	/*CVirus vs2;
	if(vs2.LoadFromFile(_T("data\\MyFirstVirus.mjvinfo")))
		MessageBox("Load Successful!");
	MessageBox(vs2.GetvName());
	CString str;
	str.Format("%d",vs2.GetvsCount());
	MessageBox(str);
	CFile objFile;*/
	/*objFile.Open("objfile.dat",CFile::modeCreate | CFile::modeWrite);
	objFile.Seek(0x00000100,CFile::begin);
	DWORD dw;
	dw=0x11111111;
	objFile.Write(&dw,sizeof(dw));
	dw=0x12222221;
	objFile.Write(&dw,sizeof(dw));
	dw=0x13333331;
	objFile.Write(&dw,sizeof(dw));*/
	CFile objFile;
	BOOL canopenfile=objFile.Open("C:\Documents and Settings\All Users\Application Data\Jiangmin\Log\FileGuard.log",CFile::modeRead);
	objFile.Seek(100,CFile::begin);
	if(virus1.vMatch(objFile))
		MessageBox("有病毒");
	else
		MessageBox("没有病毒");
	objFile.Close();
	objFile.Open("ReadMe.txt",CFile::modeRead);
	if(virus1.vMatch(objFile))
		MessageBox("有病毒");
	else
		MessageBox("没有病毒");
	//CString str;
	//DWORD dw2;
	//str.Format("%d",sizeof(dw2));
	//MessageBox(str);
	//this->m_edit1.SetWindowText("21322");
}
