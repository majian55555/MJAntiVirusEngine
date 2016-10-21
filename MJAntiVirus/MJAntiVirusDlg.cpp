// MJAntiVirusDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MJAntiVirus.h"
#include "MJAntiVirusDlg.h"
#include "CVirus.h"
#include "DlgScanSet.h"
#include "SetPropSheet.h"
#include "PSAPI.H"
#pragma comment(lib,"PSAPI.LIB" )

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CMJAntiVirusDlg* itDialog;
/////////////////////////////////////////////////////////////////////////////
// CMJAntiVirusDlg dialog

CMJAntiVirusDlg::CMJAntiVirusDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMJAntiVirusDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMJAntiVirusDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMJAntiVirusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMJAntiVirusDlg)
	DDX_Control(pDX, IDC_LIST_SELEICON, m_list_seleicon);
	DDX_Control(pDX, IDC_LB_FILENUM, m_lb_filenum);
	DDX_Control(pDX, IDC_LIST_SHOWRLT, m_list_showresult);
	DDX_Control(pDX, IDC_BTN_STOP, m_btn_stop);
	DDX_Control(pDX, IDC_BTN_PAUSE, m_btn_pause);
	DDX_Control(pDX, IDC_EDIT_TIME, m_edit_time);
	DDX_Control(pDX, IDC_BTN_START, m_btn_start);
	DDX_Control(pDX, IDC_LB_SHOWF, m_lb_showf);
	DDX_Control(pDX, IDC_TRDISKTREE, m_trdisktree);
	DDX_Control(pDX, IDC_LIST_OUTLOOK, m_List);
	DDX_Control(pDX, IDC_AGENT1, m_agent);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMJAntiVirusDlg, CDialog)
	//{{AFX_MSG_MAP(CMJAntiVirusDlg)
	ON_WM_PAINT()
	ON_WM_SYSCOMMAND()
	ON_MESSAGE(WM_TRARMESSAGE,OnTrayMessage)
	ON_WM_MEASUREITEM()
	ON_WM_DRAWITEM()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TRDISKTREE, OnSelchangedTrdisktree)
	ON_BN_CLICKED(IDC_BTN_START, OnBtnStart)
	ON_NOTIFY(NM_CLICK, IDC_TRDISKTREE, OnClickTrdisktree)
	ON_BN_CLICKED(IDC_BTN_PAUSE, OnBtnPause)
	ON_BN_CLICKED(IDC_BTN_STOP, OnBtnStop)
	ON_WM_CLOSE()
	ON_COMMAND(ID_MENUITEM_RESTORE, OnMenuitemRestore)
	ON_COMMAND(ID_MENUITEM_CLOSE, OnMenuitemClose)
	ON_COMMAND(ID_MENUITEM_ABOUT, OnMenuitemAbout)
	ON_COMMAND(ID_MENUITEM_CMPINFO, OnMenuitemCmpinfo)
	ON_COMMAND(ID_MENUITEM_LOCK, OnMenuitemLock)
	ON_COMMAND(ID_MENUITEM_NETMONI, OnMenuitemNetmoni)
	ON_COMMAND(ID_MENUITEM_SHOWPROC, OnMenuitemProc)
	ON_COMMAND(ID_MENUITEM_REGISTER, OnMenuitemRegister)
	ON_COMMAND(ID_MENUITEM_SYSMONI, OnMenuitemSysmoni)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMJAntiVirusDlg message handlers

BOOL CMJAntiVirusDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	itDialog=this;

	this->m_Imagelist.Create(32,32,ILC_COLOR24|ILC_MASK,0,1);
	this->m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	this->m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	this->m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	this->m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
	this->m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON5));
	this->m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON6));
	this->m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON7));

	//向列表视图控件中添加按钮
	this->m_List.SetImageLists(&m_Imagelist);
	this->m_List.AddButton("病毒扫描",500);
	this->m_List.AddButton("实时监视",501);
	this->m_List.AddButton("工具",502);
	this->m_List.AddButton("服务",503);
	this->m_List.AddButton("帮助",504);

	//设置回调函数
	this->m_List.pItemDlbFun =OnItemDouble;

	//向指定按钮添加关联的视图项
	CString str;
	str="图标目标选择";
	m_List.AddButtonItems(0,str);
	str="文件夹目标选择";
	m_List.AddButtonItems(0,str);
	str="扫描杀毒设置";
	m_List.AddButtonItems(0,str);
	str="操作系统监视";
	m_List.AddButtonItems(1,str);
	str="网络系统监视";
	m_List.AddButtonItems(1,str);
	str="设置";
	m_List.AddButtonItems(2,str);
	str="获取计算机系统属性";
	m_List.AddButtonItems(2,str);
	str="显示正在运行的程序";
	m_List.AddButtonItems(2,str);
	str="锁定计算机";
	m_List.AddButtonItems(2,str);
	str="加密文件";
	m_List.AddButtonItems(2,str);
	str="加密文件夹";
	m_List.AddButtonItems(2,str);
	str="注册";
	m_List.AddButtonItems(3,str);
	str="升级";
	m_List.AddButtonItems(3,str);
	str="关于本程序";
	m_List.AddButtonItems(4,str);
	str="使用本程序的帮助";
	m_List.AddButtonItems(4,str);

	this->m_imagelist.Create(16,16,ILC_COLOR32|ILC_MASK,0,0);
	this->m_trdisktree.SetImageList(&(this->m_imagelist),TVSIL_NORMAL);
	this->m_trdisktree.ModifyStyle(0L,TVS_HASLINES|TVS_LINESATROOT);
	HTREEITEM root=this->m_trdisktree.InsertItem("我的电脑");
	unsigned int alldriver=::GetLogicalDriveStrings(0,NULL);
	char *driverstr=new char[alldriver+sizeof(_T(""))];
	if(::GetLogicalDriveStrings(alldriver,driverstr)!=alldriver-1)
		return FALSE;
	char *pdriverstr=driverstr;
	unsigned int driversize=strlen(pdriverstr);
	HTREEITEM disktree;
	while(driversize>0)
	{
		::SHGetFileInfo(pdriverstr,0,&(this->m_fileinfo),sizeof(this->m_fileinfo),SHGFI_ICON);
		m_imindex=this->m_imagelist.Add(this->m_fileinfo.hIcon);
		disktree=this->m_trdisktree.InsertItem(pdriverstr,m_imindex,m_imindex,root,TVI_LAST);
		this->m_trdisktree.EnsureVisible(disktree);

		CFileFind findfile;
		CString rootstr=this->m_trdisktree.GetItemText(disktree);
		BOOL bfinded=findfile.FindFile(rootstr+_T("\\*.*"));
		while(bfinded)
		{
			bfinded=findfile.FindNextFile();
			CString filepath;
			if(findfile.IsDots())
				continue;
			if(findfile.IsDirectory())
			{
				::SHGetFileInfo(findfile.GetFilePath(),0,&(this->m_fileinfo),sizeof(this->m_fileinfo),SHGFI_ICON);
				this->m_imindex=this->m_imagelist.Add(this->m_fileinfo.hIcon);
				HTREEITEM subtreeitem=this->m_trdisktree.InsertItem(findfile.GetFileName(),this->m_imindex,this->m_imindex,disktree);
			}
		}
		pdriverstr+=driversize+1;
		driversize=strlen(pdriverstr);
	}
	this->m_treetrace="";
	this->m_trdisktree.ShowWindow(SW_HIDE);
	this->m_btn_pause.EnableWindow(FALSE);
	this->m_btn_stop.EnableWindow(FALSE);
	this->m_lb_showf.ShowWindow(SW_HIDE);
	this->m_edit_time.ShowWindow(SW_HIDE);
	this->m_list_showresult.ShowWindow(SW_HIDE);

	CTimeSpan t1(0,0,0,0);
	this->m_time=t1;
	this->m_edit_time.SetWindowText("");
