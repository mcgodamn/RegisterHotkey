// ConsoleApplication18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ConsoleApplication18.h"
#include <Windows.h>
#include <time.h>
#pragma comment(lib, "user32.lib")
using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	enum{keyid = 1}; //�Ы�id�ܼ�(int�n���]��
	HWND h; //h = HANDLE
	RegisterHotKey(0, keyid, MOD_ALT, 0x5A); //���U����ALT+Z
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)){ //�d�I����MASSAGE
		PeekMessage(&msg, 0, 0, 0, 0x0001); //�ˬd�y�g��MASSAGE
		switch(msg.message){
		case WM_HOTKEY:
			if (msg.wParam == keyid){  //�Y�y�gMASSAGE��ID���]�w���䪺ID�h����ƥ�
				h = FindWindow(NULL, _T("WWE 2K15")); //FINDWINDOW�禡 ���B�HWWE 2K15����
				if (h){ //�p�GWWE 2K15���椤
					SendMessage(h, WM_CLOSE, 0, 0); //�H�@�ӵ������O���ӵ���
					Sleep(300);
					system("start C:\\Users\\Mcgodamn0\\Desktop\\game\\WWE2K15Launcher.exe.lnk"); //����WWE 2K15(�ڦۤv���ݨD
				}
				else system("start C:\\Users\\Mcgodamn0\\Desktop\\game\\WWE2K15Launcher.exe.lnk");

			}
		}
	}
	
		return 0;
}