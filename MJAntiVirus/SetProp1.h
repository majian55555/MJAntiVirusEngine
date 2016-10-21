#if !defined(AFX_SETPROP1_H__BF23D61D_BD4F_4291_A94F_D56F49ABC21F__INCLUDED_)
#define AFX_SETPROP1_H__BF23D61D_BD4F_4291_A94F_D56F49ABC21F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetProp1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetProp1 dialog

class CSetProp1 : public CPropertyPage
{
	DECLARE_DYNCREATE(CSetProp1)

// Construction
public:
	CSetProp1();
	~CSetProp1();

// Dialog Data
	//{{AFX_DATA(CSetProp1)
	enum { IDD = IDD_PROP1 };
	CButton	m_prop1_check5;
	CButton	m_prop1_check4;
	CButton	m_prop1_check3;
	CButton	m_prop1_check2;
	CButton	m_prop1_check1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSetProp1)
	public:
	virtual void Serialize(CArchive& ar);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSetProp1)
	afx_msg void OnCheck1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETPROP2_H__BC8E3475_2A3E_40FA_98D7_BE8D2C3603E7__INCLUDED_)
