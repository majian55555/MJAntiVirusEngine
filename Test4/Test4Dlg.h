// Test4Dlg.h : header file
//

#if !defined(AFX_TEST4DLG_H__4213E673_8A61_4355_8828_A84450671763__INCLUDED_)
#define AFX_TEST4DLG_H__4213E673_8A61_4355_8828_A84450671763__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest4Dlg dialog

class CTest4Dlg : public CDialog
{
// Construction
public:
	CTest4Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest4Dlg)
	enum { IDD = IDD_TEST4_DIALOG };
	CEdit	m_edit1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest4Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest4Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST4DLG_H__4213E673_8A61_4355_8828_A84450671763__INCLUDED_)
