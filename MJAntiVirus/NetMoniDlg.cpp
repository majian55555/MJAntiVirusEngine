// NetMoniDlg.cpp : implementation file
//
#include "stdafx.h"
#include "MJAntiVirus.h"
#include "MJAntiVirusDlg.h"
#include "NetMoniDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CMJAntiVirusDlg* itDialog;
/////////////////////////////////////////////////////////////////////////////
// CNetMoniDlg dialog
PROTONAME protos[11] = {
	{IPPROTO_IP ,"IP"},
	{IPPROTO_ICMP,"ICMP"},
	{IPPROTO_IGMP,"IGMP"},
	{IPPROTO_GGP,"GGP"},
	{IPPROTO_TCP,"TCP"},
	{IPPROTO_PUP,"PUP"},
	{IPPROTO_UDP,"UDP"},
	{IPPROTO_IDP,"IDP"},
	{IPPROTO_ND,"ND"},
	{IPPROTO_RAW,"RAW"},
	{IPPROTO_MAX,"MAX"}
};



CNetMoniDlg::CNetMoniDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNetMoniDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNetMoniDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNetMoniDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetMoniDlg)
	DDX_Control(pDX, IDC_BTN_CANCEL, m_btn_cancel);
	DDX_Control(pDX, IDC_BTN_BEGINLISTEN, m_btn_beginlisten);
	DDX_Control(pDX, IDC_LIST1, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNetMoniDlg, CDialog)
	//{{AFX_MSG_MAP(CNetMoniDlg)
	ON_BN_CLICKED(IDC_BTN_BEGINLISTEN, OnBtnBeginlisten)
	ON_BN_CLICKED(IDC_BTN_CANCEL, OnBtnCancel)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetMoniDlg message handlers

BOOL CNetMoniDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_List.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_GRIDLINES|LVS_EX_TWOCLICKACTIVATE);
	m_List.InsertColumn(0,"协议",LVCFMT_LEFT,80);
	m_List.InsertColumn(1,"源IP地址",LVCFMT_LEFT,120);
	m_List.InsertColumn(2,"目的IP地址",LVCFMT_LEFT,120);
	m_List.InsertColumn(3,"通信端口",LVCFMT_LEFT,80);
	m_List.InsertColumn(4,"大小",LVCFMT_LEFT,100);
	m_List.InsertColumn(5,"数据",LVCFMT_LEFT,120);
	this->m_btn_beginlisten.EnableWindow();
	this->m_btn_cancel.EnableWindow(FALSE);
	this->m_pThread=NULL;
	this->m_Sock=NULL;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

char* CNetMoniDlg::get_protoname(int protoID)
{
	for (int i= 0; i<11; i++)
	{
		if (protoID == protos[i].value)
		{
			return protos[i].protoname;
		}
	}
	return "";
}

