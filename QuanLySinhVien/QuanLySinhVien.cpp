// QuanLySinhVien.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <windows.h>
#include <string>
#include<iostream>
#include <io.h>
#include <fcntl.h>
#include <list>
#include <conio.h>
#include <wchar.h>
#include <iterator>

#include "Student.h"
#include "FileManage.h"

using namespace std;
struct oxoy
{
	int ox;
	int oy;
};
void InList(wstring a[], int n);
void gotoxy(int x, int y, wstring str, bool control);
void SetRect();
void SetUpUnicode();
void Menu_Main();
void Menu_Add_New_Student();
void Menu_Print_List();
void Menu_Sort();
void Menu_Find();
void Menu_Statistic();
Student AddStudent();
const int width = 1000;
const int height = 800;
int ox = 0;
int oy = 0;
void removeScrollbar();
void InputSelect(int x);
void HuongDanMenu_Main();
void HuongDanMenu_AddStudent();
bool MenuBase(wstring str);
bool getconchar(KEY_EVENT_RECORD& krec)
{
	DWORD cc;
	INPUT_RECORD irec;
	HANDLE h = GetStdHandle(STD_INPUT_HANDLE);

	if (h == NULL)
	{
		return false; // console not found
	}

	for (; ; )
	{
		ReadConsoleInput(h, &irec, 1, &cc);
		if (irec.EventType == KEY_EVENT
			&& ((KEY_EVENT_RECORD&)irec.Event).bKeyDown
			)//&& ! ((KEY_EVENT_RECORD&)irec.Event).wRepeatCount )
		{
			krec = (KEY_EVENT_RECORD&)irec.Event;
			return true;
		}
	}
	return false; //future ????
}

int main() {
	SetUpUnicode();
	removeScrollbar();
	Menu_Main();
}

void InList(wstring a[], int n)
{

}

void gotoxy(int x, int y, wstring str, bool control)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
	std::wcout << str;
	if (!control)
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
	HuongDanMenu_Main();
	//lựa chọn 1
	wstring a[6];
	a[0] = L"1.Thêm mới hồ sơ.";
	a[1] = L"2.In danh sách.";
	a[2] = L"3.Sắp xếp.";
	a[3] = L"4.Tìm kiếm";
	a[4] = L"5.Thống kê";
	a[5] = L"6.Thoát.";
	oxoy selected[7];
	for (int i = 0; i < 6; i++) {
		selected[i].ox = ox;
		selected[i].oy = oy;
		gotoxy(ox, oy, a[i], false);

	}
	selected[6].ox = ox + 20;
	selected[6].oy = oy;
	gotoxy(ox, oy, L"Lựa chọn của bạn là: ", false);
	int vtriHTai = 6;
	bool lanDau = false;
	while (true)
	{
		KEY_EVENT_RECORD key;
		getconchar(key);
		switch (key.wVirtualKeyCode)
		{
		case 37://trai quay lại
		{
			std::wcout << "trái";
			break;
		}
		case 38://lên
		{
			if (vtriHTai >= 0)
			{
				vtriHTai--;
				if (vtriHTai < 0)
					vtriHTai = 6;
			}
			gotoxy(selected[vtriHTai].ox, selected[vtriHTai].oy, L"", true);
			break;
		}
		case 39://phải là lựa chọn
		{
			if (vtriHTai + 1 == 6)return;
			InputSelect(vtriHTai + 1);
			break;
		}
		case 40://xuống
		{

			if (vtriHTai < 7)
			{
				vtriHTai++;
				if (vtriHTai > 6)
					vtriHTai = 0;
			}

			gotoxy(selected[vtriHTai].ox, selected[vtriHTai].oy, L"", true);
			break;
		}
		case 13: //enter lựa chọn
		{
			if (vtriHTai + 1 == 6)
			{
				system("CLS");
				gotoxy(ox+20, oy / 2, L"Chương trình đã kết thúc.Hẹn gặp lại bạn :)\n\n\n\n\n\n\n\n", false);
				return;
			}
			InputSelect(vtriHTai + 1);
			break;
		}
		default://nhập giá trị
		{
			int x = (int)key.uChar.AsciiChar - 48;
			if (x == 6) {
				system("CLS");
				gotoxy(ox + 20, oy / 2, L"Chương trình đã kết thúc.Hẹn gặp lại bạn :)\n\n\n\n\n\n\n\n", false);
				return;
			}
			InputSelect(x);
			break;
		}
		}
	}

}