//加载病毒库
	CFileFind virus_filefind;
 	BOOL virus_bFind;
 	virus_bFind=virus_filefind.FindFile(_T("data\\*.*"));
	this->m_VArray.RemoveAll();
 	while(virus_bFind)
 	{
 		virus_bFind=virus_filefind.FindNextFile();
 		if(virus_filefind.IsDots())
 		{
 			continue;
 		}
		CVirus *vs=new CVirus();
		vs->LoadFromFile(virus_filefind.GetFilePath());
		this->m_VArray.Add((CVirus*)vs);
		//MessageBox("Load Successful!");
	}
//设置图标显示列表框
	this->m_imagelistforicon.Create(74,74,ILC_COLORDDB|ILC_MASK,20,1);
	this->m_imagelistforicon.Add(AfxGetApp()->LoadIcon(IDI_ICON_MYCOMPUTER));
	this->m_imagelistforicon.Add(AfxGetApp()->LoadIcon(IDI_ICON_DOCUMENT));
	this->m_imagelistforicon.Add(AfxGetApp()->LoadIcon(IDI_ICON_HARDDISK));
	this->m_imagelistforicon.Add(AfxGetApp()->LoadIcon(IDI_ICON_MEMORY));
	this->m_imagelistforicon.Add(AfxGetApp()->LoadIcon(IDI_ICON_SYSFILE));
	this->m_imagelistforicon.Add(AfxGetApp()->LoadIcon(IDI_ICON_CDROM));
	this->m_imagelistforicon.Add(AfxGetApp()->LoadIcon(IDI_ICON_USB));
	this->m_list_seleicon.SetImageList(&(this->m_imagelistforicon),LVSIL_NORMAL);
	this->m_list_seleicon.InsertItem(0,"我的电脑",0);
	this->m_list_seleicon.InsertItem(1,"我的文档",1);
	this->m_list_seleicon.InsertItem(2,"我的硬盘",2);
	this->m_list_seleicon.InsertItem(3,"我的内存",3);
	this->m_list_seleicon.InsertItem(4,"系统文件",4);
	this->m_list_seleicon.InsertItem(5,"光盘",5);
	this->m_list_seleicon.InsertItem(6,"移动存储",6);
//设置线程句柄
	this->thread_findfile=NULL;
	this->thread_mycomputer=NULL;
	this->thread_time=NULL;
	this->m_setpropsheet=NULL;
//设置动态鼠标
	HCURSOR cursor=AfxGetApp()->LoadStandardCursor(IDC_ARROW);
	this->m_oldcursor=CopyCursor(cursor);
	this->m_mycursor=::LoadCursorFromFile("mouse.ani");
	if(this->m_mycursor==NULL)
	{
		AfxMessageBox("装入鼠标文件失败");
	}
	else
	{
		::ShowCursor(false);
		::SetSystemCursor(this->m_mycursor,32512);
		::ShowCursor(true);
	}
//获取关机权限
	static HANDLE hToken;   
	static TOKEN_PRIVILEGES tp;
	static LUID luid;        							
	OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY,&hToken);
	LookupPrivilegeValue(NULL,SE_SHUTDOWN_NAME,&luid);
	tp.PrivilegeCount =1;
	tp.Privileges [0].Luid =luid;
	tp.Privileges [0].Attributes =SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(hToken,FALSE,&tp,sizeof(TOKEN_PRIVILEGES),NULL, NULL);

//设定系统托盘ICON和MENU
	this->m_menu.LoadMenu(IDR_TRAYMENU);
	this->m_menu.ChangeMenuItem(&this->m_menu);
	//this->m_menu.DrawItem();
	this->m_traydata.cbSize = sizeof(NOTIFYICONDATA);
	this->m_traydata.hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	this->m_traydata.hWnd = this->m_hWnd;
	char* m_str="计科052班马健的毕业设计--病毒查杀程序";
	strncpy(this->m_traydata.szTip,m_str,strlen(m_str)+1);//strlen +1表示将空字符拷贝到目标字符串中
	this->m_traydata.uCallbackMessage = WM_TRARMESSAGE;
	this->m_traydata.uFlags = NIF_ICON|NIF_MESSAGE|NIF_TIP;

//设置小助手
	COleVariant iv("0");
	this->m_AgentCharacters=this->m_agent.GetCharacters();
	this->m_AgentRequest=this->m_AgentCharacters.Load("Ozzar",COleVariant("Ozzar.acs"));
	this->m_AgentEx=this->m_AgentCharacters.Character("Ozzar");
	this->m_AgentEx.Show(iv);
	COleVariant iv1;
	this->m_AgentEx.SetLeft(GetSystemMetrics(SM_CXSCREEN)/2);
	this->m_AgentEx.SetTop(GetSystemMetrics(SM_CYSCREEN)/2);
	this->m_AgentEx.MoveTo(GetSystemMetrics(SM_CXSCREEN)-150,GetSystemMetrics(SM_CYSCREEN)-200,iv1);
	COleVariant iv2("你好，我是Ozzar。这是计科052班，马健的毕业设计!");
	COleVariant iv3;
	this->m_AgentEx.Play("Announce");
	this->m_AgentEx.Speak(iv2,iv3);
	this->m_AgentEx.Play("Wave");
	this->m_AgentEx.Play("RestPose");
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMJAntiVirusDlg::OnPaint() 
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
HCURSOR CMJAntiVirusDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
BOOL CMJAntiVirusDlg::OnEraseBkgnd(CDC* pDC) 
{
	CRect rc;
	pDC->GetClipBox(&rc);
	DrawGradient(pDC->GetSafeHdc(), rc, RGB(180,180,250), RGB(250,250,255), 1);		
	return TRUE;
}
void CMJAntiVirusDlg::DrawGradient(HDC pDC,const RECT& rect,COLORREF begin, COLORREF end, const int &width)
{
	RECT rcstep;	
	HBRUSH br;
	int	n,m;
	float step=0.0;
	int	nred=0,ngreen=0,nblue=0;
	float red=0.0,green=0.0,blue=0.0;
	nred=(GetRValue(end)-GetRValue(begin));
	ngreen=(GetGValue(end)-GetGValue(begin));
	nblue=(GetBValue(end)-GetBValue(begin));
	step=(float)abs(rect.top-rect.bottom)/(float)width;
	red=nred/(float)step;
	green=ngreen/(float)step;
	blue=nblue/(float)step;
	nred=GetRValue(begin);
	ngreen=GetGValue(begin);
	nblue=GetBValue(begin);
	for(int start=0 ; start <= step ; start++)
	{
		n=min((int)(rect.top+start*width), rect.bottom);
		m=min((int)(rect.top+(start+1)*width), rect.bottom);
		::SetRect(&rcstep,rect.left,n,rect.right+1,m);
		br=CreateSolidBrush(RGB(nred + red*start,
		ngreen + green*start,nblue + blue*start));
		HBRUSH oldbr=(HBRUSH)::SelectObject(pDC,br);
		FillRect(pDC,&rcstep,br);
		::SelectObject(pDC,oldbr);
		DeleteObject(br);
	}
}

