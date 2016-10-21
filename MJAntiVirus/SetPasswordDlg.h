#if !defined(AFX_SETPASSWORDDLG_H__2FC40EB9_3D44_4E1B_8371_79C7EE9A1076__INCLUDED_)
#define AFX_SETPASSWORDDLG_H__2FC40EB9_3D44_4E1B_8371_79C7EE9A1076__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetPasswordDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetPasswordDlg dialog

class CSetPasswordDlg : public CDialog
{
// Construction
public:
	CSetPasswordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetPasswordDlg)
	enum { IDD = IDD_DLG_SETPASSWORD };
	CEdit	m_edt_password;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetPasswordDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetPasswordDlg)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETPASSWORDDLG_H__2FC40EB9_3D44_4E1B_8371_79C7EE9A1076__INCLUDED_)
