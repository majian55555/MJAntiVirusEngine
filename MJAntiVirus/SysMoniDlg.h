#if !defined(AFX_SYSMONIDLG_H__6CE6F01C_84AB_4F9F_A74B_E62EC955368C__INCLUDED_)
#define AFX_SYSMONIDLG_H__6CE6F01C_84AB_4F9F_A74B_E62EC955368C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SysMoniDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSysMoniDlg dialog

class CSysMoniDlg : public CDialog
{
// Construction
public:
	CString m_szi;
	CString m_strWatchedDir;
	BOOL StartWatch(CString path);
	CSysMoniDlg(CWnd* pParent = NULL);   // standard constructor
	BOOL	m_bAddNew0;
	BOOL	m_bDel0;
	BOOL	m_bRename0;
	BOOL	m_bModify0;
	BOOL	m_bOther0;
	int m_i;
// Dialog Data
	//{{AFX_DATA(CSysMoniDlg)
	enum { IDD = IDD_DLG_MONITORFILE };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSysMoniDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSysMoniDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnStart();
	afx_msg void OnStop();
	afx_msg void OnClear();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HANDLE m_hThread;
	HANDLE hDir;
	static DWORD WINAPI ThreadProc_SysMoni( LPVOID lParam ) ;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSMONIDLG_H__6CE6F01C_84AB_4F9F_A74B_E62EC955368C__INCLUDED_)