void CMJAntiVirusDlg::OnItemDouble(const CListCtrl *pListCtrl, int nIndex)
{
	if (pListCtrl)
	{
		CString str = pListCtrl->GetItemText(nIndex,0);
		if("图标目标选择"==str)
		{
			itDialog->m_trdisktree.ShowWindow(SW_HIDE);
			itDialog->m_list_seleicon.ShowWindow(SW_SHOW);
			itDialog->m_btn_start.ShowWindow(SW_SHOW);
			itDialog->m_btn_stop.ShowWindow(SW_SHOW);
			itDialog->m_btn_stop.EnableWindow(FALSE);
			itDialog->m_btn_pause.ShowWindow(SW_SHOW);
			itDialog->m_btn_pause.EnableWindow(FALSE);
			itDialog->m_lb_showf.ShowWindow(SW_SHOW);
			return;
		}
		if("文件夹目标选择"==str)
		{
			itDialog->m_list_seleicon.ShowWindow(SW_HIDE);
			itDialog->m_trdisktree.ShowWindow(SW_SHOW);
			itDialog->m_btn_start.ShowWindow(SW_SHOW);
			itDialog->m_btn_stop.ShowWindow(SW_SHOW);
			itDialog->m_btn_stop.EnableWindow(FALSE);
			itDialog->m_btn_pause.ShowWindow(SW_SHOW);
			itDialog->m_btn_pause.EnableWindow(FALSE);
			itDialog->m_lb_showf.ShowWindow(SW_SHOW);
			return;
		}
		if("扫描杀毒设置"==str)
		{
			itDialog->ShowScanSetDlg();
			return;
		}
		if("操作系统监视"==str)
		{
			itDialog->ShowSysMoniDlg();
			return;
		}
		if("网络系统监视"==str)
		{
			itDialog->ShowNetMoniDlg();
			return;
		}
		if("设置"==str)
		{
			itDialog->ShowSetDlg();
			return;
		}
		if("获取计算机系统属性"==str)
		{
			itDialog->ShowComputerInfoDlg();
			return;
		}
		if("显示正在运行的程序"==str)
		{
			itDialog->ExecuProcessView();
			return;
		}
		if("锁定计算机"==str)
		{
			itDialog->ShowLockDlg();
			return;
		}
		if("加密文件"==str)
		{
			itDialog->ShowFileEncryDlg();
			return;
		}
		if("加密文件夹"==str)
		{
			itDialog->ShowFolderEncryDlg();
			return;
		}
		if("注册"==str)
		{
			//AfxMessageBox("此功能暂无！！！",MB_OK | MB_ICONQUESTION);
			itDialog->ShowRegDlg();
			return;
		}
		if("升级"==str)
		{
			AfxMessageBox("此功能暂无！！！",MB_OK | MB_ICONQUESTION);
			return;
		}
		if("关于本程序"==str)
		{
			itDialog->ShowAboutDlg();
			return;
		}
		if("使用本程序的帮助"==str)
		{
			AfxMessageBox("此功能暂无！！！",MB_OK | MB_ICONQUESTION);
			return;
		}
	}
}

void CMJAntiVirusDlg::OnSelchangedTrdisktree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	this->m_treetrace="";
	CFileFind findfile;
	HTREEITEM parent;
	HTREEITEM seleitem=this->m_trdisktree.GetSelectedItem();
	HTREEITEM childitem=this->m_trdisktree.GetChildItem(seleitem);
	if(this->m_trdisktree.GetItemText(seleitem)=="我的电脑")
	{
		return;
	}
	if((childitem) && (this->m_trdisktree.GetItemText(seleitem)!="我的电脑"))
	{
		while(childitem)
		{
			this->m_trdisktree.DeleteItem(childitem);
			childitem=this->m_trdisktree.GetChildItem(seleitem);
		}	
	}
	parent=this->m_trdisktree.GetParentItem(seleitem);
	this->m_treetrace=this->m_trdisktree.GetItemText(seleitem);
	while(parent)
	{
		this->m_treetrace=this->m_trdisktree.GetItemText(parent)+_T("\\")+this->m_treetrace;
		parent=this->m_trdisktree.GetParentItem(parent);
	}
	this->m_treetrace.Delete(0,9); //删除“我的电脑\”
	BOOL bfinded=findfile.FindFile(this->m_treetrace+_T("\\*.*"));
	while(bfinded)
	{
		bfinded=findfile.FindNextFile();
		if(findfile.IsDots())
			continue;
		if(findfile.IsDirectory())
		{
			::SHGetFileInfo(findfile.GetFilePath(),0,&(this->m_fileinfo),sizeof(this->m_fileinfo),SHGFI_ICON);
			this->m_imindex=this->m_imagelist.Add(this->m_fileinfo.hIcon);
			HTREEITEM subtreeitem=this->m_trdisktree.InsertItem(findfile.GetFileName(),this->m_imindex,this->m_imindex,seleitem);
			this->m_trdisktree.SetCheck(subtreeitem,this->m_trdisktree.GetCheck(seleitem));
			CFileFind findfile2;
			BOOL bfinded2=findfile2.FindFile(findfile.GetFilePath()+_T("\\*.*"));
			while(bfinded2)
			{
				bfinded2=findfile2.FindNextFile();
				if(findfile2.IsDots())
					continue;
				if(findfile2.IsDirectory())
				{
					::SHGetFileInfo(findfile2.GetFilePath(),0,&(this->m_fileinfo),sizeof(this->m_fileinfo),SHGFI_ICON);
					this->m_imindex=this->m_imagelist.Add(this->m_fileinfo.hIcon);
					this->m_trdisktree.InsertItem(findfile2.GetFileName(),this->m_imindex,this->m_imindex,subtreeitem,TVI_FIRST);
				 }
			}
		}
	}
	*pResult = 0;
}


