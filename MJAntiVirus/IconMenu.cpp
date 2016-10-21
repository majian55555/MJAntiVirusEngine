// IconMenu1.cpp: implementation of the CIconMenu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IconMenu.h"
#include "mjantivirus.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIconMenu::CIconMenu()
{
	m_index= 0;
	m_iconindex= 0;
	m_save = 0;
	m_isdrawtitle = TRUE;
	m_titlefont.CreateFont(-14,-8,900,0,FW_BOLD,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_MODERN,"华文细黑");
	//创建图像列表
}

CIconMenu::~CIconMenu()
{
//	m_imagelist.Detach();
}

BOOL  CIconMenu::AttatchMenu(HMENU m_hmenu)
{
	this->Attach(m_hmenu);
	return TRUE;

}

BOOL CIconMenu::ChangeMenuItem(CMenu* m_menu,BOOL m_Toped)
{
	if (m_menu != NULL)
	{
		int m_itemcount = m_menu->GetMenuItemCount();
		for (int i=0;i<m_itemcount;i++)
		{
			m_menu->GetMenuString(i,m_ItemLists[m_index].m_ItemText,MF_BYPOSITION);
			int m_itemID = m_menu->GetMenuItemID(i);
			if (m_itemID==-1 && m_Toped)
			{
				m_itemID = -2;//顶层菜单
			};
			m_ItemLists[m_index].m_ItemID = m_itemID;
			if (m_itemID>0)
			{
				m_ItemLists[m_index].m_IconIndex= m_iconindex;
				m_iconindex+=1;
			}
			m_menu->ModifyMenu(i,MF_OWNERDRAW|MF_BYPOSITION |MF_STRING,m_ItemLists[m_index].m_ItemID,(LPSTR)&(m_ItemLists[m_index]));
			
			m_index+=1;
			CMenu* m_subMenu = m_menu->GetSubMenu(i);

			if (m_subMenu)
			{
				ChangeMenuItem(m_subMenu);
			}
		}
	}
	return TRUE	;
}

void CIconMenu::MeasureItem( LPMEASUREITEMSTRUCT lpStruct )
{
	if (lpStruct->CtlType==ODT_MENU)
	{
		lpStruct->itemHeight = ITEMHEIGHT;
		lpStruct->itemWidth = ITEMWIDTH;
		CMenuItemInfo* m_iteminfo;
		m_iteminfo = (CMenuItemInfo*)lpStruct->itemData;
		lpStruct->itemWidth = ((CMenuItemInfo*)lpStruct->itemData)->m_ItemText.GetLength()*10;
		switch(m_iteminfo->m_ItemID)
		{
			case 0: //分隔条
				{
					lpStruct->itemHeight = 1;
					break;
				}	
		}
	}
}

void CIconMenu::DrawItem( LPDRAWITEMSTRUCT lpStruct )
{
	if (lpStruct->CtlType==ODT_MENU)
	{
		if(lpStruct->itemData == NULL)	return;
		unsigned int m_state = lpStruct->itemState;
		CDC* m_dc = CDC::FromHandle(lpStruct->hDC);
		//m_dc.Attach(lpStruct->hDC);

		CString str =  ((CMenuItemInfo*)(lpStruct->itemData))->m_ItemText;
		LPSTR m_str = str.GetBuffer(str.GetLength());

		int m_itemID = ((CMenuItemInfo*)(lpStruct->itemData))->m_ItemID;
		
		int m_itemicon = ((CMenuItemInfo*)(lpStruct->itemData))->m_IconIndex;
		CRect m_rect = lpStruct->rcItem;
		
		m_dc->SetBkMode(TRANSPARENT);
		
		switch(m_itemID)
		{
		case -2:
			{

				DrawTopMenu(m_dc,m_rect,(m_state&ODS_SELECTED)||(m_state&0x0040)); //0x0040 ==ODS_HOTLIGHT
				DrawItemText(m_dc,m_str,m_rect);
				break;
			}
		case -1:
			{	
				DrawItemText(m_dc,m_str,m_rect);
				break;
			}
		case 0:
			{
				DrawSeparater(m_dc,m_rect);
				break;
			}
		default:
			{	
				DrawComMenu(m_dc,m_rect,0xfaa0,0xf00ff,m_state&ODS_SELECTED);
				DrawItemText(m_dc,m_str,m_rect);
		//if (m_itemID == m_ItemLists[1].m_ItemID)
			//	if (m_state&ODS_SELECTED)
				CRect orect;
				orect.bottom=m_rect.bottom+90;
				orect.top=m_rect.top-50;
				orect.left=m_rect.left;
				orect.right=m_rect.right;
			DrawMenuTitle(m_dc,orect,"计科052班  马健的毕业设计");				
				break;
			}
								
		}

			
	}
}
/*************************************************************
功能描述: 绘制菜单项文本

参数说明: m_pdc标识画布对象,str标识菜单文本,m_rect标识菜单区域
*************************************************************/
void CIconMenu::DrawItemText(CDC* m_pdc,LPSTR str,CRect m_rect)
{

	m_rect.DeflateRect(40,0,0,0);
	m_pdc->DrawText(str,m_rect,DT_SINGLELINE|DT_VCENTER|DT_LEFT);
}

