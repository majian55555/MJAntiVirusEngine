#if !defined(AFX_SERVERSOCKET_H__D710DFF9_F8BD_4F9F_8EF7_48A4700EAB36__INCLUDED_)
#define AFX_SERVERSOCKET_H__D710DFF9_F8BD_4F9F_8EF7_48A4700EAB36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ServerSocket.h : header file
//

#include "MJServer2Dlg.h"
#include "afxsock.h"

/////////////////////////////////////////////////////////////////////////////
// CServerSocket command target
class CMJServer2Dlg;
class CServerSocket : public CSocket
{
// Attributes
public:
	CMJServer2Dlg* m_pDlg;
// Operations
public:
	CServerSocket(CMJServer2Dlg* dlg);
	virtual ~CServerSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CServerSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERSOCKET_H__D710DFF9_F8BD_4F9F_8EF7_48A4700EAB36__INCLUDED_)
