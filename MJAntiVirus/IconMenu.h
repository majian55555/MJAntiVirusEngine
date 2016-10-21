// IconMenu1.h: interface for the CIconMenu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICONMENU1_H__FAA8B855_EE72_4332_96D7_73F8FA07E521__INCLUDED_)
#define AFX_ICONMENU1_H__FAA8B855_EE72_4332_96D7_73F8FA07E521__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

const int MAX_MENUCOUNT = 20,ITEMHEIGHT = 26,ITEMWIDTH= 120; //菜单项数量


/*************************************
CMenuItemInfo结构用于记录菜单项信息
*************************************/
struct CMenuItemInfo
{
	CString m_ItemText;//菜单项文本
	int m_IconIndex;//菜单项索引
	int m_ItemID;//菜单标记 -2顶层菜单,-1弹出式菜单,0分隔条,其他普通菜单
};

class CIconMenu : public CMenu  
{
public:
	CMenuItemInfo m_ItemLists[MAX_MENUCOUNT]; //菜单项信息
	int m_index; //临时索引
	int m_iconindex;
	BOOL m_isdrawtitle;
	CFont m_titlefont;
	CIconMenu();
	int m_save;
	BOOL ChangeMenuItem(CMenu* m_menu,BOOL m_Toped = FALSE);
	BOOL  AttatchMenu(HMENU m_hmenu);
	void DrawItemText(CDC* m_pdc,LPSTR str,CRect m_rect);
	void DrawTopMenu(CDC* m_pdc,CRect m_rect,BOOL m_selected = FALSE); //绘制顶层菜单
	void DrawSeparater(CDC* m_pdc,CRect m_rect);//绘制分隔条
	void DrawComMenu(CDC* m_pdc,CRect m_rect,COLORREF m_fromcolor,COLORREF m_tocolor, BOOL m_selected = FALSE);
	void DrawMenuIcon(CDC* m_pdc,CRect m_rect,int m_icon );
	void DrawMenuTitle(CDC* m_pdc,CRect m_rect,CString m_title);
	//override memu's viutual method
	virtual ~CIconMenu();
	virtual void MeasureItem( LPMEASUREITEMSTRUCT lpStruct);//设置菜单项大小
	virtual void DrawItem(LPDRAWITEMSTRUCT lpStruct);//重绘菜单项

};

#endif // !defined(AFX_ICONMENU1_H__FAA8B855_EE72_4332_96D7_73F8FA07E521__INCLUDED_)
