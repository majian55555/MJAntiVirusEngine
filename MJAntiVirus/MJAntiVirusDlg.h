// MJAntiVirusDlg.h : header file
//
//{{AFX_INCLUDES()
#include "agentctlex.h"
//}}AFX_INCLUDES

#if !defined(AFX_MJANTIVIRUSDLG_H__FC15F0B0_3AFB_4C61_9521_86CB1DC3B0C5__INCLUDED_)
#define AFX_MJANTIVIRUSDLG_H__FC15F0B0_3AFB_4C61_9521_86CB1DC3B0C5__INCLUDED_

#include "OutlookList.h"	// Added by ClassView
#include "DlgScanSet.h"	// Added by ClassView
#include "SetPropSheet.h"	// Added by ClassView
#include "DlgComputerInfo.h"	// Added by ClassView
#include "LockOrSetDlg.h"	// Added by ClassView
#include "SysMoniDlg.h"
#include "FileEncryDlg.h"	// Added by ClassView
#include "FolderEncryDlg.h"	// Added by ClassView
#include "MJAntiVirusAboutDlg.h"	// Added by ClassView
#include "Label.h"
#include "IconMenu.h"
#include "RegDlg.h"
#include "NetMoniDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "agentctlcharacters.h"
#include "agentctlcharacterex.h"
#include "agentctlrequest.h"
/////////////////////////////////////////////////////////////////////////////
// CMJAntiVirusDlg dialog
struct ScanSet
{
	int memfirst;
	int scanfile;
	int scanmode;
	int scanspeed;
	int turnoff;
};
class CMJAntiVirusDlg : public CDialog
{
// Construction
public:
	void StopAgent();
	void ShowRegDlg(void);
	void ShowNetMoniDlg(void);
	NOTIFYICONDATA m_traydata;
	void ShowAboutDlg(void);
	void ShowFolderEncryDlg(void);
	void ShowFileEncryDlg(void);
	void ShowSysMoniDlg(void);
	HCURSOR m_mycursor;
	HCURSOR m_oldcursor;
	void ShowLockDlg(void);
	void ExecuProcessView(void);
	CStringArray* FindProcessFilePath(void);
	ScanSet m_scanset;
	void ShowComputerInfoDlg();
	void ShowSetDlg();
	CSetPropSheet* m_setpropsheet;
	CImageList m_imagelistforicon;
	void ShowScanSetDlg();
	static DWORD WINAPI Fun_findfile(LPVOID);
	static DWORD WINAPI Fun_time(LPVOID);
	static DWORD WINAPI Fun_mycomputer(LPVOID);
	void FindFile(CString fname);
	void static OnItemDouble(const CListCtrl* pListCtrl,int nIndex);
	CMJAntiVirusDlg(CWnd* pParent = NULL);	// standard constructor
	CTimeSpan m_time;
	HANDLE thread_time;
	HANDLE thread_findfile;
	HANDLE thread_mycomputer;
	CAgentCtlCharacters m_AgentCharacters;
	CAgentCtlCharacterEx m_AgentEx;
	CAgentCtlRequest m_AgentRequest;
	void DrawGradient(HDC pDC,const RECT& rect,COLORREF begin, COLORREF end, const int &width);
// Dialog Data
	//{{AFX_DATA(CMJAntiVirusDlg)
	enum { IDD = IDD_MJANTIVIRUS_DIALOG };
	CListCtrl	m_list_seleicon;
	CEdit	m_lb_filenum;
	CListCtrl	m_list_showresult;
	CButton	m_btn_stop;
	CButton	m_btn_pause;
	CEdit	m_edit_time;
	CButton	m_btn_start;
	CStatic	m_lb_showf;
	CTreeCtrl	m_trdisktree;
	COutlookList	m_List;
	CAgentCtlEx	m_agent;
	//}}AFX_DATA
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMJAntiVirusDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL
// Implementation
protected:
	CIconMenu m_menu;
	CImageList m_Imagelist;
	HICON m_hIcon;
	CImageList m_imagelist;
	int m_imindex;
	SHFILEINFO m_fileinfo;
	CString m_treetrace;
	
	// Generated message map functions
	//{{AFX_MSG(CMJAntiVirusDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg LRESULT OnTrayMessage(WPARAM wParam, LPARAM lParam);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangedTrdisktree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtnStart();
	afx_msg void OnClickTrdisktree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtnPause();
	afx_msg void OnBtnStop();
	afx_msg void OnClose();
	afx_msg void OnMenuitemRestore();
	afx_msg void OnMenuitemClose();
	afx_msg void OnMenuitemAbout();
	afx_msg void OnMenuitemCmpinfo();
	afx_msg void OnMenuitemLock();
	afx_msg void OnMenuitemNetmoni();
	afx_msg void OnMenuitemProc();
	afx_msg void OnMenuitemRegister();
	afx_msg void OnMenuitemSysmoni();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CNetMoniDlg m_netmonidlg;
	CMJAntiVirusAboutDlg m_aboutdlg;
	CFolderEncryDlg m_folderencrydlg;
	CObArray m_VArray;
	CString CmpWithVS(CString);
	static void RecursiveDiskTree(HTREEITEM);
	CString RecursiveFileName(HTREEITEM);
	void RecursiveDiskTreeCheck(HTREEITEM,BOOL);
	CString m_FileName;
	CToolBar m_ToolBar;
	int m_findfilenum;
	int m_findvirusnum;
	int m_killvirusnum;
	CLockOrSetDlg m_locksetdlg;
	CSysMoniDlg m_sysmonidlg;
	CDlgScanSet m_ScanSetDlg;
	CFileEncryDlg m_fileencrydlg;
	CDlgComputerInfo m_dlg_computerinfo;
	CRegDlg m_regdlg;
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MJANTIVIRUSDLG_H__FC15F0B0_3AFB_4C61_9521_86CB1DC3B0C5__INCLUDED_)
