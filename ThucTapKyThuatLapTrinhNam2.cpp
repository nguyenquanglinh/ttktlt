#include <stdio.h>
#include <windows.h>
#include <string>
#include<iostream>
#include <io.h>
#include <fcntl.h>
#include <list>
#include <conio.h>
#include "student.h"
using namespace std;

void InList(wstring a[], int n);
void gotoxy(int x, int y, wstring str);
void SetRect();
void SetUpUnicode();
void Menu_Main();
void Menu_Add_New_Student();
void Menu_Print_List();
void Menu_Sort();
void Menu_Find();
void Menu_Statistic();
const int width = 1000;
const int height = 800;
int ox = 0;
int oy = 0;
int main() {
    SetUpUnicode();
    Menu_Main();
    

}

void InList(wstring a[],int n)
{
    for (int i = 0; i < n; i++) {
        gotoxy(ox, oy, a[i]);
    }
}

void gotoxy(int x, int y, wstring str)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
    std::wcout << str;
    oy += 2;
}

void SetUpUnicode() {
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    SetRect();
}

void Menu_Main()
{
    //
    ox += 40;
    oy += 1;
    //title ox=50,oy=2
    std::wstring  title = L"Chào mừng bạn đến với quản lý sinh viên";
    gotoxy(ox, oy, title);
    ox -= 30;
    //lựa chọn 1
    wstring a[6];
    a[0]=L"1.Thêm mới hồ sơ.";
    a[1]=L"2.In danh sách.";
    a[2]=L"3.Sắp xếp.";
    a[3]=L"4.Tìm kiếm";
    a[4]=L"5.Thống kê";
    a[5]=L"6.Thoát.";
    InList(a, 6);
    gotoxy(ox, oy, L"Xin mời bạn chọn.(1->6)");
    int x = 0;
    while (true)
    {
        wcin >> x;
        switch (x)
        {
        case 1: {
            Menu_Add_New_Student();
            break;
        }
        case 2: {
            Menu_Print_List();
            break;
        }
        case 3: {
            Menu_Sort();
            break;
        }
        case 4: {
            Menu_Find();
            break;
        }
        case 5: {
            Menu_Statistic();
            break;
        }
        case 6:
        {
            return;
        }

        default:
            break;
        }

    }
}
void Menu_Add_New_Student()
{
    
}
void Menu_Print_List()
{
}
void Menu_Sort()
{
}
void Menu_Find()
{
}
void Menu_Statistic()
{
}

void SetRect()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}