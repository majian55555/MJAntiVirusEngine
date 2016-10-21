#if !defined(AFX_NETMONIDLG_H__7A256F62_D7DB_4221_97F3_109FAFB1AB47__INCLUDED_)
#define AFX_NETMONIDLG_H__7A256F62_D7DB_4221_97F3_109FAFB1AB47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NetMoniDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNetMoniDlg dialog
#define SIO_RCVALL            _WSAIOW(IOC_VENDOR,1)
#define SIO_RCVALL_MCAST      _WSAIOW(IOC_VENDOR,2)
#define SIO_RCVALL_IGMPMCAST  _WSAIOW(IOC_VENDOR,3)
#define SIO_KEEPALIVE_VALS    _WSAIOW(IOC_VENDOR,4)
#define SIO_ABSORB_RTRALERT   _WSAIOW(IOC_VENDOR,5)
#define SIO_UCAST_IF          _WSAIOW(IOC_VENDOR,6)
#define SIO_LIMIT_BROADCASTS  _WSAIOW(IOC_VENDOR,7)
#define SIO_INDEX_BIND        _WSAIOW(IOC_VENDOR,8)
#define SIO_INDEX_MCASTIF     _WSAIOW(IOC_VENDOR,9)
#define SIO_INDEX_ADD_MCAST   _WSAIOW(IOC_VENDOR,10)
#define SIO_INDEX_DEL_MCAST   _WSAIOW(IOC_VENDOR,11)


//定义Ip数据报头结构,20个字节
typedef struct HeadIP
{
	unsigned char  headerlen:4;  //首部长度,占4位
	unsigned char  version:4;    //版本,占4位 
	unsigned char  servertype;   //服务类型,占8位,即1个字节
	unsigned short totallen;     //总长度,占16位
	unsigned short id;           //与idoff构成标识 ,共占16位,前3位是标识,后13位是片偏移
	unsigned short idoff;        
	unsigned char  ttl;          //生存时间 ,占8位         
	unsigned char  proto;        //协议,占8位   
	unsigned short checksum;     //首部检验和,占16位  
	unsigned int   sourceIP;     //源IP地址,占32位
	unsigned int   destIP;       //目的IP地址,占32位
}HEADIP;

//定义TCP数据报首部
typedef struct HeadTCP
{
	WORD   SourcePort;    //16位源端口号
	WORD   DePort;        //16位目的端口
	DWORD  SequenceNo;    //32位序号
	DWORD  ConfirmNo;     //32位确认序号
	BYTE   HeadLen;       //与Flag为一个组成部分, 首部长度,占4位,保留6位,6位标识,共16位   
	BYTE   Flag;
	WORD   WndSize;       //16位窗口大小
	WORD   CheckSum;      //16位校验和
	WORD   UrgPtr;        //16位紧急指针
} HEADTCP;

//定义UDP数据报首部
typedef struct HeadUDP
{
	WORD SourcePort;  //16位源端口号
	WORD DePort;      //16位目的端口
	WORD Len;         //16为UDP长度
	WORD ChkSum;      //16位UDP校验和
} HEADUDP;


//定义ICMP数据报首部
typedef struct HeadICMP
{
	BYTE Type;    //8位类型
	BYTE Code;    //8位代码
	WORD ChkSum;  //16位校验和
} HEADICMP;

//定义协议名称
struct  PROTONAME
{
	int  value;
	char* protoname;  
};

class CNetMoniDlg : public CDialog
{
// Construction
public:
	CNetMoniDlg(CWnd* pParent = NULL);   // standard constructor
	SOCKET       m_Sock;
	CWinThread*  m_pThread;
	static UINT ThreadFun(LPVOID pParam);
	static char* get_protoname(int protoID);
// Dialog Data
	//{{AFX_DATA(CNetMoniDlg)
	enum { IDD = IDD_DLG_NETMONI };
	CButton	m_btn_cancel;
	CButton	m_btn_beginlisten;
	CListCtrl	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetMoniDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNetMoniDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnBeginlisten();
	afx_msg void OnBtnCancel();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETMONIDLG_H__7A256F62_D7DB_4221_97F3_109FAFB1AB47__INCLUDED_)