void CMJAntiVirusDlg::OnBtnStart() 
{
	// TODO: Add your control notification handler code here
	CFile scansetfile;
	if(scansetfile.Open("Setting\\ScanSet.dat",CFile::modeRead | CFile::shareDenyNone))
	{
		scansetfile.SeekToBegin();
		CArchive setscanarc(&scansetfile,CArchive::load);
		setscanarc>>this->m_scanset.scanfile>>this->m_scanset.scanmode
					>>this->m_scanset.scanspeed>>this->m_scanset.memfirst>>this->m_scanset.turnoff;
		setscanarc.Close();
 		scansetfile.Close();
	}
	else
	{
		this->m_scanset.memfirst=0;
		this->m_scanset.scanfile=0;
		this->m_scanset.scanmode=1;
		this->m_scanset.scanspeed=1;
		this->m_scanset.turnoff=1;
	}
	CTimeSpan t1(0,0,0,0);
	this->m_time=t1;
	this->m_edit_time.SetWindowText(this->m_time.Format("%H时%M分%S秒"));
	this->m_list_showresult.ModifyStyle(0L,LVS_REPORT);
	this->m_list_showresult.ModifyStyle(0L,LVS_SINGLESEL);
	this->m_list_showresult.ModifyStyle(0L,LVS_SHOWSELALWAYS);
	this->m_list_showresult.ModifyStyle(0L,LVS_NOSORTHEADER);
	this->m_list_showresult.SetExtendedStyle(LVS_EX_GRIDLINES);
	int nColumnCount=this->m_list_showresult.GetHeaderCtrl()->GetItemCount();
	for (int i=0;i<nColumnCount;i++)
	{
		this->m_list_showresult.DeleteColumn(0);
	}
	this->m_list_showresult.DeleteAllItems();
	this->m_list_showresult.InsertColumn(0,"文件路径",LVCFMT_LEFT,100);
	this->m_list_showresult.InsertColumn(1,"病毒名",LVCFMT_LEFT,100);
	this->m_list_showresult.InsertColumn(2,"杀毒情况",LVCFMT_LEFT,100);
	this->m_list_showresult.ShowWindow(SW_SHOW);

	this->m_findfilenum=0;
	this->m_findvirusnum=0;
	this->m_killvirusnum=0;
	CString str_filenum;
	str_filenum.Format("文件数：%d 病毒数：%d 杀毒数：%d",this->m_findfilenum,this->m_findvirusnum,this->m_killvirusnum);
	this->m_lb_filenum.SetWindowText(str_filenum);
	this->m_lb_filenum.ShowWindow(SW_SHOW);
	this->m_edit_time.ShowWindow(SW_SHOW);

	HTREEITEM parent;
	if(this->m_trdisktree.IsWindowVisible())
	{
		this->m_FileName="";
		parent=this->m_trdisktree.GetChildItem(this->m_trdisktree.GetRootItem());
		this->thread_findfile=::CreateThread(NULL,0,Fun_findfile,(LPVOID)parent,0,NULL);
		switch(this->m_scanset.scanspeed)
		{
		case 0:
			::SetThreadPriority(this->thread_findfile,THREAD_PRIORITY_ABOVE_NORMAL);
			break;
		case 1:
			::SetThreadPriority(this->thread_findfile,THREAD_PRIORITY_NORMAL);
			break;
		case 2:
			::SetThreadPriority(this->thread_findfile,THREAD_PRIORITY_BELOW_NORMAL);
			break;
		default:
			::SetThreadPriority(this->thread_findfile,THREAD_PRIORITY_NORMAL);
			break;
		
		}
	}
	else if(this->m_list_seleicon.IsWindowVisible())
	{
		switch(this->m_list_seleicon.GetSelectionMark())
		{
		case 0:     //我的电脑
			this->thread_mycomputer=::CreateThread(NULL,0,Fun_mycomputer,(LPVOID)0,0,NULL);
			break;
		case 1:     //我的文档
			this->thread_mycomputer=::CreateThread(NULL,0,Fun_mycomputer,(LPVOID)1,0,NULL);
			break;
		case 2:     //我的硬盘
			this->thread_mycomputer=::CreateThread(NULL,0,Fun_mycomputer,(LPVOID)2,0,NULL);
			break;
		case 3:		//我的内存
			this->thread_mycomputer=::CreateThread(NULL,0,Fun_mycomputer,(LPVOID)3,0,NULL);
			break;
		case 4:		//系统文件
			this->thread_mycomputer=::CreateThread(NULL,0,Fun_mycomputer,(LPVOID)4,0,NULL);
			break;
		case 5:		//光盘
			this->thread_mycomputer=::CreateThread(NULL,0,Fun_mycomputer,(LPVOID)5,0,NULL);
			break;
		case 6:		//移动存储
			this->thread_mycomputer=::CreateThread(NULL,0,Fun_mycomputer,(LPVOID)6,0,NULL);
			break;
		default:
			MessageBox("图标选项未选中或出错，请重新选择！！！");
			return;
		}
		switch(this->m_scanset.scanspeed)
		{
		case 0:
			::SetThreadPriority(this->thread_findfile,THREAD_PRIORITY_ABOVE_NORMAL);
			break;
		case 1:
			::SetThreadPriority(this->thread_findfile,THREAD_PRIORITY_NORMAL);
			break;
		case 2:
			::SetThreadPriority(this->thread_findfile,THREAD_PRIORITY_BELOW_NORMAL);
			break;
		default:
			::SetThreadPriority(this->thread_findfile,THREAD_PRIORITY_NORMAL);
			break;
		}
	}
	else
	{
		return;
	}
	this->thread_time=::CreateThread(NULL,0,Fun_time,NULL,0,NULL);
	::SetThreadPriority(this->thread_time,THREAD_PRIORITY_NORMAL);
	this->m_lb_showf.EnableWindow();
	this->m_lb_showf.ShowWindow(SW_SHOW);
	this->m_btn_start.EnableWindow(FALSE);
	this->m_btn_pause.EnableWindow();
	this->m_btn_stop.EnableWindow();
	this->m_AgentEx.Play("Searching");
}

CString CMJAntiVirusDlg::RecursiveFileName(HTREEITEM childitem)
{
	HTREEITEM parent=this->m_trdisktree.GetParentItem(childitem);
	if(parent==this->m_trdisktree.GetRootItem())
	{
		return this->m_trdisktree.GetItemText(childitem).Left(this->m_trdisktree.GetItemText(childitem).GetLength()-1);
	}
	//MessageBox(this->RecursiveFileName(parent)+_T("\\")+this->m_trdisktree.GetItemText(childitem));
	return(this->RecursiveFileName(parent)+_T("\\")+this->m_trdisktree.GetItemText(childitem));
}
void CMJAntiVirusDlg::RecursiveDiskTree(HTREEITEM parent)
{
	//MessageBox(this->m_trdisktree.GetItemText(parent));
	HTREEITEM childitem=itDialog->m_trdisktree.GetChildItem(parent);
	while(childitem)
	{
		if(itDialog->m_trdisktree.GetCheck(childitem))
		{
			//MessageBox(this->RecursiveFileName(childitem));
			itDialog->m_FileName=itDialog->RecursiveFileName(childitem);
			//HANDLE thread_findfile=::CreateThread(NULL,0,Fun_findfile,NULL,0,NULL);
			itDialog->FindFile(itDialog->m_FileName);
			childitem=itDialog->m_trdisktree.GetNextSiblingItem(childitem);
			continue;
		}
		else
		{
			if(itDialog->m_trdisktree.GetChildItem(childitem))
				itDialog->RecursiveDiskTree(childitem);
		}
		childitem=itDialog->m_trdisktree.GetNextSiblingItem(childitem);
	}
	return;
}

