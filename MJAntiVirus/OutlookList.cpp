// OutlookList.cpp : implementation file
//

#include "stdafx.h"
#include "MJAntiVirus.h"
#include "OutlookList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutlookList

COutlookList::COutlookList()
	: m_ButtonHeight (30),m_ButtonCount(0)
{
	m_LeftMargin = 25;
	pItemDlbFun = NULL;
}

COutlookList::~COutlookList()
{
	//m_pButton.RemoveAll();
	int m = m_pButton.GetSize();
	for (int i = 0; i<m_pButton.GetSize();i++)
	{
		((CButton*)m_pButton[i])->DestroyWindow();
		delete ((CButton*)m_pButton[i]);
	}
}

BEGIN_MESSAGE_MAP(COutlookList, CListCtrl)
	//{{AFX_MSG_MAP(COutlookList)
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutlookList message handlers

void COutlookList::AddButton(LPCSTR Btntext,UINT uID)
{
	int index =  m_pButton.Add(new CListButton);
	((CListButton*)m_pButton[m_pButton.GetSize()-1])->Create(Btntext,WS_CHILD,GetAddButtonRect(),this,uID);
	((CListButton*)m_pButton[m_pButton.GetSize()-1])->m_Index = index;
	((CListButton*)m_pButton[m_pButton.GetSize()-1])->ShowWindow(SW_SHOW);
	m_ButtonCount+=1;
}

//获取将要添加按钮的客户区域
CRect COutlookList::GetAddButtonRect()
{
	int count = m_pButton.GetSize();
	int sumheight = 0;
	CRect rect;
	GetClientRect(rect);
	if (count>1)
	{
		CRect rect1;
		for (int m=0; m<count-1;m++)
		{
			((CListButton*)m_pButton[m])->GetClientRect(rect1);
			sumheight+=rect1.Height();
		}
		return CRect(0,sumheight,rect.Width(),sumheight+m_ButtonHeight);		
	}
	else
		return CRect(0,0,rect.Width(),m_ButtonHeight);
}

int COutlookList::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CListCtrl::OnCreate(lpCreateStruct) == -1)
	{
		return -1;
	}		
	return 0;
}

void COutlookList::PreSubclassWindow() 
{
	CListCtrl::PreSubclassWindow();
	m_ClientList.Create(LVS_ICON,CRect(0,0,0,0),this,101);
	
	//m_ClientList.MoveWindow(GetListClientRect());
	m_ClientList.ShowWindow(SW_SHOW);

	m_ClientList.SetExtendedStyle(LVS_EX_FLATSB);

	m_ClientList.SetBkColor(RGB(192,192,192));

	m_ClientList.SetTextBkColor(RGB(192,192,192));
	m_ClientList.SetTextColor(RGB(0,0,255));

	m_ClientList.Arrange(LVA_ALIGNLEFT );

}

BOOL COutlookList::PreTranslateMessage(MSG* pMsg) 
{	
	if ((pMsg->hwnd==m_ClientList.m_hWnd)&&(pMsg->message==WM_LBUTTONDBLCLK))
	{
		int index;
		index = m_ClientList.GetSelectionMark();
		if (pItemDlbFun!= NULL)
			pItemDlbFun(&m_ClientList,index);
	}
	return CListCtrl::PreTranslateMessage(pMsg);
}

BOOL COutlookList::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	int index =  CommandToIndex(nID);
	if (index != -1)
	{
		OnButtonDown(index,nID);
	}
	m_ClientList.OnCmdMsg(nID,nCode,pExtra,pHandlerInfo);
	return CListCtrl::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

//按钮的单击处理
void COutlookList::OnButtonDown(UINT bIndex, UINT nID)
{
	CRect listrect,buttonrect;
	int height = 0;
	
	CListButton* temp;
	GetClientRect(listrect);
	if (m_ButtonCount!=1)
	{	
		temp = (CListButton*)m_pButton[bIndex];
		if (temp->m_Toped) //用户单击顶层按钮
		{
			for (unsigned int i= m_ButtonCount-1; i>bIndex;i--)
			{
				temp = (CListButton*)m_pButton[i];
				temp->GetClientRect(buttonrect);			
				CRect rect(0,listrect.bottom-buttonrect.Height()-height,buttonrect.Width(),listrect.bottom-height);				
				height+= buttonrect.Height();
				temp->MoveWindow(rect);
				temp->m_Toped = FALSE;
			}			
		}
		else //用于单击底层按钮
		{
			int bottomindex = GetBtmTopIndex();
			for (unsigned int i = bottomindex; i <=bIndex;i++)
			{
				int topheight = GetTopButtonHeight();//获取顶层按钮高度

				temp = (CListButton*)m_pButton[i];
				temp->GetClientRect(buttonrect);

				CRect rect(0,topheight,buttonrect.Width(),topheight+buttonrect.Height());
				temp->MoveWindow(rect);
				temp->m_Toped = TRUE;			
			}
		}
		CRect rectclt =GetListClientRect();
		m_ClientList.MoveWindow(rectclt);
		ShowButtonItems(bIndex);
	}	
}

