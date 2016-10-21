// RegDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mjantivirus.h"
#include "RegDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegDlg dialog


CRegDlg::CRegDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegDlg)
	DDX_Control(pDX, IDC_LAB_REGSTATE, m_lab_regstate);
	DDX_Control(pDX, IDC_EDIT_REGCODE, m_edit_regcode);
	DDX_Control(pDX, IDC_BTN_REG, m_btn_reg);
	DDX_Control(pDX, IDC_BTN_QUITREG, m_btn_quitreg);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegDlg, CDialog)
	//{{AFX_MSG_MAP(CRegDlg)
	ON_BN_CLICKED(IDC_BTN_REG, OnBtnReg)
	ON_BN_CLICKED(IDC_BTN_QUITREG, OnBtnQuitreg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegDlg message handlers

BOOL CRegDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	pMysocket = new CMysocket(this); //创建套接字对象
	if (!pMysocket->Create()) //创建套接字
	{
		delete pMysocket;
		MessageBox("套接字创建失败.");
		this->m_lab_regstate.SetWindowText("本地计算机网络问题。");
		this->m_btn_reg.EnableWindow(FALSE);
		this->m_edit_regcode.SetReadOnly();
		this->m_btn_quitreg.SetFocus();
		return FALSE;
	}
	//connect
	int port;
	port = 5555; //获取端口
	if  (! pMysocket->Connect("127.0.0.1",port)) //连接服务器
	{
		MessageBox("连接服务器失败!");
		this->m_lab_regstate.SetWindowText("连接服务器失败! 服务器未启动或本地计算机网络未连接。");
		this->m_btn_reg.EnableWindow(FALSE);
		this->m_edit_regcode.SetReadOnly();
		this->m_btn_quitreg.SetFocus();
		return FALSE;
	}
	else
	{
		//MessageBox("连接成功！！！");
		CString str;
		str="L"+this->RegisterProgram();
		pMysocket->Send(str.GetBuffer(str.GetLength()),str.GetLength());	
		//this->m_lab_regstate.SetWindowText("连接服务器成功，请填写注册码。");	
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRegDlg::OnBtnReg() 
{
	// TODO: Add your control notification handler code here
	CString temp,temp2;
	this->m_edit_regcode.GetWindowText(temp2);
	temp='R';
	temp+=temp2;
	temp+=this->RegisterProgram();
	//MessageBox(temp);
	int num = pMysocket->Send(temp.GetBuffer(temp.GetLength()),temp.GetLength());
}

void CRegDlg::OnBtnQuitreg() 
{
	// TODO: Add your control notification handler code here
	this->pMysocket->Close();
	delete this->pMysocket;
	this->DestroyWindow();
}

void CRegDlg::ReceiveData()
{
	char buffer[200];
	//接收传来的数据
	int factdata =  pMysocket->Receive(buffer,200);
	buffer[factdata] = '\0';
	CString str;
	str.Format("%s",buffer);
	if(str=="HasRegister")
	{
		this->m_lab_regstate.SetWindowText("本计算机已注册。");
		this->m_btn_reg.EnableWindow(FALSE);
		this->m_edit_regcode.EnableWindow(FALSE);
	}
	else if(str=="HasNotRegister")
	{
		this->m_lab_regstate.SetWindowText("连接服务器成功，请填写注册码。");
		this->m_btn_reg.EnableWindow();
		this->m_edit_regcode.EnableWindow();
	}
	else if(str=="SuccessReg")
	{
		MessageBox("注册成功！");
		this->m_lab_regstate.SetWindowText("注册成功！");
		this->m_btn_reg.EnableWindow(FALSE);
		this->m_edit_regcode.EnableWindow(FALSE);
	}
	else if(str=="RegisterFailByErrorRegCode")
	{
		MessageBox("注册失败！");
		this->m_lab_regstate.SetWindowText("注册失败，可能是注册码错误！");
		this->m_btn_reg.EnableWindow();
		this->m_edit_regcode.EnableWindow();
	}
}
CString CRegDlg::RegisterProgram()
{
 	unsigned long s1,s2;       
	CString MyCpuID,CPUID1,CPUID2;   
 	__asm
 	{   
		push eax
		push edx
 		mov eax,01h
 		xor edx,edx
 		cpuid
 		mov s1,edx
 		mov s2,eax
		pop edx
		pop eax
	}   
	CPUID1.Format("%08X%08X",s1,s2);   
	__asm
	{   
		push eax
		push ecx
		push edx
		mov eax,03h   
		xor ecx,ecx   
		xor edx,edx   
		cpuid   
		mov s1,edx   
		mov s2,ecx
		pop edx
		pop ecx
		pop eax
	}   
	CPUID2.Format("%08X%08X",s1,s2);   
	MyCpuID=CPUID1+CPUID2;
	DWORD ser;
	char namebuf[128];
	char filebuf[128];
	::GetVolumeInformation("c:\\",namebuf,128,&ser,0,0,filebuf,128);
	CString strdisk;
	strdisk.Format("%d",ser);
	CString strmachine;
	strmachine=MyCpuID.Mid(13,5); //从MyCpuID的第13位开始取5个
	strmachine+=strdisk.Mid(3,5);//从strdisk的第3位开始取5个,合并生成机器码
	return strmachine;
}