void Menu_Add_New_Student()
{
	HuongDanMenu_AddStudent();
	Student st = AddStudent();
	if (!st.CheckStudentNull()) {
		gotoxy(ox, oy, L"Bạn có muốn lưu hay không ?", false);
		FileManage fm;
		fm.SaveData(st.toString());
	}
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

Student AddStudent()
{
	/*wstring a[5];
	a[0] = L"1.Mã sinh viên: ";
	a[1] = L"2.Mã lớp: ";
	a[2] = L"3.Tên sinh viên: ";
	a[3] = L"4.Ngày tháng năm sinh: ";
	a[4] = L"5.Điểm trung bình: ";*/
	Student st;
	oy -= 4;
	ox = 20;
	//mã sinh viên
	while (st.GetId() == L"")
	{
		gotoxy(ox, oy, L"1.Mã sinh viên(gồm 8 ký tự): ", false);
		st.InPutId();
	}
	//gotoxy(ox, oy, st.GetId());

	//mã lớp
	while (st.GetIdClass() == L"")
	{
		gotoxy(ox, oy, L"2.Mã lớp(gồm 8 ký tự): ", false);
		st.InPutIdClass();
	}
	//gotoxy(ox, oy, st.GetIdClass());

	//tên 
	while (st.GetName() == L"")
	{
		gotoxy(ox, oy, L"3.Tên sinh viên(tối đa 30 ký tự): ", false);
		st.InputName();
	}
	//gotoxy(ox, oy, st.GetName());

	//datetime
	while (st.GetDateTime() == L"")
	{
		gotoxy(ox, oy, L"4.Ngày tháng năm sinh (dd/mm/yyyy): ", false);
		st.InPutDateTime();
	}
	//gotoxy(ox, oy, st.GetDateTime());


	//number
	while (st.GetNumBer() == L"0")
	{
		gotoxy(ox, oy, L"5.Điểm trung bình(nhỏ hơn 10): ", false);
		st.InputNumBer();
	}
	//gotoxy(ox, oy, std::to_wstring(st.GetNumBer()));

	return st;
}

void removeScrollbar()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}

void InputSelect(int x)
{

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

void HuongDanMenu_Main()
{
	system("color 20");
	//title ox=50,oy=2
	ox = 40;
	oy = 1;
	gotoxy(ox, oy, L"Chào mừng bạn đến với quản lý sinh viên", false);
	ox = 90;
	gotoxy(ox, oy, L"Hướng dẫn:", false);
	gotoxy(ox, oy, L"Xin mời bạn chọn(1->6)", false);
	oy -= 3;
	ox = 20;
}

void HuongDanMenu_AddStudent()
{
	system("CLS");
	system("color 30");
	oy = 1;
	ox = 40;
	gotoxy(ox, oy, L"Menu thêm sinh viên mới", false);
	ox = 100;
	gotoxy(ox, oy, L"Hướng dẫn:", false);
	ox = 90;
	wstring b[3];
	gotoxy(ox, oy, L"1.Lưu(CTRL+s).", false);
	gotoxy(ox, oy, L"2.Thoát-không lưu(ESC).", false);
	gotoxy(ox, oy, L"3.Nhập lại thông tin(CTRL+z).", false);
}

bool MenuBase(wstring str)
{
	return false;
}

void SetRect()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
