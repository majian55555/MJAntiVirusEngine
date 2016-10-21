#if !defined(AFX_MJANTIVIRUSABOUTDLG_H__D54DA183_664E_445E_BE34_0B0A6B386E0D__INCLUDED_)
#define AFX_MJANTIVIRUSABOUTDLG_H__D54DA183_664E_445E_BE34_0B0A6B386E0D__INCLUDED_
#include "Label.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MJAntiVirusAboutDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMJAntiVirusAboutDlg dialog

class CMJAntiVirusAboutDlg : public CDialog
{
// Construction
public:
	CMJAntiVirusAboutDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMJAntiVirusAboutDlg)
	enum { IDD = IDD_ABOUT_DIALOG };
	CLabel	m_label6;
	CLabel	m_label5;
	CLabel	m_label4;
	CLabel	m_label3;
	CLabel	m_label2;
	CLabel	m_label1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMJAntiVirusAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMJAntiVirusAboutDlg)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MJANTIVIRUSABOUTDLG_H__D54DA183_664E_445E_BE34_0B0A6B386E0D__INCLUDED_)
