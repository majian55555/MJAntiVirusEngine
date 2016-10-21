#if !defined(AFX_SREENPROTECTDLG_H__ADAD436F_1E6E_452F_B2B1_CCCFAF7F0402__INCLUDED_)
#define AFX_SREENPROTECTDLG_H__ADAD436F_1E6E_452F_B2B1_CCCFAF7F0402__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SreenProtectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSreenProtectDlg dialog
struct SMyScreen
{
	CPoint curpt;
	int x;
	int y;
	int idirect;
	int a;
	int b;
	int m_nIndexBit;
	CClientDC* dc;
};
class CSreenProtectDlg : public CDialog
{
// Construction
public:
	CSreenProtectDlg(CWnd* pParent = NULL);   // standard constructor
	static DWORD WINAPI DrawBitmap(LPVOID);
// Dialog Data
	//{{AFX_DATA(CSreenProtectDlg)
	enum { IDD = IDD_DLG_SCREENPROTECT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSreenProtectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSreenProtectDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnClose();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	SMyScreen* m_mystruct;
	HANDLE thread_screen;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SREENPROTECTDLG_H__ADAD436F_1E6E_452F_B2B1_CCCFAF7F0402__INCLUDED_)
