// SreenProtectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mjantivirus.h"
#include "SreenProtectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSreenProtectDlg dialog


CSreenProtectDlg::CSreenProtectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSreenProtectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSreenProtectDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSreenProtectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSreenProtectDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSreenProtectDlg, CDialog)
	//{{AFX_MSG_MAP(CSreenProtectDlg)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_CLOSE()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSreenProtectDlg message handlers

BOOL CSreenProtectDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	ShowCursor(false);
	this->m_mystruct=new SMyScreen;
	CRect rc(0,0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
	::GetCursorPos(&this->m_mystruct->curpt);
	this->MoveWindow(rc);
	//SetTimer(1,500,NULL);
	this->m_mystruct->x=0;
	this->m_mystruct->y=0;
	this->m_mystruct->a=0;
	this->m_mystruct->b=0;
	this->m_mystruct->idirect=0;
	this->m_mystruct->m_nIndexBit=0;
	this->m_mystruct->dc=new CClientDC(this);
	this->thread_screen=::CreateThread(NULL,0,DrawBitmap,(LPVOID)this->m_mystruct,0,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSreenProtectDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	CBrush brush(RGB(0,0,0));
	CRect rect;
	GetClientRect(rect);
	dc.FillRect(&rect,&brush);
	// Do not call CDialog::OnPaint() for painting messages
}

void CSreenProtectDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int moveptx=point.x-this->m_mystruct->curpt.x;
	int movepty=point.y-this->m_mystruct->curpt.y;
	if(moveptx+movepty>5 || moveptx+movepty<-5)
		PostMessage(WM_CLOSE); 
	CDialog::OnMouseMove(nFlags, point);
}


//DEL void CSreenProtectDlg::OnTimer(UINT nIDEvent) 
//DEL {
//DEL 	// TODO: Add your message handler code here and/or call default
//DEL 	//KillTimer(1);
//DEL 	CClientDC dc(this);
//DEL 	if(this->m_nIndexBit>=5)
//DEL 		this->m_nIndexBit=0;
//DEL 	//this->thread_screen=::CreateThread(NULL,0,DrawBitmap,0,0,NULL);
//DEL 	DrawBitmap(dc,this->m_nIndexBit);
//DEL 	this->m_nIndexBit++;
//DEL 	SetTimer(1,500,NULL);
//DEL 	CDialog::OnTimer(nIDEvent);
//DEL }
DWORD WINAPI CSreenProtectDlg::DrawBitmap(LPVOID myinput)
{
	SMyScreen* mystruct=(SMyScreen*)myinput;
	while(true)
	{
		if(mystruct->m_nIndexBit>=5)
			mystruct->m_nIndexBit=0;
		CDC dcmem;
		dcmem.CreateCompatibleDC(mystruct->dc);
		CBitmap m_Bitmap;
		m_Bitmap.LoadBitmap(IDB_BITMAP3+mystruct->m_nIndexBit);
		dcmem.SelectObject(m_Bitmap);
		BITMAP bmp;
		GetObject(m_Bitmap,sizeof(bmp),&bmp);
		int iscreenx=GetSystemMetrics(SM_CXSCREEN);
		int iscreeny=GetSystemMetrics(SM_CYSCREEN);
		if(mystruct->a>iscreenx/5)
			mystruct->a=0;
		if(mystruct->b>iscreeny/5)
			mystruct->b=0;
		if(mystruct->idirect>1)
			mystruct->idirect=0;
		switch(mystruct->idirect)
		{
		case 0:
			for(mystruct->x=bmp.bmWidth;mystruct->x>0;mystruct->x--)
			{
				mystruct->dc->BitBlt(mystruct->a,mystruct->b,bmp.bmWidth,bmp.bmHeight,&dcmem,mystruct->x,mystruct->y,SRCCOPY);	
			}
			break;
		case 1:
			for(mystruct->y=bmp.bmHeight;mystruct->y>0;mystruct->y--)
			{
				mystruct->dc->BitBlt(mystruct->a,mystruct->b,bmp.bmWidth,bmp.bmHeight,&dcmem,mystruct->x,mystruct->y,SRCCOPY);	
			}
			break;
		}
		mystruct->idirect++;
		mystruct->a+=60;
		mystruct->b+=20;
		Sleep(3000);  //一幅图显示的时间
		mystruct->dc->BitBlt(0,0,iscreenx,iscreeny,&dcmem,0,0,BLACKNESS);
		dcmem.DeleteDC();
		mystruct->m_nIndexBit++;
	}
}

void CSreenProtectDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	//KillTimer(1);
	::TerminateThread(this->thread_screen,NULL);
	ShowCursor(true);
	CDialog::OnClose();
}

void CSreenProtectDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	PostMessage(WM_CLOSE); 
	CDialog::OnLButtonDown(nFlags, point);
}

void CSreenProtectDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	PostMessage(WM_CLOSE); 
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CSreenProtectDlg::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	PostMessage(WM_CLOSE); 
	CDialog::OnKeyUp(nChar, nRepCnt, nFlags);
}

void CSreenProtectDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	PostMessage(WM_CLOSE); 
	CDialog::OnLButtonUp(nFlags, point);
}
