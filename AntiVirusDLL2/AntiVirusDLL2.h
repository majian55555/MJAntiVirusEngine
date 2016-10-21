// AntiVirusDLL2.h : main header file for the ANTIVIRUSDLL2 DLL
//

#if !defined(AFX_ANTIVIRUSDLL2_H__806A8451_0EC3_47FD_94B2_54E30288ADFD__INCLUDED_)
#define AFX_ANTIVIRUSDLL2_H__806A8451_0EC3_47FD_94B2_54E30288ADFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include <afxsock.h>
#include <nb30.h>
/////////////////////////////////////////////////////////////////////////////
// CAntiVirusDLL2App
// See AntiVirusDLL2.cpp for the implementation of this class
//

class CAntiVirusDLL2App : public CWinApp
{
public:
	CAntiVirusDLL2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAntiVirusDLL2App)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CAntiVirusDLL2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
struct ComputerInfo
{
	CString computername;
	CString totalmem;
	CString aviliblemen;
	CString aviliblemempersent;
	CString cpuspeed;
	CString sysplatform;
	CString ipaddress;
	CString macaddress;
};
typedef struct
{
	unsigned long in_cycles;	// Internal clock cycles during
								//   test
	unsigned long ex_ticks;		// Microseconds elapsed during 
								//   test
	unsigned long raw_freq;		// Raw frequency of CPU in MHz

	unsigned long norm_freq;	// Normalized frequency of CPU
								//   in MHz.
}FREQ_INFO;
typedef struct
{
    ADAPTER_STATUS adapt;
    NAME_BUFFER NameBuff[ 30 ];
}ASTAT,*PASTAT;


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANTIVIRUSDLL2_H__806A8451_0EC3_47FD_94B2_54E30288ADFD__INCLUDED_)