//根据按钮命令返回索引
UINT COutlookList::CommandToIndex(UINT nID)
{
	for (int i = 0;i< m_pButton.GetSize();i++)
	{
		if ((unsigned int)((CListButton*)m_pButton[i])->GetDlgCtrlID()==nID)
		{
			return ((CListButton*)m_pButton[i])->m_Index;
		}
	}
	return -1;
}

//返回顶层按钮的高度
UINT COutlookList::GetTopButtonHeight()
{
	UINT result = 0;
	CListButton* temp;
	CRect rect;
	for (unsigned int i = 0; i< m_ButtonCount;i++)
	{
		temp = (CListButton*)m_pButton[i];
		if (temp->m_Toped)
		{
			temp->GetClientRect(rect);
			result += rect.Height();
		}
	}
	return result;
}

UINT COutlookList::GetBtmBtnHeight()
{
	UINT result = 0;
	CListButton* temp;
	CRect rect;
	for (unsigned int i = 0; i< m_ButtonCount;i++)
	{
		temp = (CListButton*)m_pButton[i];
		if (temp->m_Toped==FALSE)
		{
			temp->GetClientRect(rect);
			result += rect.Height();
		}
	}
	return result;
}


//获取当前底层按钮到其上方的底层按钮的数量
UINT COutlookList::GetNumCurToBtmBtn(UINT nIndex)
{
	UINT result = 0;
	CListButton* temp;
	for (unsigned int i = 0; i<nIndex;i++)
	{
		temp = (CListButton*)m_pButton[i];		
		if (temp->m_Toped==FALSE)
			result+=1;
	}
	return (result);
}

//获取下方按钮的顶层索引
int COutlookList::GetBtmTopIndex()
{
	CListButton* temp;
	for (unsigned int i = 0; i<m_ButtonCount;i++)
	{
		temp = (CListButton*)m_pButton[i];		
		if (temp->m_Toped==FALSE)
			return i;
	}
	return -1;	
}


CRect COutlookList::GetListClientRect()
{
	int TopHeight = GetTopButtonHeight(); //获取上方按钮的高度
	int BtmHeight = GetBtmBtnHeight();	//获取下方按钮的高度
	
	CRect rect;
	GetClientRect(rect); //获取列表总的客户区域

	CRect ClientRect(0,TopHeight,rect.Width(),rect.Height()-BtmHeight);
	return ClientRect;

}

void COutlookList::AddButtonItems(UINT nIndex, CString &strItem)
{
	CListButton* temp;
	temp = (CListButton*)m_pButton[nIndex];

	temp->m_ButtonItems.AddTail(strItem);
}

//显示指定按钮关联的列表视图项
void COutlookList::ShowButtonItems(UINT nIndex)
{
	CListButton* temp;
	temp = (CListButton*)m_pButton[nIndex];
	m_ClientList.DeleteAllItems();

	CRect showrect = GetListClientRect();

	if (temp->m_ButtonItems.GetCount()>0)
	{
		POSITION pos;
		pos = temp->m_ButtonItems.GetHeadPosition();
		CString str= temp->m_ButtonItems.GetHead();
		CRect ClientRect;
		ClientRect= GetListClientRect();
		int m = 0;

		m_ClientList.InsertItem(m,str,m);
		m_ClientList.SetItemPosition(m,CPoint(m_LeftMargin,25+m*70));

		while (pos != temp->m_ButtonItems.GetTailPosition())
		{

			str = temp->m_ButtonItems.GetNext(pos);
			m_ClientList.InsertItem(m,str,m);
			m_ClientList.SetItemPosition(m,CPoint(m_LeftMargin,25+m*70));
			m+=1;
		}
		str = temp->m_ButtonItems.GetAt(pos);
		m_ClientList.InsertItem(m,str,m);
		m_ClientList.SetItemPosition(m,CPoint(m_LeftMargin,25+m*70));
	}
}

void COutlookList::SetImageLists(CImageList *pImagelist)
{
	if (pImagelist)
		m_ClientList.SetImageList(pImagelist,LVSIL_NORMAL);
}

void COutlookList::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	*pResult = 0;
}
