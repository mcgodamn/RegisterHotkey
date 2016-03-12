// ConsoleApplication18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ConsoleApplication18.h"
#include <Windows.h>
#include <time.h>
using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	enum{keyid = 1}; //創建id變數(int好像也行
	HWND h; //h = HANDLE
	RegisterHotKey(0, keyid, MOD_ALT, 0x5A); //註冊熱鍵ALT+Z
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)){ //攔截熱鍵MASSAGE
		PeekMessage(&msg, 0, 0, 0, 0x0001); //檢查流經的MASSAGE
		switch(msg.message){
		case WM_HOTKEY:
			if (msg.wParam == keyid){  //若流經MASSAGE的ID為設定熱鍵的ID則執行事件
				h = FindWindow(NULL, _T("WWE 2K15")); //FINDWINDOW函式 此處以WWE 2K15為例
				if (h){ //如果WWE 2K15執行中
					SendMessage(h, WM_CLOSE, 0, 0); //寄一個結束指令給該視窗
					Sleep(300); //等候視窗結束
					system("start C:\\Users\\Mcgodamn0\\Desktop\\game\\WWE2K15Launcher.exe.lnk"); //重啟WWE 2K15(我自己的需求
				}
				else system("start C:\\Users\\Mcgodamn0\\Desktop\\game\\WWE2K15Launcher.exe.lnk");

			}
		}
	}
	
		return 0;
}
