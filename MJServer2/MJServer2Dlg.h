// MJServer2Dlg.h : header file
//

#if !defined(AFX_MJSERVER2DLG_H__9E7D1491_9958_4570_88A3_3DBA0BD3BC72__INCLUDED_)
#define AFX_MJSERVER2DLG_H__9E7D1491_9958_4570_88A3_3DBA0BD3BC72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ServerSocket.h"
#include "ClientSocket.h"
const int BUFFERSIZE = 200;
/////////////////////////////////////////////////////////////////////////////
// CMJServer2Dlg dialog
class CServerSocket;
class CClientSocket;
class CMJServer2Dlg : public CDialog
{
// Construction
public:
	CMJServer2Dlg(CWnd* pParent = NULL);	// standard constructor
	void ReceiveData(CClientSocket* socket);
	void AcceptConnect();
	CServerSocket* m_pSocket;
	CClientSocket* m_pClient;
	CPtrList m_socketlist;
// Dialog Data
	//{{AFX_DATA(CMJServer2Dlg)
	enum { IDD = IDD_MJSERVER2_DIALOG };
	CButton	m_btn_listen;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMJServer2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMJServer2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnListen();
	afx_msg void OnBtnCreatefile();
	afx_msg void OnBtnCreatefile2();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL Register(CString);
	BOOL FindRegMachine(CString);
	BOOL FindRegCode(CString);
	CString Carlugate(CString);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MJSERVER2DLG_H__9E7D1491_9958_4570_88A3_3DBA0BD3BC72__INCLUDED_)
