#if !defined(AFX_MYSOCKET_H__64112455_83A8_485C_B86E_04732403BD9C__INCLUDED_)
#define AFX_MYSOCKET_H__64112455_83A8_485C_B86E_04732403BD9C__INCLUDED_
#include "RegDlg.h"
#include "Afxsock.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Mysocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CMysocket command target
class CRegDlg ;
class CMysocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CMysocket(CRegDlg* pDlg);
	virtual ~CMysocket();
	CRegDlg* pClientdlg;
// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMysocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMysocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSOCKET_H__64112455_83A8_485C_B86E_04732403BD9C__INCLUDED_)
