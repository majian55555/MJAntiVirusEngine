// ServerSocket.cpp : implementation file
//

#include "stdafx.h"
#include "MJServer2.h"
#include "ServerSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerSocket

CServerSocket::CServerSocket(CMJServer2Dlg* dlg)
{
	m_pDlg = dlg;
}

CServerSocket::~CServerSocket()
{

	m_pDlg = NULL;
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CServerSocket, CSocket)
	//{{AFX_MSG_MAP(CServerSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CServerSocket member functions

void CServerSocket::OnAccept(int nErrorCode) 
{
	CSocket::OnAccept(nErrorCode);
	if (m_pDlg)
		m_pDlg->AcceptConnect();
}
