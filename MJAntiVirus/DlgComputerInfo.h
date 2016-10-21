#if !defined(AFX_DLGCOMPUTERINFO_H__7FEC5CE5_E96F_4DEB_A641_E7E4F0F9B355__INCLUDED_)
#define AFX_DLGCOMPUTERINFO_H__7FEC5CE5_E96F_4DEB_A641_E7E4F0F9B355__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgComputerInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgComputerInfo dialog

class CDlgComputerInfo : public CDialog
{
// Construction
public:
	CDlgComputerInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgComputerInfo)
	enum { IDD = IDD_DLG_COMPUTERINFO };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgComputerInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgComputerInfo)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
struct ComputerInfo
{
	CString computername;
	CString totalmem;
	CString aviliblemen;
	CString aviliblemempersent;
	CString cpuspeed;
	CString sysplatform;
	CString ipaddress;
	CString macaddress;
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCOMPUTERINFO_H__7FEC5CE5_E96F_4DEB_A641_E7E4F0F9B355__INCLUDED_)
