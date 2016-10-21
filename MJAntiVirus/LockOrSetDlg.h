#if !defined(AFX_LOCKORSETDLG_H__93DE0071_EFA9_4B07_B307_AF47ADA52BE9__INCLUDED_)
#define AFX_LOCKORSETDLG_H__93DE0071_EFA9_4B07_B307_AF47ADA52BE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LockOrSetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLockOrSetDlg dialog

class CLockOrSetDlg : public CDialog
{
// Construction
public:
	CLockOrSetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLockOrSetDlg)
	enum { IDD = IDD_DLG_LOCKORSET };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLockOrSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLockOrSetDlg)
	afx_msg void OnBtnSetcode();
	afx_msg void OnBtnLockcpt();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOCKORSETDLG_H__93DE0071_EFA9_4B07_B307_AF47ADA52BE9__INCLUDED_)