void CIconMenu::DrawTopMenu(CDC* m_pdc,CRect m_rect,BOOL m_selected )
{
	if (m_selected)
	{
		m_pdc->SelectStockObject(BLACK_PEN);
		m_pdc->Rectangle(&m_rect);
		m_rect.DeflateRect(1,1);
		m_pdc->FillSolidRect(m_rect,RGB(150, 185, 255));
	}
	else
	{
		CRect rect;
		AfxGetMainWnd()->GetClientRect(rect);
		rect.top = m_rect.top;
		rect.bottom = m_rect.bottom;
		rect.left= 360;
		rect.right +=4;
		//CRect c_rect(m_rect);
		m_pdc->FillSolidRect(&rect,RGB(200,187, 255));
		m_pdc->FillSolidRect(&m_rect,RGB(200,187, 255));
		//m_pdc->SelectStockObject(BLACK_PEN);
		//m_pdc->FillSolidRect(m_rect,RGB(100, 185, 255));
	}
}

void CIconMenu::DrawSeparater(CDC* m_pdc,CRect m_rect)
{
	if (m_pdc != NULL)
	{
		m_rect.DeflateRect(25,0,0,0);
		m_pdc->Draw3dRect(m_rect,RGB(255,0,0),RGB(0,0,255));
	}
}

void CIconMenu::DrawComMenu(CDC* m_pdc,CRect m_rect,COLORREF m_fromcolor,COLORREF m_tocolor, BOOL m_selected )
{
	if (m_selected)
	{
		m_pdc->SelectStockObject(BLACK_PEN);

		//m_rect.InflateRect(0,0,0,0);
		m_rect.DeflateRect(25,1,0,2);
		m_pdc->Rectangle(m_rect);
		//m_rect.DeflateRect(0,1,1,1);

		CBitmap m_bitmap;
		m_bitmap.LoadBitmap(IDB_LEFTBITMAP);
		BITMAP m_size;
		m_bitmap.GetBitmap(&m_size);
		CDC m_memdc;
		m_memdc.CreateCompatibleDC(m_pdc);
		CGdiObject* m_oldobject;
		m_oldobject = m_memdc.SelectObject(&m_bitmap);

		//m_save = m_pdc->SaveDC();
		m_pdc->StretchBlt(m_rect.left+1,m_rect.top+1,m_rect.Width()-2,m_rect.Height()-2,&m_memdc,0,0,m_size.bmWidth,m_size.bmHeight,SRCCOPY);
		m_bitmap.DeleteObject();


		//m_memdc.SelectObject(m_oldobject);
	}
	else
	{
		//m_pdc->RestoreDC(m_save);
		m_pdc->FillSolidRect(m_rect,RGB(0x000000F9, 0x000000F8, 0x000000F7));
	}

}

void CIconMenu::DrawMenuIcon(CDC* m_pdc,CRect m_rect,int m_icon )
{
	//m_imagelist.Draw(m_pdc,m_icon,CPoint(m_rect.left+2,m_rect.top+4),ILD_TRANSPARENT);
}

void CIconMenu::DrawMenuTitle(CDC* m_pdc,CRect m_rect,CString m_title)
{
	CBitmap m_bitmap;
	m_bitmap.LoadBitmap(IDB_ITEMBITMAP);
	BITMAP m_size;
	m_bitmap.GetBitmap(&m_size);
	CDC m_memdc;
	m_memdc.CreateCompatibleDC(m_pdc);
	CGdiObject* m_oldobject;
	m_oldobject = m_memdc.SelectObject(&m_bitmap);
	//m_save = m_pdc->SaveDC();
	m_pdc->StretchBlt(0,0,24,m_rect.bottom,&m_memdc,0,0,m_size.bmWidth,m_size.bmHeight,SRCCOPY);
	m_bitmap.DeleteObject();
	CFont* m_oldfont = m_pdc->SelectObject(&m_titlefont);
	m_pdc->TextOut(m_rect.left+5,m_rect.Height()+65,m_title);
	//m_pdc->DrawText(m_title,m_rect,DT_SINGLELINE|DT_VCENTER |DT_LEFT);
	m_pdc->SelectObject(m_oldfont);
	m_isdrawtitle = FALSE;
}