void CMJAntiVirusDlg::FindFile(CString fname)
{
	CFileFind ff;
 	BOOL bFinded;
 	bFinded=ff.FindFile(fname+_T("\\*.*"));
 	while(bFinded)
 	{
 		bFinded=ff.FindNextFile();
 		if(ff.IsDots())
 		{
 			continue;
 		}
 		if(ff.IsDirectory())
 		{
 			FindFile(ff.GetFilePath());//目标文件是一个子目录，则程序递归调用
 		}
		else
		{
			if(this->m_scanset.scanfile==0)
			{
				this->m_lb_showf.SetWindowText(ff.GetFilePath());   //显示所找到的文件
				CString str_virusname=this->CmpWithVS(ff.GetFilePath());
				if(""!=str_virusname) //是病毒
				{
					this->m_list_showresult.InsertItem(this->m_findvirusnum,"");
					this->m_list_showresult.SetItemText(this->m_findvirusnum,0,ff.GetFilePath());
					this->m_list_showresult.SetItemText(this->m_findvirusnum,1,str_virusname);
					this->m_findvirusnum++;
					//this->m_list_showresult.
					//MessageBox("有病毒:"+str_virusname);
				}
				this->m_findfilenum++;
				CString str_filenum;
				str_filenum.Format("文件数：%d 病毒数：%d 杀毒数：%d",this->m_findfilenum,this->m_findvirusnum,this->m_killvirusnum);
				this->m_lb_filenum.SetWindowText(str_filenum);
			}
			else if(this->m_scanset.scanfile==1)
			{
				if(ff.GetFilePath().Right(4)==".exe" || ff.GetFilePath().Right(4)==".dll" || ff.GetFilePath().Right(4)==".com")
				{
					this->m_lb_showf.SetWindowText(ff.GetFilePath());   //显示所找到的文件
					CString str_virusname=this->CmpWithVS(ff.GetFilePath());
					if(""!=str_virusname) //是病毒
					{
						this->m_list_showresult.InsertItem(this->m_findvirusnum,"");
						this->m_list_showresult.SetItemText(this->m_findvirusnum,0,ff.GetFilePath());
						this->m_list_showresult.SetItemText(this->m_findvirusnum,1,str_virusname);
						this->m_findvirusnum++;
						//this->m_list_showresult.
						//MessageBox("有病毒:"+str_virusname);
					}
					this->m_findfilenum++;
					CString str_filenum;
					str_filenum.Format("文件数：%d 病毒数：%d 杀毒数：%d",this->m_findfilenum,this->m_findvirusnum,this->m_killvirusnum);
					this->m_lb_filenum.SetWindowText(str_filenum);
				}
			}
		}
 	}
}
void CMJAntiVirusDlg::RecursiveDiskTreeCheck(HTREEITEM parent,BOOL checkbox)
{
	HTREEITEM childitem=this->m_trdisktree.GetChildItem(parent);
	if(childitem==NULL)
	{
		return;
	}
	while(childitem)
 		{
 			this->m_trdisktree.SetCheck(childitem,!checkbox);
			this->RecursiveDiskTreeCheck(childitem,checkbox);
 			childitem=this->m_trdisktree.GetNextSiblingItem(childitem);	
		}	
	return;
}

void CMJAntiVirusDlg::OnClickTrdisktree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CPoint pt; 
	GetCursorPos(&pt); 
	this->m_trdisktree.ScreenToClient(&pt); 
	UINT uFlags ; 
	HTREEITEM seleitem = this->m_trdisktree.HitTest(pt,&uFlags); 
	if ( uFlags & TVHT_ONITEMSTATEICON ) //点击在CheckBox上 
	{
		if(this->m_trdisktree.GetCheck(seleitem)) //已选中
		{
			this->m_trdisktree.SelectItem(seleitem);
			this->RecursiveDiskTreeCheck(seleitem,this->m_trdisktree.GetCheck(seleitem));
			HTREEITEM parent=this->m_trdisktree.GetParentItem(seleitem);
			while(parent)
			{
				this->m_trdisktree.SetCheck(parent,FALSE);
				parent=this->m_trdisktree.GetParentItem(parent);
			}
		}
		else  //未选中
		{
			this->m_trdisktree.SelectItem(seleitem);
			this->RecursiveDiskTreeCheck(seleitem,this->m_trdisktree.GetCheck(seleitem));
		}
	} 
	if ( uFlags & TVHT_ONITEMBUTTON) // 点击在+上 
	{ 
		this->m_trdisktree.SelectItem(seleitem);
	} 
	*pResult = 0;
}

void CMJAntiVirusDlg::OnBtnPause() 
{
	// TODO: Add your control notification handler code here
	DWORD exitCode=NULL;
	int rc=::GetExitCodeThread(thread_findfile,&exitCode);
	if(rc && STILL_ACTIVE==exitCode)
	{
		CString str_title;
		this->m_btn_pause.GetWindowText(str_title);
		if("暂停杀毒"==str_title)
		{
			::SuspendThread(this->thread_findfile);
			::SuspendThread(this->thread_time);
			this->m_btn_pause.SetWindowText("继续杀毒");
			this->StopAgent();
		}
		else
		{
			::ResumeThread(this->thread_findfile);
			::ResumeThread(this->thread_time);
			this->m_btn_pause.SetWindowText("暂停杀毒");
			this->m_AgentEx.Play("Searching");
		}
	}
	rc=::GetExitCodeThread(thread_mycomputer,&exitCode);
	if(rc && STILL_ACTIVE==exitCode)
	{
		CString str_title;
		this->m_btn_pause.GetWindowText(str_title);
		if("暂停杀毒"==str_title)
		{
			::SuspendThread(this->thread_mycomputer);
			::SuspendThread(this->thread_time);
			this->m_btn_pause.SetWindowText("继续杀毒");
			this->StopAgent();
		}
		else
		{
			::ResumeThread(this->thread_mycomputer);
			::ResumeThread(this->thread_time);
			this->m_btn_pause.SetWindowText("暂停杀毒");
			this->m_AgentEx.Play("Searching");
		}
	}
}

