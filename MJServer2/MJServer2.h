// MJServer2.h : main header file for the MJSERVER2 application
//

#if !defined(AFX_MJSERVER2_H__17578E5C_DEB6_45FA_9D74_CF0FD8868BFC__INCLUDED_)
#define AFX_MJSERVER2_H__17578E5C_DEB6_45FA_9D74_CF0FD8868BFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMJServer2App:
// See MJServer2.cpp for the implementation of this class
//

class CMJServer2App : public CWinApp
{
public:
	CMJServer2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMJServer2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMJServer2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MJSERVER2_H__17578E5C_DEB6_45FA_9D74_CF0FD8868BFC__INCLUDED_)
