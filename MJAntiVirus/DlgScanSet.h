#if !defined(AFX_DLGSCANSET_H__0BB56AF9_C36F_4C62_A1EF_4E9A2418B48C__INCLUDED_)
#define AFX_DLGSCANSET_H__0BB56AF9_C36F_4C62_A1EF_4E9A2418B48C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgScanSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgScanSet dialog

class CDlgScanSet : public CDialog
{
// Construction
public:
	CDlgScanSet();   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgScanSet)
	enum { IDD = IDD_DLG_SCANSET };
	int		m_scanmode;
	int		m_scanspeed;
	int		m_memfirstornot;
	int		m_turnoffornot;
	int		m_scanfile;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgScanSet)
	public:
	virtual void Serialize(CArchive& ar);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgScanSet)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnScansetok();
	afx_msg void OnBtnScansetcancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSCANSET_H__0BB56AF9_C36F_4C62_A1EF_4E9A2418B48C__INCLUDED_)