void CMJAntiVirusDlg::OnBtnStop() 
{
	// TODO: Add your control notification handler code here
	DWORD exitCode=NULL;
	int rc=::GetExitCodeThread(thread_findfile,&exitCode);
	if(rc && STILL_ACTIVE==exitCode)
	{
		::TerminateThread(itDialog->thread_findfile,NULL);
		::TerminateThread(itDialog->thread_time,NULL);
	}
	rc=::GetExitCodeThread(thread_mycomputer,&exitCode);
	if(rc && STILL_ACTIVE==exitCode)
	{
		::TerminateThread(itDialog->thread_mycomputer,NULL);
		::TerminateThread(itDialog->thread_time,NULL);
	}
	this->StopAgent();
	AfxMessageBox("查毒完毕！");
	this->m_lb_showf.SetWindowText("");
	this->m_btn_start.EnableWindow();
	this->m_btn_pause.SetWindowText("暂停杀毒");
	this->m_btn_pause.EnableWindow(FALSE);
	this->m_btn_stop.EnableWindow(FALSE);
	this->m_lb_filenum.ShowWindow(SW_HIDE);
	this->m_edit_time.ShowWindow(SW_HIDE);
}
//DWORD WINAPI Fun_findfile(LPVOID lpParameter);

DWORD WINAPI CMJAntiVirusDlg::Fun_time(LPVOID lpParameter)
{
	while(1)
	{
		itDialog->m_edit_time.SetWindowText(itDialog->m_time.Format("%H时%M分%S秒"));
		::Sleep(1000);
		itDialog->m_time+=CTimeSpan(0,0,0,1);
	}
	return 0;
}

DWORD WINAPI CMJAntiVirusDlg::Fun_findfile(LPVOID lpParameter)
{
	if(itDialog->m_scanset.memfirst==0)
	{
		CStringArray* array_processpath=itDialog->FindProcessFilePath();
		int processcount=array_processpath->GetSize();
		for(int i=0;i<processcount;i++)
		{
			CString str;
			str=array_processpath->GetAt(i);
			itDialog->m_lb_showf.SetWindowText(str);
			CString str_virusname=itDialog->CmpWithVS(str);
			if(""!=str_virusname) //是病毒
			{
				itDialog->m_list_showresult.InsertItem(itDialog->m_findvirusnum,"");
				itDialog->m_list_showresult.SetItemText(itDialog->m_findvirusnum,0,str);
				itDialog->m_list_showresult.SetItemText(itDialog->m_findvirusnum,1,str_virusname);
				itDialog->m_findvirusnum++;
			}
			itDialog->m_findfilenum++;
			CString str_filenum;
			str_filenum.Format("文件数：%d 病毒数：%d 杀毒数：%d",itDialog->m_findfilenum,itDialog->m_findvirusnum,itDialog->m_killvirusnum);
			itDialog->m_lb_filenum.SetWindowText(str_filenum);
		}
	}
	HTREEITEM parent=(HTREEITEM)lpParameter;
	while(parent)
	{
		if(itDialog->m_trdisktree.GetCheck(parent))
		{
			itDialog->FindFile(itDialog->m_trdisktree.GetItemText(parent));
		}
		else
		{
			RecursiveDiskTree(parent);
		}
		parent=itDialog->m_trdisktree.GetNextSiblingItem(parent);
	}
	::TerminateThread(itDialog->thread_time,NULL);
	::SendMessage(itDialog->m_hWnd,WM_COMMAND,0xfff555ee,0xf55555ee);
	AfxMessageBox("查毒完毕！");
	itDialog->m_findfilenum=0;
	itDialog->m_findvirusnum=0;
	itDialog->m_killvirusnum=0;
	itDialog->m_lb_showf.SetWindowText("");
	itDialog->m_edit_time.SetWindowText("");
	itDialog->m_btn_start.EnableWindow();
	itDialog->m_lb_filenum.SetWindowText("");
	itDialog->m_btn_pause.EnableWindow(FALSE);
	itDialog->m_btn_stop.EnableWindow(FALSE);
	CFile scansetfile;
	if(scansetfile.Open("Setting\\ScanSet.dat",CFile::modeRead | CFile::shareDenyNone))
	{
		scansetfile.SeekToBegin();
		CArchive setscanarc(&scansetfile,CArchive::load);
		int turnoffaft;
		setscanarc>>turnoffaft>>turnoffaft>>turnoffaft>>turnoffaft>>turnoffaft;
		setscanarc.Close();
 		scansetfile.Close();
		if(turnoffaft==0)
		{
			//AfxMessageBox("turnoffcomputer");
			::ExitWindowsEx(EWX_POWEROFF,0);
		}
	}
	return 0;
}

