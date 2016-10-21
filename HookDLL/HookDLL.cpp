#define _WIN32_WINNT 0x0500
#include <windows.h>
//HHOOK g_hookKeyBoard=NULL;
HHOOK g_hookKeyBoard_LL=NULL;
/*HINSTANCE g_hInst;
BOOL WINAPI DllMain(HINSTANCE hinstDll,DWORD fdwReason,LPVOID lpvReserved)
{
	g_hInst=hinstDll;
}*/
LRESULT CALLBACK KeyHookProc_LL(int code,WPARAM wParam,LPARAM lParam)
{
	PKBDLLHOOKSTRUCT p = NULL;
	p = (PKBDLLHOOKSTRUCT)lParam;
	if(p->vkCode>=0x30 && p->vkCode<=0x39)
	{
		return ::CallNextHookEx(g_hookKeyBoard_LL,code,wParam,lParam);
	}
	else if(p->vkCode>=0x41 && p->vkCode<=0x5A)
	{
		return ::CallNextHookEx(g_hookKeyBoard_LL,code,wParam,lParam);
	}
	else if(p->vkCode==VK_SHIFT || p->vkCode==VK_BACK || p->vkCode==VK_DELETE)
	{
		return ::CallNextHookEx(g_hookKeyBoard_LL,code,wParam,lParam);
	}
	return 1;
}
/*
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) 
{ 
	BOOL fEatKeystroke = FALSE; 
	PKBDLLHOOKSTRUCT p = NULL; 

	if (nCode == HC_ACTION)  
	{ 
		p = (PKBDLLHOOKSTRUCT) lParam; 
		switch (wParam)  
		{ 
			case WM_KEYDOWN:  

			case WM_SYSKEYDOWN: 
            case WM_KEYUP:     
			case WM_SYSKEYUP:  
				fEatKeystroke = (p->vkCode == VK_LWIN) || (p->vkCode == VK_RWIN) ||  // ÆÁ±Î×óÓÒWIN¼ü 
				//ÆÁ±ÎAlt+Tab 
				((p->vkCode == VK_TAB) && ((p->flags & LLKHF_ALTDOWN) != 0)) || 
				// ÆÁ±ÎAlt+Esc 
				((p->vkCode == VK_ESCAPE) && ((p->flags & LLKHF_ALTDOWN) != 0)) || 
				//ÆÁ±ÎCtrl+Esc 
				((p->vkCode == VK_ESCAPE) && ((GetKeyState(VK_CONTROL) & 0x8000) != 0)); 
				break; 
			default: 
				break; 
      } 
	} 

  return (fEatKeystroke ? TRUE : CallNextHookEx(glhHook,nCode,wParam,lParam)); 
} 

LRESULT CALLBACK KeyHookProc(int code,WPARAM wParam,LPARAM lParam)
{
	if(wParam>=0x30 && wParam<=0x39)
	{
		return ::CallNextHookEx(g_hookKeyBoard,code,wParam,lParam);
	}
	else if(wParam>=0x41 && wParam<=0x5A)
	{
		return ::CallNextHookEx(g_hookKeyBoard,code,wParam,lParam);
	}
	else if(wParam==VK_SHIFT || wParam==VK_BACK || wParam==VK_DELETE)
	{
		return ::CallNextHookEx(g_hookKeyBoard,code,wParam,lParam);
	}
	return 1;
}*/
void SetHook()
{	
	g_hookKeyBoard_LL=::SetWindowsHookEx(WH_KEYBOARD_LL,KeyHookProc_LL,::GetModuleHandle("HookDLL.dll"),0);
	//g_hookKeyBoard=::SetWindowsHookEx(WH_KEYBOARD,KeyHookProc,::GetModuleHandle("HookDLL.dll"),0);
}
void UnloadHook()
{
	::UnhookWindowsHookEx(g_hookKeyBoard_LL);
	//::UnhookWindowsHookEx(g_hookKeyBoard);
	//g_hookKeyBoard=NULL;
	g_hookKeyBoard_LL=NULL;
}