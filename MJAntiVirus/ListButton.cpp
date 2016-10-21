// ListButton.cpp : implementation file
//

#include "stdafx.h"
#include "MJAntiVirus.h"
#include "ListButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListButton

CListButton::CListButton()
	: m_Toped (TRUE)
{
}

CListButton::~CListButton()
{
}


BEGIN_MESSAGE_MAP(CListButton, CButton)
	//{{AFX_MSG_MAP(CListButton)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListButton message handlers