DWORD WINAPI CMJAntiVirusDlg::Fun_mycomputer(LPVOID lpParameter)
{
	if(itDialog->m_scanset.memfirst==0)
	{
		CStringArray* array_processpath=itDialog->FindProcessFilePath();
		int processcount=array_processpath->GetSize();
		for(int i=0;i<processcount;i++)
		{
			CString str;
			str=array_processpath->GetAt(i);
			itDialog->m_lb_showf.SetWindowText(str);
			CString str_virusname=itDialog->CmpWithVS(str);
			if(""!=str_virusname) //是病毒
			{
				itDialog->m_list_showresult.InsertItem(itDialog->m_findvirusnum,"");
				itDialog->m_list_showresult.SetItemText(itDialog->m_findvirusnum,0,str);
				itDialog->m_list_showresult.SetItemText(itDialog->m_findvirusnum,1,str_virusname);
				itDialog->m_findvirusnum++;
			}
			itDialog->m_findfilenum++;
			CString str_filenum;
			str_filenum.Format("文件数：%d 病毒数：%d 杀毒数：%d",itDialog->m_findfilenum,itDialog->m_findvirusnum,itDialog->m_killvirusnum);
			itDialog->m_lb_filenum.SetWindowText(str_filenum);
		}
	}
	int i=0,processcount;
	CStringArray* array_processpath;
	int situation=(int)lpParameter;
	char* driverstr=NULL;
	unsigned int alldriver=NULL;
	char* pdriverstr=NULL;
	unsigned int driversize=NULL;
	char strwin[50];
	char strsys[50];
	switch(situation)
	{
	case 0:
		alldriver=::GetLogicalDriveStrings(0,NULL);
		driverstr=new char[alldriver+sizeof(_T(""))];
		if(::GetLogicalDriveStrings(alldriver,driverstr)!=alldriver-1)
		{
			AfxMessageBox("硬盘信息出错，in Funmycomputer");
			return 0;
		}
		pdriverstr=driverstr;
		driversize=strlen(pdriverstr);
		while(driversize>0)
		{
			itDialog->FindFile(pdriverstr);
			pdriverstr+=driversize+1;
			driversize=strlen(pdriverstr);
		}
		break;
	case 1:
		itDialog->FindFile(_T("C:\\Documents and Settings"));
		break;
	case 2:
		alldriver=::GetLogicalDriveStrings(0,NULL);
		driverstr=new char[alldriver+sizeof(_T(""))];
		if(::GetLogicalDriveStrings(alldriver,driverstr)!=alldriver-1)
		{
			AfxMessageBox("硬盘信息出错，in Funmycomputer");
			return 0;
		}
		pdriverstr=driverstr;
		driversize=strlen(pdriverstr);
		while(driversize>0)
		{
			if(::GetDriveType(pdriverstr)==DRIVE_FIXED)
				itDialog->FindFile(pdriverstr);
			pdriverstr+=driversize+1;
			driversize=strlen(pdriverstr);
		}
		break;
	case 3:
		array_processpath=itDialog->FindProcessFilePath();
		processcount=array_processpath->GetSize();
		for(i=0;i<processcount;i++)
		{
			CString str;
			str=array_processpath->GetAt(i);
			itDialog->m_lb_showf.SetWindowText(str);
			CString str_virusname=itDialog->CmpWithVS(str);
			if(""!=str_virusname) //是病毒
			{
				itDialog->m_list_showresult.InsertItem(itDialog->m_findvirusnum,"");
				itDialog->m_list_showresult.SetItemText(itDialog->m_findvirusnum,0,str);
				itDialog->m_list_showresult.SetItemText(itDialog->m_findvirusnum,1,str_virusname);
				itDialog->m_findvirusnum++;
			}
			itDialog->m_findfilenum++;
			CString str_filenum;
			str_filenum.Format("文件数：%d 病毒数：%d 杀毒数：%d",itDialog->m_findfilenum,itDialog->m_findvirusnum,itDialog->m_killvirusnum);
			//AfxMessageBox(str_filenum);
			itDialog->m_lb_filenum.SetWindowText(str_filenum);
		}
		i=0;
		break;
	case 4:
		::GetWindowsDirectory(strwin,50);
		::GetSystemDirectory(strsys,50);
		itDialog->FindFile(_T(strwin));
		if(::strcspn(strwin,strsys)!=0) //strwin是否包含strsys
		{
			//AfxMessageBox("in");
			itDialog->FindFile(_T(strsys));
		}
		break;
	case 5:
		alldriver=::GetLogicalDriveStrings(0,NULL);
		driverstr=new char[alldriver+sizeof(_T(""))];
		if(::GetLogicalDriveStrings(alldriver,driverstr)!=alldriver-1)
		{
			AfxMessageBox("硬盘信息出错，in Funmycomputer");
			return 0;
		}
		pdriverstr=driverstr;
		driversize=strlen(pdriverstr);
		while(driversize>0)
		{
			if(::GetDriveType(pdriverstr)==DRIVE_CDROM)
				itDialog->FindFile(pdriverstr);
			pdriverstr+=driversize+1;
			driversize=strlen(pdriverstr);
		}
		break;
	case 6:
		alldriver=::GetLogicalDriveStrings(0,NULL);
		driverstr=new char[alldriver+sizeof(_T(""))];
		if(::GetLogicalDriveStrings(alldriver,driverstr)!=alldriver-1)
		{
			AfxMessageBox("硬盘信息出错，in Funmycomputer");
			return 0;
		}
		pdriverstr=driverstr;
		driversize=strlen(pdriverstr);
		while(driversize>0)
		{
			if(::GetDriveType(pdriverstr)==DRIVE_REMOVABLE)
				itDialog->FindFile(pdriverstr);
			pdriverstr+=driversize+1;
			driversize=strlen(pdriverstr);
		}
		break;
	default:
		AfxMessageBox("Error in Fun_mycomputer");
		break;
	}
	::TerminateThread(itDialog->thread_time,NULL);
	::SendMessage(itDialog->m_hWnd,WM_COMMAND,0xfff555ee,0xf55555ee);
	AfxMessageBox("查毒完毕！");
	itDialog->m_findfilenum=0;
	itDialog->m_findvirusnum=0;
	itDialog->m_killvirusnum=0;
	itDialog->m_lb_showf.SetWindowText("");
	itDialog->m_edit_time.SetWindowText("");
	itDialog->m_btn_start.EnableWindow();
	itDialog->m_lb_filenum.SetWindowText("");
	itDialog->m_btn_pause.EnableWindow(FALSE);
	itDialog->m_btn_stop.EnableWindow(FALSE);
	CFile scansetfile;
	if(scansetfile.Open("Setting\\ScanSet.dat",CFile::modeRead | CFile::shareDenyNone))
	{
		scansetfile.SeekToBegin();
		CArchive setscanarc(&scansetfile,CArchive::load);
		int turnoffaft;
		setscanarc>>turnoffaft>>turnoffaft>>turnoffaft>>turnoffaft>>turnoffaft;
		setscanarc.Close();
 		scansetfile.Close();
		if(turnoffaft==0)
		{
			//AfxMessageBox("turnoffcomputer");
			::ExitWindowsEx(EWX_POWEROFF,0);
		}
	}
	return 0;
}

CString CMJAntiVirusDlg::CmpWithVS(CString filename)
{
	CFile objFile;
	if(objFile.Open(filename,CFile::modeRead | CFile::typeBinary))
	{
		for(int i=0;i<this->m_VArray.GetSize();i++)
		{
			if(((CVirus*)this->m_VArray[i])->vMatch(objFile))
			{
				objFile.Close();
				return ((CVirus*)this->m_VArray[i])->GetvName();
			}
		}
		objFile.Close();
	}
	return "";
}

void CMJAntiVirusDlg::ShowScanSetDlg()
{
	this->m_ScanSetDlg.DestroyWindow();
	this->m_ScanSetDlg.Create(IDD_DLG_SCANSET,this);
	this->m_ScanSetDlg.ShowWindow(SW_SHOW);
}

void CMJAntiVirusDlg::ShowSetDlg()
{
	this->m_setpropsheet=new CSetPropSheet("病毒查杀程序设置");
	this->m_setpropsheet->Create(this);
}

void CMJAntiVirusDlg::ShowComputerInfoDlg()
{
	this->m_dlg_computerinfo.DestroyWindow();
	this->m_dlg_computerinfo.Create(IDD_DLG_COMPUTERINFO,this);
	this->m_dlg_computerinfo.ShowWindow(SW_SHOW);
}

CStringArray* CMJAntiVirusDlg::FindProcessFilePath()
{
	CStringArray* array_processpath=new CStringArray();
	DWORD processid[1024],needed,processcount,i;
	HANDLE hProcess;
	HMODULE hModule;
	char path[MAX_PATH] = "",temp[256];
	EnumProcesses(processid, sizeof(processid), &needed);
	processcount=needed/sizeof(DWORD);

	for (i=0;i<processcount;i++)
	{
		hProcess=OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,false,processid[i]);
		if (hProcess)
		{
			EnumProcessModules(hProcess, &hModule, sizeof(hModule), &needed);
			GetModuleFileNameEx(hProcess, hModule, path, sizeof(path));
			GetShortPathName(path,path,256);
			itoa(processid[i],temp,10);
			CString str;
			str.Format("%s",path);
			array_processpath->Add(str);
		}
	}
	CloseHandle(hProcess);
	CloseHandle(hModule);
	return array_processpath;
}

