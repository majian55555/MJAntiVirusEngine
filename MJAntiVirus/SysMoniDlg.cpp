// SysMoniDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MJAntiVirus.h"
#include "MJAntiVirusDlg.h"
#include "SysMoniDlg.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSysMoniDlg dialog
extern CMJAntiVirusDlg* itDialog;

CSysMoniDlg::CSysMoniDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSysMoniDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSysMoniDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSysMoniDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSysMoniDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSysMoniDlg, CDialog)
	//{{AFX_MSG_MAP(CSysMoniDlg)
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSysMoniDlg message handlers
DWORD WINAPI CSysMoniDlg::ThreadProc_SysMoni(LPVOID lParam )  //线程函数
{
	CSysMoniDlg* sysmonidlg=(CSysMoniDlg*)lParam;  //参数转化
	sysmonidlg->m_i=0;
	sysmonidlg->hDir = CreateFile(            //打开目录，得到目录的句柄
									sysmonidlg->m_strWatchedDir,
									GENERIC_READ|GENERIC_WRITE,
									FILE_SHARE_READ|FILE_SHARE_WRITE|FILE_SHARE_DELETE,
									NULL,
									OPEN_EXISTING,
									FILE_FLAG_BACKUP_SEMANTICS,
									NULL
								); 
	if(sysmonidlg->hDir ==INVALID_HANDLE_VALUE  ) 
		return false;
	char buf[(sizeof(FILE_NOTIFY_INFORMATION)+MAX_PATH)*2];
	FILE_NOTIFY_INFORMATION* pNotify=(FILE_NOTIFY_INFORMATION*)buf;
	DWORD dwBytesReturned;        
	while(true)
	{
		if(::ReadDirectoryChangesW(sysmonidlg->hDir,pNotify,sizeof(buf),true,FILE_NOTIFY_CHANGE_FILE_NAME|
			FILE_NOTIFY_CHANGE_DIR_NAME|FILE_NOTIFY_CHANGE_ATTRIBUTES|FILE_NOTIFY_CHANGE_SIZE|
			FILE_NOTIFY_CHANGE_LAST_WRITE|FILE_NOTIFY_CHANGE_LAST_ACCESS|FILE_NOTIFY_CHANGE_CREATION|
			FILE_NOTIFY_CHANGE_SECURITY,&dwBytesReturned,NULL,NULL))
		{
			char tmp[MAX_PATH],str1[MAX_PATH],str2[MAX_PATH];
			memset(tmp,0,sizeof(tmp)); //ZeroMemory()
			WideCharToMultiByte(CP_ACP,0,pNotify->FileName,pNotify->FileNameLength/2,tmp,99,NULL,NULL);
			strcpy(str1,tmp);
			if(pNotify->NextEntryOffset!=0)
			{
				PFILE_NOTIFY_INFORMATION p=(PFILE_NOTIFY_INFORMATION)((char*)pNotify+pNotify->NextEntryOffset);
				memset( tmp,0,sizeof(tmp));
				WideCharToMultiByte(CP_ACP,0,p->FileName,p->FileNameLength/2,tmp,99,NULL,NULL);
				strcpy(str2,tmp);
			}
			switch(pNotify->Action)
			{				
				case FILE_ACTION_ADDED:
					if(sysmonidlg->m_bAddNew0)
					{
						CTime tt=CTime::GetCurrentTime();	
						CString strTT;
						strTT.Format("%d:%d:%d",tt.GetHour(),tt.GetMinute(),tt.GetSecond());
						sysmonidlg->m_list.InsertItem(0,sysmonidlg->m_szi);
						sysmonidlg->m_list.SetItemText(0,2,"添加了新文件");
						sysmonidlg->m_list.SetItemText(0,3,str1);
						sysmonidlg->m_list.SetItemText(0,1,strTT);
				//		PlaySound(MAKEINTRESOURCE(IDR_WAVE1),AfxGetResourceHandle(),SND_RESOURCE|SND_PURGE|SND_NODEFAULT); 
					}
					break;
				case FILE_ACTION_REMOVED:
					if(sysmonidlg->m_bDel0)
					{
						CTime tt=CTime::GetCurrentTime();	
						CString strTT;
						strTT.Format("%d:%d:%d",tt.GetHour(),tt.GetMinute(),tt.GetSecond());
						sysmonidlg->m_list.InsertItem(0,sysmonidlg->m_szi);
						sysmonidlg->m_list.SetItemText(0,2,"删除了文件");
						sysmonidlg->m_list.SetItemText(0,3,str1);
						sysmonidlg->m_list.SetItemText(0,1,strTT);
				//		PlaySound(MAKEINTRESOURCE(IDR_WAVE1),AfxGetResourceHandle(),SND_RESOURCE|SND_PURGE|SND_NODEFAULT); 
					}
					break;
				case FILE_ACTION_RENAMED_NEW_NAME:
					if(sysmonidlg->m_bRename0)
					{
						CTime tt=CTime::GetCurrentTime();	
						CString strTT;
						strTT.Format("%d:%d:%d",tt.GetHour(),tt.GetMinute(),tt.GetSecond());
						sysmonidlg->m_list.InsertItem(0,sysmonidlg->m_szi);
						sysmonidlg->m_list.SetItemText(0,2,"重命名了文件");
						strcat(str1,"->");
						sysmonidlg->m_list.SetItemText(0,3,strcat(str1,str2));
						sysmonidlg->m_list.SetItemText(0,1,strTT);
						//			PlaySound(MAKEINTRESOURCE(IDR_WAVE1),AfxGetResourceHandle(),SND_RESOURCE|SND_PURGE|SND_NODEFAULT); 
					}
					break;
				case FILE_ACTION_RENAMED_OLD_NAME:
					if(sysmonidlg->m_bRename0)
					{
						CTime tt=CTime::GetCurrentTime();	
						CString strTT;
						strTT.Format("%d:%d:%d",tt.GetHour(),tt.GetMinute(),tt.GetSecond());
						sysmonidlg->m_list.InsertItem(0,sysmonidlg->m_szi);
						sysmonidlg->m_list.SetItemText(0,2,"重命名了文件");
						strcat(str1," 改名为 ");
						sysmonidlg->m_list.SetItemText(0,3,strcat(str1,str2));
						sysmonidlg->m_list.SetItemText(0,1,strTT);
						//			PlaySound(MAKEINTRESOURCE(IDR_WAVE1),AfxGetResourceHandle(),SND_RESOURCE|SND_PURGE|SND_NODEFAULT); 
					}
					break;
				case FILE_ACTION_MODIFIED:
					if(sysmonidlg->m_bModify0)
					{
						CTime tt=CTime::GetCurrentTime();	
						CString strTT;
						strTT.Format("%d:%d:%d",tt.GetHour(),tt.GetMinute(),tt.GetSecond());
						sysmonidlg->m_list.InsertItem(0,sysmonidlg->m_szi);
						sysmonidlg->m_list.SetItemText(0,2,"修改了文件");
						sysmonidlg->m_list.SetItemText(0,3,str1);
						sysmonidlg->m_list.SetItemText(0,1,strTT);
						//		PlaySound(MAKEINTRESOURCE(IDR_WAVE1),AfxGetResourceHandle(),SND_RESOURCE|SND_PURGE|SND_NODEFAULT); 
					}
					break;  
				default:
					if(sysmonidlg->m_bOther0)
					{
						CTime tt=CTime::GetCurrentTime();	
						CString strTT;
						strTT.Format("%d:%d:%d",tt.GetHour(),tt.GetMinute(),tt.GetSecond());
						sysmonidlg->m_list.InsertItem(0,sysmonidlg->m_szi);
						sysmonidlg->m_list.SetItemText(0,2,"未知变化");
						sysmonidlg->m_list.SetItemText(0,3,"");
						sysmonidlg->m_list.SetItemText(0,1,strTT);
						//		PlaySound(MAKEINTRESOURCE(IDR_WAVE1),AfxGetResourceHandle(),SND_RESOURCE|SND_PURGE|SND_NODEFAULT); 
					}
					break;  
			}	
			sysmonidlg->m_i++;
			sysmonidlg->m_szi.Format("%d",sysmonidlg->m_i);
			//itoa(sysmonidlg->m_i,sysmonidlg->m_szi,10);
			//AfxBeginThread(SoundThread,0);			
		}
		else           
			break;           
	}
	return 0;
}
BOOL CSysMoniDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_list.ModifyStyle(LVS_TYPEMASK,LVS_REPORT);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_FLATSB|LVS_EX_TWOCLICKACTIVATE |LVS_EX_GRIDLINES);
	m_list.InsertColumn(0,"数量",LVCFMT_LEFT,40);
	m_list.InsertColumn(1,"时间",LVCFMT_LEFT,80);
	m_list.InsertColumn(2,"类型",LVCFMT_LEFT,100);
	m_list.InsertColumn(3,"变化的内容",LVCFMT_LEFT,500);
	GetDlgItem(IDC_STATE)->SetWindowText("停止了监视");
	GetDlgItem(IDC_STOP)->EnableWindow(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSysMoniDlg::OnStart() 
{
	// TODO: Add your control notification handler code here
	CString path=_T("C:\\");
	if(AfxMessageBox("开启系统监视？",MB_YESNO | MB_ICONQUESTION)==IDYES)
	{
		if(!this->StartWatch(path))
		{
			MessageBox("创建系统监视线程出错！！！");
		}
		GetDlgItem(IDC_STOP)->EnableWindow(true);
		GetDlgItem(IDC_START)->EnableWindow(false);	
		GetDlgItem(IDC_STATE)->SetWindowText("正在监视...    ");
		itDialog->m_AgentEx.Play("Processing2");
	}
}
void CSysMoniDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_STATE)->SetWindowText("停止了监视");
	if(this->m_hThread !=NULL)
	{
		::TerminateThread(this->m_hThread,0);
		this->m_hThread = NULL;
	}
	if(hDir !=INVALID_HANDLE_VALUE)
	{
		CloseHandle(this->hDir);
		this->hDir = INVALID_HANDLE_VALUE;
	}
	GetDlgItem(IDC_STOP)->EnableWindow(false);
	GetDlgItem(IDC_START)->EnableWindow(true);
	itDialog->StopAgent();
}

void CSysMoniDlg::OnClear() 
{
	// TODO: Add your control notification handler code here
	this->m_list.DeleteAllItems();
}

BOOL CSysMoniDlg::StartWatch(CString path)
{
	this->m_strWatchedDir = path;  
	DWORD ThreadId;  //创建一个新线程用于监视
	this->m_hThread=::CreateThread(NULL,0,ThreadProc_SysMoni,this,THREAD_PRIORITY_IDLE,&ThreadId);
	return NULL!=m_hThread;
}

void CSysMoniDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(this->m_hThread !=NULL)
	{
		::TerminateThread(this->m_hThread,0);
		this->m_hThread = NULL;
	}
	if(hDir !=INVALID_HANDLE_VALUE)
	{
		CloseHandle(this->hDir);
		this->hDir = INVALID_HANDLE_VALUE;
	}
	CDialog::OnClose();
}
