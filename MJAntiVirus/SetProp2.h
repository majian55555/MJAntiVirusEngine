#if !defined(AFX_SETPROP2_H__FE38A36F_8456_401E_8512_4AB570F051D1__INCLUDED_)
#define AFX_SETPROP2_H__FE38A36F_8456_401E_8512_4AB570F051D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetProp2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetProp2 dialog

class CSetProp2 : public CPropertyPage
{
	DECLARE_DYNCREATE(CSetProp2)

// Construction
public:
	CSetProp2();
	~CSetProp2();

// Dialog Data
	//{{AFX_DATA(CSetProp2)
	enum { IDD = IDD_PROP2 };
	CButton	m_prop2_check6;
	CButton	m_prop2_check5;
	CButton	m_prop2_check4;
	CButton	m_prop2_check3;
	CButton	m_prop2_check2;
	CButton	m_prop2_check1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSetProp2)
	public:
	virtual void Serialize(CArchive& ar);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSetProp2)
	afx_msg void OnProp2Check5();
	afx_msg void OnProp2Check6();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETPROP2_H__FE38A36F_8456_401E_8512_4AB570F051D1__INCLUDED_)
