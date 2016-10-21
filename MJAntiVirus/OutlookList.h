#if !defined(AFX_OUTINTERFACEDLG_H__0D6A438A_04F2_41CC_8F5E_00046FA0C248__INCLUDED_)
#define AFX_OUTINTERFACEDLG_H__0D6A438A_04F2_41CC_8F5E_00046FA0C248__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OutlookList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COutlookList window
#include "ListButton.h"
#define LISTID = 2010;

//定义双击列表视图项的回调函数
typedef void(ItemDlbFun)(const CListCtrl* pListCtrl,int nItemIndex);

class COutlookList : public CListCtrl
{
// Construction
public:
	COutlookList();
	CPtrArray m_pButton; //按钮数组
	UINT m_ButtonCount ; //按钮数量
	UINT m_LeftMargin; //图像列表显示的左边距
	CListCtrl m_ClientList; //在客户区域显示视图项
	ItemDlbFun* pItemDlbFun; //视图项的双击事件
// Attributes
public:

// Operations

private:
	UINT m_ButtonHeight; //按钮高度
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutlookList)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetImageLists(CImageList* pImagelist);
	void ShowButtonItems(UINT nIndex);
	void AddButtonItems(UINT nIndex,CString& strItem);
	UINT GetBtmBtnHeight();
	CRect GetListClientRect();
	int GetBtmTopIndex();
	UINT GetNumCurToBtmBtn(UINT nIndex);
	UINT GetTopButtonHeight();
	UINT CommandToIndex(UINT nID);
	void OnButtonDown(UINT bIndex, UINT nID);
	CRect GetAddButtonRect();
	void AddButton(LPCSTR text,UINT uID);
	virtual ~COutlookList();

	// Generated message map functions
protected:
	//{{AFX_MSG(COutlookList)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTLOOKLIST_H__C190DC04_038D_4AB9_994F_804C7DCB9E28__INCLUDED_)
