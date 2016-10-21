#if !defined(AFX_REGDLG_H__62109C2E_C7C3_4C12_8AE0_8755C19D8196__INCLUDED_)
#define AFX_REGDLG_H__62109C2E_C7C3_4C12_8AE0_8755C19D8196__INCLUDED_
#include "Mysocket.h"
#include "Resource.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RegDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRegDlg dialog
class CMysocket;
class CRegDlg : public CDialog
{
// Construction
public:
	void ReceiveData(void);
	CRegDlg(CWnd* pParent = NULL);   // standard constructor
	CMysocket* pMysocket;
// Dialog Data
	//{{AFX_DATA(CRegDlg)
	enum { IDD = IDD_DLG_REG };
	CStatic	m_lab_regstate;
	CEdit	m_edit_regcode;
	CButton	m_btn_reg;
	CButton	m_btn_quitreg;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRegDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnReg();
	afx_msg void OnBtnQuitreg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString RegisterProgram();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGDLG_H__62109C2E_C7C3_4C12_8AE0_8755C19D8196__INCLUDED_)
