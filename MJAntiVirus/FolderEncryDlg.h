#if !defined(AFX_FOLDERENCRYDLG_H__F193C0EB_375F_4E25_9C38_7A8933020063__INCLUDED_)
#define AFX_FOLDERENCRYDLG_H__F193C0EB_375F_4E25_9C38_7A8933020063__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FolderEncryDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFolderEncryDlg dialog

class CFolderEncryDlg : public CDialog
{
// Construction
public:
	CFolderEncryDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFolderEncryDlg)
	enum { IDD = IDD_FOLDERENCRY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFolderEncryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFolderEncryDlg)
	afx_msg void OnAdd();
	afx_msg void OnBtencry();
	afx_msg void OnBtunencry();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FOLDERENCRYDLG_H__F193C0EB_375F_4E25_9C38_7A8933020063__INCLUDED_)
