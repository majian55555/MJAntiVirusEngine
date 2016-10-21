#if !defined(AFX_FILEENCRYDLG_H__929D5D55_DCEB_4168_9177_920123ABB528__INCLUDED_)
#define AFX_FILEENCRYDLG_H__929D5D55_DCEB_4168_9177_920123ABB528__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileEncryDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFileEncryDlg dialog

class CFileEncryDlg : public CDialog
{
// Construction
public:
	CFileEncryDlg(CWnd* pParent = NULL);   // standard constructor
	CString strpathtemp;
// Dialog Data
	//{{AFX_DATA(CFileEncryDlg)
	enum { IDD = IDD_FILEENCRY_DIALOG };
	CStatic	m_filepath;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileEncryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFileEncryDlg)
	afx_msg void OnBtopen();
	afx_msg void OnBtencry();
	afx_msg void OnBtunencry();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEENCRYDLG_H__929D5D55_DCEB_4168_9177_920123ABB528__INCLUDED_)