void CMJAntiVirusDlg::ExecuProcessView()
{
	STARTUPINFO strinfo;
	PROCESS_INFORMATION processinfo;
	memset(&strinfo,0,sizeof(strinfo));
	strinfo.cb = sizeof(strinfo);
	BOOL ret = CreateProcess(NULL,"ProcessView.exe",NULL,NULL,TRUE,DETACHED_PROCESS,NULL,NULL,&strinfo,&processinfo);
	if (ret)
	{
		WaitForSingleObject(processinfo.hProcess,INFINITE);
	}
	else
	{
		MessageBox("ProcessView.exe不在当前目录，请查看！！！");
	}
}
void CMJAntiVirusDlg::ShowLockDlg()
{
	this->m_locksetdlg.DestroyWindow();
	this->m_locksetdlg.Create(IDD_DLG_LOCKORSET,this);
	this->m_locksetdlg.ShowWindow(SW_SHOW);
}

BOOL CMJAntiVirusDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	//将鼠标设置为原样
	::ShowCursor(false);
	if(::SetSystemCursor(this->m_oldcursor,32512))
		::ShowCursor(true);
	else
	{
		MessageBox("设置鼠标原样式出错！！！");
		::ShowCursor(true);
	}
	return CDialog::DestroyWindow();
}
void CMJAntiVirusDlg::ShowSysMoniDlg()
{
	this->m_sysmonidlg.DestroyWindow();
	this->m_sysmonidlg.Create(IDD_DLG_MONITORFILE,this);
	this->m_sysmonidlg.ShowWindow(SW_SHOW);
}
void CMJAntiVirusDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(MessageBox("是否退出！！！","提示",MB_ICONWARNING | MB_YESNO)==IDYES)
	{
		COleVariant iv("再见！！！");
		COleVariant iv1;
		COleVariant iv2;
		this->m_AgentEx.Speak(iv,iv1);
		this->m_AgentEx.Hide(iv2);
		::Sleep(1300);
		this->m_AgentCharacters.Unload("Ozzar");
		CDialog::OnClose();
	}
}
void CMJAntiVirusDlg::ShowFileEncryDlg()
{
	this->m_fileencrydlg.DestroyWindow();
	this->m_fileencrydlg.Create(IDD_FILEENCRY_DIALOG,this);
	this->m_fileencrydlg.ShowWindow(SW_SHOW);
}
void CMJAntiVirusDlg::ShowFolderEncryDlg()
{
	this->m_folderencrydlg.DestroyWindow();
	this->m_folderencrydlg.Create(IDD_FOLDERENCRY_DIALOG,this);
	this->m_folderencrydlg.ShowWindow(SW_SHOW);
}
void CMJAntiVirusDlg::ShowAboutDlg()
{
	this->m_aboutdlg.DestroyWindow();
	this->m_aboutdlg.Create(IDD_ABOUT_DIALOG,this);
	this->m_aboutdlg.ShowWindow(SW_SHOW);
}
void CMJAntiVirusDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == SC_MINIMIZE )
	{
		this->ShowWindow(SW_HIDE);
		Shell_NotifyIcon(NIM_ADD,&m_traydata);
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}
LRESULT CMJAntiVirusDlg::OnTrayMessage(WPARAM wParam, LPARAM lParam)
{
	if (lParam == WM_LBUTTONDOWN)
	{
		ShowWindow(SW_RESTORE);
	}
	else if (lParam == WM_RBUTTONDOWN)
	{
		CPoint m_point;
		::GetCursorPos(&m_point);
		//this->m_menu.TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, m_point.x,m_point.y,AfxGetApp()->m_pMainWnd,TPM_LEFTALIGN);
		CMenu* m_submenu = this->m_menu.GetSubMenu(0);
		m_submenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, m_point.x,m_point.y,AfxGetApp()->m_pMainWnd,TPM_LEFTALIGN);
	}
	return 0;
}

void CMJAntiVirusDlg::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	m_menu.MeasureItem(lpMeasureItemStruct);	
	//CDialog::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
}

void CMJAntiVirusDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	m_menu.DrawItem(lpDrawItemStruct);
	//CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

void CMJAntiVirusDlg::OnMenuitemRestore() 
{
	// TODO: Add your command handler code here
	Shell_NotifyIcon(NIM_DELETE,&m_traydata);
	ShowWindow(SW_SHOW);
}

void CMJAntiVirusDlg::OnMenuitemClose() 
{
	// TODO: Add your command handler code here
	if(MessageBox("是否退出！！！","提示",MB_ICONWARNING | MB_YESNO)==IDYES)
	{
		Shell_NotifyIcon(NIM_DELETE,&m_traydata);
		this->OnCancel();
	}
}

void CMJAntiVirusDlg::OnMenuitemAbout() 
{
	// TODO: Add your command handler code here
	this->ShowAboutDlg();
}

void CMJAntiVirusDlg::OnMenuitemCmpinfo() 
{
	// TODO: Add your command handler code here
	this->ShowComputerInfoDlg();
}

void CMJAntiVirusDlg::OnMenuitemLock() 
{
	// TODO: Add your command handler code here
	this->ShowLockDlg();
}

void CMJAntiVirusDlg::OnMenuitemNetmoni() 
{
	// TODO: Add your command handler code here
	this->ShowNetMoniDlg();
}

void CMJAntiVirusDlg::OnMenuitemProc() 
{
	// TODO: Add your command handler code here
	this->ExecuProcessView();
}

void CMJAntiVirusDlg::OnMenuitemRegister() 
{
	// TODO: Add your command handler code here
	this->ShowRegDlg();
}

void CMJAntiVirusDlg::OnMenuitemSysmoni() 
{
	// TODO: Add your command handler code here
	this->ShowSysMoniDlg();
}



void CMJAntiVirusDlg::ShowNetMoniDlg()
{
	this->m_netmonidlg.DestroyWindow();
	this->m_netmonidlg.Create(IDD_DLG_NETMONI,this);
	this->m_netmonidlg.ShowWindow(SW_SHOW);
}
void CMJAntiVirusDlg::ShowRegDlg()
{
	this->m_regdlg.DestroyWindow();
	this->m_regdlg.Create(IDD_DLG_REG,this);
	this->m_regdlg.ShowWindow(SW_SHOW);
}

void CMJAntiVirusDlg::StopAgent()
{
	COleVariant iv;
	this->m_AgentEx.StopAll(iv);
	this->m_AgentEx.Play("RestPose");
}

BOOL CMJAntiVirusDlg::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(wParam==0xfff555ee && lParam==0xf55555ee)
	{
 		this->StopAgent();
 		return 0;
 	}
	return CDialog::OnCommand(wParam, lParam);
}
