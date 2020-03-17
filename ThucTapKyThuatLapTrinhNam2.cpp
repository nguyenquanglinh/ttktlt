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
student AddStudent();
const int width = 1000;
const int height = 800;
int ox = 0;
int oy = 0;
int main() {
	SetUpUnicode();
	Menu_Main();


}
void InList(wstring a[], int n)
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
//0 = Black
//1 = Blue
//2 = Green
//3 = Aqua
//4 = Red
//5 = Purple
//6 = Yellow
//7 = White
//8 = Gray
//9 = Light Blue
//A = Light Green
//B = Light Aqua
//C = Light Red
//D = Light Purple
//E = Light Yellow
//F = BringWhite
void Menu_Main()
{
	system("color 20");
	
	//title ox=50,oy=2
	ox = 40;
	oy = 1;
	gotoxy(ox, oy, L"Chào mừng bạn đến với quản lý sinh viên");
	ox = 90;

	gotoxy(ox, oy, L"Hướng dẫn:");
	gotoxy(ox, oy, L"Xin mời bạn chọn(1->6)");
	oy -= 3;
	ox = 20;
	//lựa chọn 1
	wstring a[6];
	a[0] = L"1.Thêm mới hồ sơ.";
	a[1] = L"2.In danh sách.";
	a[2] = L"3.Sắp xếp.";
	a[3] = L"4.Tìm kiếm";
	a[4] = L"5.Thống kê";
	a[5] = L"6.Thoát.";
	InList(a, 6);
	
	gotoxy(ox, oy, L"Lựa chọn của bạn là: ");
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
	system("CLS");
	system("color 30");
	oy = 1;
	ox = 40;
	gotoxy(ox, oy, L"Menu thêm sinh viên mới");
	ox = 100;
	gotoxy(ox, oy, L"Hướng dẫn:");
	ox = 90;
	wstring b[3];
	b[0] = L"1.Lưu(SHIFT).";
	b[1] = L"2.Thoát-không lưu(CTRL).";
	b[2] = L"3.Nhập lại thông tin(ALT).";
	InList(b, 3);
	student st = AddStudent();
	//gotoxy(ox, oy, st.toString());
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

student AddStudent()
{
	/*wstring a[5];
	a[0] = L"1.Mã sinh viên: ";
	a[1] = L"2.Mã lớp: ";
	a[2] = L"3.Tên sinh viên: ";
	a[3] = L"4.Ngày tháng năm sinh: ";
	a[4] = L"5.Điểm trung bình: ";*/
	student st;
	oy -= 7;
	ox = 20;
	//mã sinh viên
	while (st.GetId() == L"0")
	{
		gotoxy(ox, oy, L"1.Mã sinh viên: ");
		st.InPutId();
	}
	//gotoxy(ox, oy, st.GetId());

	//mã lớp
	while (st.GetIdClass() == L"0")
	{
		gotoxy(ox, oy, L"2.Mã lớp: ");
		st.InPutIdClass();
	}
	//gotoxy(ox, oy, st.GetIdClass());

	//tên 
	while (st.GetName() == L"0")
	{
		gotoxy(ox, oy, L"3.Tên sinh viên: ");
		st.InputName();
	}
	//gotoxy(ox, oy, st.GetName());

	//datetime
	while (st.GetDateTime() == L"0")
	{
		gotoxy(ox, oy, L"4.Ngày tháng năm sinh: ");
		st.InPutDateTime();
	}
	//gotoxy(ox, oy, st.GetDateTime());


	//number
	while (st.GetNumBer() == L"0.0")
	{
		gotoxy(ox, oy, L"5.Điểm trung bình: ");
		st.InputNumBer();
	}
	//gotoxy(ox, oy, std::to_wstring(st.GetNumBer()));

	return st;
}

void SetRect()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}