UINT CNetMoniDlg::ThreadFun(LPVOID pParam)
{
	CNetMoniDlg* pDlg = static_cast<CNetMoniDlg*>(pParam);
	MSG msg;
	char buffer[1000],sourceip[32] ,*tempbuf;
	char *ptemp;
	BYTE* pData = NULL; //实际数据报中的数据
	UINT  sourceport ;
	CString str;
	HEADIP*    pHeadIP;
	HEADICMP*  pHeadICMP;
	HEADUDP*   pHeadUDP;
	HEADTCP*   pHeadTCP;
	in_addr addr;
	int ret;
	while (TRUE)
	{
		pData = NULL;
		if (PeekMessage(&msg,pDlg->m_hWnd,WM_CLOSE,WM_CLOSE,PM_NOREMOVE ))
		{
			closesocket(pDlg->m_Sock);
			break;		
		}
		memset(buffer,0,1000);
		ret = recv(pDlg->m_Sock,buffer,1000,0);
		if (ret == SOCKET_ERROR)
		{
			continue;
		}
		else //接收到数据
		{
			tempbuf = buffer;
			pHeadIP = (HEADIP*)tempbuf;
			//获取数据报总长度
			WORD len = ntohs(pHeadIP->totallen);
			//获取源IP
			pDlg->m_List.InsertItem(pDlg->m_List.GetItemCount(),"");
			addr.S_un.S_addr = pHeadIP->sourceIP;
			ptemp = inet_ntoa(addr);
			pDlg->m_List.SetItemText(pDlg->m_List.GetItemCount()-1,1,ptemp);
			//获取目的IP
			addr.S_un.S_addr = pHeadIP->destIP;
			ptemp = inet_ntoa(addr);
			pDlg->m_List.SetItemText(pDlg->m_List.GetItemCount()-1,2,ptemp);
			//获取协议名称
			ptemp = get_protoname(pHeadIP->proto);
			strcpy(sourceip,ptemp);
			pDlg->m_List.SetItemText(pDlg->m_List.GetItemCount()-1,0,sourceip);
			//获取IP数据报总长度
			WORD ipSumLen  =  ntohs(pHeadIP->totallen);
			//IP数据报头总长度
			int ipHeadLen = 20;
			//获得去除IP层数据的长度
			WORD  netlen = ipSumLen - ipHeadLen;
			//根据不同大协议获得不同协议的数据
			switch (pHeadIP->proto)
			{
			case IPPROTO_ICMP:
				{
					pHeadICMP = (HEADICMP*)(tempbuf+20);
					pData = (BYTE*)(pHeadICMP)+4; //ICMP数据报头共4个字节					
					//获取数据的长度
					netlen -= 4;
					break;
				}
			case IPPROTO_UDP:
				{
					pHeadUDP = (HEADUDP*)(tempbuf+20);
					pData = (BYTE*)pHeadUDP+8; //UDP数据报头共8个字节
					sourceport = ntohs(pHeadUDP->SourcePort);
					str.Format("%d",sourceport);
					//设置源端口
					pDlg->m_List.SetItemText(pDlg->m_List.GetItemCount()-1,3,str);	
					str.Empty();
					netlen -= 8;				
					break;
				}
			case IPPROTO_TCP:
				{
					pHeadTCP = (HEADTCP*)(tempbuf+20);
					sourceport = ntohs(pHeadTCP->SourcePort);					

					pData = (BYTE*)pHeadTCP+20; //TCP数据报头共20个字节
									 
					str.Format("%d",sourceport);
					//设置源端口
					pDlg->m_List.SetItemText(pDlg->m_List.GetItemCount()-1,3,str);	
					str.Empty();
					netlen-= 20;				
					break;
				}									
			}
			//设置数据大小
			str.Format("%d",netlen);
			pDlg->m_List.SetItemText(pDlg->m_List.GetItemCount()-1,4,str);
			str.Empty();
			//设置数据
			if (pData != NULL)
			{
				str.Format(" %s",pData);
				pDlg->m_List.SetItemText(pDlg->m_List.GetItemCount()-1,5,str);
			}
			str.Empty();
		}
	}
	return 0;
}


void CNetMoniDlg::OnBtnBeginlisten() 
{
	//创建套接字
	if(IDYES==AfxMessageBox("开启网络系统监视？",MB_YESNO | MB_ICONQUESTION))
	{
		m_Sock = socket(AF_INET,SOCK_RAW, IPPROTO_IP );
		char name[128];
		memset(name,0,128);
		hostent* phostent;
		phostent =  gethostbyname(name);
		DWORD ip;
		ip = inet_addr(inet_ntoa(*(in_addr*)phostent->h_addr_list[0]));
		int timeout = 4000; //超时4秒
		//设置接收数据的超时时间
		setsockopt(m_Sock,SOL_SOCKET,SO_RCVTIMEO,(const char*)&timeout,sizeof(timeout));
		sockaddr_in skaddr;
		skaddr.sin_family = AF_INET;
		skaddr.sin_port = htons(700);
		skaddr.sin_addr.S_un.S_addr  = ip;
		//绑定地址
		if ( bind(m_Sock,(sockaddr*)&skaddr,sizeof(skaddr))==SOCKET_ERROR)
		{
			MessageBox("地址绑定错误");
			return;
		}
		DWORD inBuffer=1;
		DWORD outBuffer[10];
		DWORD reValue = 0;
		if (WSAIoctl(m_Sock,SIO_RCVALL,&inBuffer,sizeof(inBuffer),&outBuffer,sizeof(outBuffer),&reValue,NULL,NULL)==SOCKET_ERROR)
		{
			MessageBox("设置缓冲区错误.");
			closesocket(m_Sock);
			return;
		}
		else
		{
			m_pThread = AfxBeginThread(ThreadFun,(void*)this,THREAD_PRIORITY_IDLE);
			this->m_btn_beginlisten.EnableWindow(FALSE);
			this->m_btn_cancel.EnableWindow();
			itDialog->StopAgent();
			itDialog->m_AgentEx.Play("Processing2");
		}
	}
}

void CNetMoniDlg::OnBtnCancel()
{
	if(m_pThread)
	{
		//m_pThread->ExitInstance();
		::TerminateThread(this->m_pThread,0);
		delete m_pThread;
	}
	closesocket(m_Sock);
	this->m_btn_beginlisten.EnableWindow();
	this->m_btn_cancel.EnableWindow(FALSE);
	itDialog->StopAgent();
}

void CNetMoniDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(this->m_pThread)
	{
		//m_pThread->ExitInstance();
		::TerminateThread(this->m_pThread,0);
		delete m_pThread;
	}
	if(this->m_Sock)
		closesocket(m_Sock);
	CDialog::OnClose();
}
