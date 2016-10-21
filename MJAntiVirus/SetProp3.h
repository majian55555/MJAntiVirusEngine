#if !defined(AFX_SETPROP3_H__A5DBC919_B6DB_431B_A161_F9581A728853__INCLUDED_)
#define AFX_SETPROP3_H__A5DBC919_B6DB_431B_A161_F9581A728853__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetProp3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetProp3 dialog

class CSetProp3 : public CPropertyPage
{
	DECLARE_DYNCREATE(CSetProp3)

// Construction
public:
	CSetProp3();
	~CSetProp3();

// Dialog Data
	//{{AFX_DATA(CSetProp3)
	enum { IDD = IDD_PROP3 };
	CButton	m_prop3_check4;
	CButton	m_prop3_check3;
	CButton	m_prop3_check2;
	CButton	m_prop3_check1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSetProp3)
	public:
	virtual void Serialize(CArchive& ar);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSetProp3)
	afx_msg void OnProp3Check1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETPROP3_H__A5DBC919_B6DB_431B_A161_F9581A728853__INCLUDED_)
