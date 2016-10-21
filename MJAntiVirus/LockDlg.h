#if !defined(AFX_LOCKDLG_H__CAD9A003_786C_458A_B2A6_8D343AA23551__INCLUDED_)
#define AFX_LOCKDLG_H__CAD9A003_786C_458A_B2A6_8D343AA23551__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LockDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLockDlg dialog
#include "SreenProtectDlg.h"
class CLockDlg : public CDialog
{
// Construction
public:
	CSreenProtectDlg m_screenprotectdlg;
	CLockDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLockDlg)
	enum { IDD = IDD_LOCK_DLG };
	CEdit	m_password;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLockDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLockDlg)
	afx_msg void OnLockBtn1();
	virtual BOOL OnInitDialog();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLockBtnScreen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOCKDLG_H__CAD9A003_786C_458A_B2A6_8D343AA23551__INCLUDED_)
