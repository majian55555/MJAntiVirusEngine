// MJServer2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MJServer2.h"
#include "MJServer2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMJServer2Dlg dialog

CMJServer2Dlg::CMJServer2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMJServer2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMJServer2Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMJServer2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMJServer2Dlg)
	DDX_Control(pDX, IDC_BTN_LISTEN, m_btn_listen);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMJServer2Dlg, CDialog)
	//{{AFX_MSG_MAP(CMJServer2Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_LISTEN, OnBtnListen)
	ON_BN_CLICKED(IDC_BTN_CREATEFILE, OnBtnCreatefile)
	ON_BN_CLICKED(IDC_BTN_CREATEFILE2, OnBtnCreatefile2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMJServer2Dlg message handlers

BOOL CMJServer2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMJServer2Dlg::OnPaint() 
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
HCURSOR CMJServer2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMJServer2Dlg::OnBtnListen() 
{
	// TODO: Add your control notification handler code here
	m_pSocket = new CServerSocket(this);
	if (!m_pSocket->Create(5555,SOCK_STREAM,"127.0.0.1"))
	{
		MessageBox("套接字创建失败");
		delete m_pSocket;
		m_pSocket = NULL;
		return;
	}
	if (!m_pSocket->Listen())
		MessageBox("监听失败");
	else
	{
		this->m_btn_listen.EnableWindow(FALSE);
	}
}

void CMJServer2Dlg::AcceptConnect()
{
	CClientSocket* socket = new CClientSocket(this);
	//接受客户端的连接
	if (m_pSocket->Accept(*socket))
	{
		m_socketlist.AddTail(socket);
		//MessageBox("连接成功！！！");
	}
	else
		delete socket;
}

void CMJServer2Dlg::ReceiveData(CClientSocket* socket)
{
	char bufferdata[BUFFERSIZE];

	//接收客户端传来的数据
	int result = socket->Receive(bufferdata,BUFFERSIZE);
	bufferdata[result] = '\0';
	if(bufferdata[0]=='R') //register注册
	{
		//MessageBox("取注册码");
		CString str,tempmachine,tempregcode;
		str=bufferdata;
		//Messageox(str);B
		tempmachine=str.Right(10);
		tempregcode=str.Mid(1,str.GetLength()-11);
		//MessageBox(tempmachine);
		//MessageBox(tempregcode);
		if(this->FindRegCode(tempregcode)) //能在注册码文件中找到str
		{
			if(this->Register(tempmachine))
			{
					CString strgetmachinecode="SuccessReg";
					socket->Send(strgetmachinecode.GetBuffer(strgetmachinecode.GetLength()),strgetmachinecode.GetLength());
					return;
			}
		}
		CString strFail="RegisterFailByErrorRegCode";
		socket->Send(strFail.GetBuffer(strFail.GetLength()),strFail.GetLength());
		return;
	}
	if(bufferdata[0]=='L') //Logon
	{
		//MessageBox("取机器码"); 
		CString str;
		str=bufferdata;
		str=str.Right(str.GetLength()-1);
		CString reg=this->Carlugate(str);//通过密钥计算获得
		if(this->FindRegMachine(reg)) //能在注册的计算机信息文件中找到reg
		{
			CString strsucess="HasRegister";
			socket->Send(strsucess.GetBuffer(strsucess.GetLength()),strsucess.GetLength());
		}
		else
		{
			CString strFail="HasNotRegister";
			socket->Send(strFail.GetBuffer(strFail.GetLength()),strFail.GetLength());
		}
		return;
	}
	/*
	if(bufferdata[0]=='C')
	{
		CString str;
		str=bufferdata;
		str=str.Right(str.GetLength()-1);
		//MessageBox(str);
		if(this->FindRegCode(temp))
		{
			CString strsucess="RegisterSecess";
			socket->Send(strsucess.GetBuffer(strsucess.GetLength()),strsucess.GetLength());
		}
		else
		{
			CString strfail="RegisterFailByServer";
			socket->Send(strfail.GetBuffer(strfail.GetLength()),strfail.GetLength());
		}
	}*/
}

CString CMJServer2Dlg::Carlugate(CString strmachine)
{
	CString code[16]={"it","is","th","ea","nt","iv","ir","us",
	"pr","og","ra","mm","ad","eb","ym","aj"};//索引字符，“It is the Antivirus program made by MaJ"
	CString reg;
	int num;
	strmachine.MakeLower();
	for(int i=0;i<10;i++)
	{
		char p=strmachine.GetAt(i);
		if(p>='a'&&p<='f')
			num=p-'a'+10;
		else
			num=p-'0';
		CString tmp=code[num];
		reg+=tmp;
 	}
 	reg.MakeUpper();
 	//MessageBox(reg);
 	return reg;
}

BOOL CMJServer2Dlg::FindRegCode(CString regcode) //注册码文件中找到regcode
{
	CFile file_regcode(_T("Register\\regcode.MJreg"),CFile::modeRead);
	file_regcode.SeekToBegin();
	CArchive ar(&file_regcode,CArchive::load);
	CStringArray strary;
	strary.Serialize(ar);
	ar.Close();
	file_regcode.Close();
	int arylenth=strary.GetSize();
	for(int i=0;i<arylenth;i++)
	{
		CString str=strary.GetAt(i);
		//MessageBox(str);
		if(str==regcode)
		{
			strary.RemoveAt(i);
			file_regcode.Open(_T("Register\\regcode.MJreg"),CFile::modeCreate|CFile::modeWrite);
			CArchive ar2(&file_regcode,CArchive::store);
			strary.Serialize(ar2);
			ar2.Close();
			file_regcode.Close();
			return TRUE;
		}
	}
	return FALSE;
}

BOOL CMJServer2Dlg::FindRegMachine(CString reg)//能在注册的计算机信息文件中找到reg
{
	CFile file_regcode(_T("Register\\reg.MJreg"),CFile::modeRead);
	file_regcode.SeekToBegin();
	if(file_regcode.GetLength()==0)
	{
		return FALSE;
	}
	CArchive ar(&file_regcode,CArchive::load);
	CStringArray strary;
	strary.Serialize(ar);
	ar.Close();
	file_regcode.Close();
	int arylenth=strary.GetSize();
	for(int i=0;i<arylenth;i++)
	{
		CString str=strary.GetAt(i);
		//MessageBox(str);
		if(str==reg)
		{
			strary.RemoveAt(i);
			file_regcode.Open(_T("Register\\reg.MJreg"),CFile::modeCreate|CFile::modeWrite);
			CArchive ar2(&file_regcode,CArchive::store);
			strary.Serialize(ar2);
			ar2.Close();
			file_regcode.Close();
			return TRUE;
		}
	}
	return FALSE;
}

BOOL CMJServer2Dlg::Register(CString strmachine) //把reg写入注册信息文件
{
	CString reg=this->Carlugate(strmachine);
	CFile file_regcode(_T("Register\\reg.MJreg"),CFile::modeReadWrite);
	file_regcode.SeekToBegin();
	CStringArray strary;
	if(file_regcode.GetLength()==0)
	{
		CArchive ar2(&file_regcode,CArchive::store);
		strary.Add(reg);
		strary.Serialize(ar2);
		ar2.Close();
		file_regcode.Close();
		return TRUE;
	}
	else
	{
		CArchive ar(&file_regcode,CArchive::load);
		strary.Serialize(ar);
		ar.Close();
		file_regcode.SeekToBegin();
		CArchive ar2(&file_regcode,CArchive::store);
		strary.Add(reg);
		strary.Serialize(ar2);
		ar2.Close();
		file_regcode.Close();
		return TRUE;
	}
	return FALSE;
}

void CMJServer2Dlg::OnBtnCreatefile()
{
	// TODO: Add your control notification handler code here
	CStringArray strary;
	CString str="aaaaaaaaaaaaaaaaaaaa";
	strary.Add(str);
	str="bbbbbbbbbbbbbbbbbbbb";
	strary.Add(str);
	str="cccccccccccccccccccc";
	strary.Add(str);
	str="dddddddddddddddddddd";
	strary.Add(str);
	str="eeeeeeeeeeeeeeeeeeee";
	strary.Add(str);
	str="ffffffffffffffffffff";
	strary.Add(str);
	CFile file_regcode(_T("Register\\regcode.MJreg"),CFile::modeCreate|CFile::modeWrite);
	CArchive ar(&file_regcode,CArchive::store);
	strary.Serialize(ar);
	ar.Close();
	file_regcode.Close();
}

void CMJServer2Dlg::OnBtnCreatefile2() 
{
	// TODO: Add your control notification handler code here
	CFile file_regcode(_T("Register\\reg.MJreg"),CFile::modeCreate);
	file_regcode.Close();
}


void CMJServer2Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString str="eeeeeeeeeeeeeeeeeeee";
	if(this->FindRegCode(str))
		MessageBox("has");
	else
		MessageBox("hasn't");
}
