#if !defined(AFX_SETPROPSHEET_H__11E53993_1E42_4A65_AFC6_3C504E789A7E__INCLUDED_)
#define AFX_SETPROPSHEET_H__11E53993_1E42_4A65_AFC6_3C504E789A7E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetPropSheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetPropSheet
#include "SetProp1.h"
#include "SetProp2.h"
#include "SetProp3.h"
class CSetPropSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSetPropSheet)

// Construction
public:
	CSetPropSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CSetPropSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetPropSheet)
	public:
	virtual BOOL OnInitDialog();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CButton m_btn_cancel;
	CButton m_btn_ok;
	CSetProp1 m_setprop1;
	CSetProp2 m_setprop2;
	CSetProp3 m_setprop3;
	virtual ~CSetPropSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSetPropSheet)
	afx_msg void OnBtn_Ok();
	afx_msg void OnBtn_Cancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETPROPSHEET_H__11E53993_1E42_4A65_AFC6_3C504E789A7E__INCLUDED_)
