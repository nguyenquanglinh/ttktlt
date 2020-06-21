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
#include "ThuatToan.h"

using namespace std;
struct oxoy
{
	int ox;
	int oy;
};

void gotoxy(int x, int y, wstring str, bool control);
void SetRect();
void SetUpUnicode();
void Menu_Main(wstring str = L"Menu quản lý sinh viên");
void Menu_Add_New_Student();
void Menu_Print_List();
void Print_List(vector<Student>dsSV);
void Menu_Sort();
void Menu_Find();
void Menu_Statistic();
Student NhapThongTinSV(Student st);
Student AddStudent();
const int width = 1000;
const int height = 800;
int ox = 0;
int oy = 0;
int viTriMenu = 0;
int removeScrollbar(int x);
void InputSelect();
void HuongDanMenu_Main(wstring str);
void HuongDanMenu_AddStudent();
void HuongDanMenu_KetQuaLuu(wstring st = L"Đã lưu thông tin sinh viên thành công");
void HuongDanMenu_SangTrai(wstring st = L"Bấm nút mũi tên sang trái để quay về");

int HuongDanMenu_Luu();
int HuongDanMenu_Thoat();
int HuongDanMenu_NhapLai();

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
bool Thoat;
int main() {
	SetUpUnicode();
	removeScrollbar(1);
	/*for (size_t i = 0; i < 255; i++)
	{
		wcout << (char)201;
	}
	*/
	/*FileManage fm;
	fm.SaveData(L"Nguyễn nguyện nguyền");*/
	/*while (true)
	{
		InputSelect();
	}*/
	/*bool x = ThuatToan().GetHashCode(L"123") < ThuatToan().GetHashCode(L"124");
	wcout << x;*/
	//Print_List(ThuatToan().BubbleSort(FileManage().OpenFile(),1));
	//Print_List(ThuatToan().QuickSort(FileManage().OpenFile(), 1));
	//Print_List(ThuatToan().SelectSort(FileManage().OpenFile(), 1));
	//Print_List(ThuatToan().InsertSort(FileManage().OpenFile(), 1));
	//Print_List(ThuatToan().ShellSort(FileManage().OpenFile(), 1));
	//Print_List(ThuatToan().HeapSort(FileManage().OpenFile(), 1));
	Print_List(ThuatToan().MergeSort(FileManage().OpenFile(), 1));
	/*vector<int> NUMBERS = vector<int>
	{ 49 ,  38 ,  65 ,  97 ,  76 ,  13 ,  27 ,  78 ,  34 ,
		12 ,  64 ,  5 ,  4 ,  62 ,  99 ,  98 ,  54 ,  56 ,
		17 ,  18 ,  23 ,  34 ,  15 ,  35 ,  25 ,  53 ,  51 };
	vector<int> x = ThuatToan().BubbleSort(NUMBERS, 1);*/
}

void gotoxy(int x, int y, wstring str, bool control)
{
	if (removeScrollbar(0) <= oy) {
		removeScrollbar(oy - removeScrollbar(0) + 10);
	}
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

void Menu_Main(wstring str)
{
	HuongDanMenu_Main(str);
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
	while (viTriMenu == 0)
	{
		KEY_EVENT_RECORD key;
		getconchar(key);
		switch (key.wVirtualKeyCode)
		{
		case 37://trai quay lại
		{
			Menu_Main(L"Chào mừng bạn đến với phần mềm quản lý sinh viên");
			viTriMenu = 1;
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
			viTriMenu = vtriHTai + 1;
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
				gotoxy(ox + 20, oy / 2, L"Chương trình đã kết thúc.Hẹn gặp lại bạn :)\n\n\n\n\n\n\n\n", false);
				return;
			}
			viTriMenu = vtriHTai + 1;
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
			viTriMenu = x;
			break;
		}
		}

	}
}

void Menu_Add_New_Student()
{
	while (viTriMenu == 1)
	{
		HuongDanMenu_AddStudent();
		Student st = AddStudent();
		if (st.Thoat)
			viTriMenu = 0;
		else if (st.NhapLai)
			viTriMenu = 1;
		else if (!st.CheckStudentNull() && !st.Thoat && !st.NhapLai) {
			if (HuongDanMenu_Luu() == 0)
			{
				FileManage fn;
				viTriMenu = 0;
				if (fn.SaveData(st.toString())) {
					HuongDanMenu_KetQuaLuu();
				}
				else
				{
					HuongDanMenu_KetQuaLuu(L"Lưu kết quả không thành công vui lòng thử lại sau");
				}
				/*Menu_Main(L"Lưu thành công. ");
			else
			{
				Menu_Main(L"Lưu ");
			}*/
			}
		}
	}
}

void Menu_Print_List()
{
	FileManage fm;
	Print_List(fm.OpenFile());

}

void Print_List(vector<Student> dsSV)
{
	system("CLS");
	system("color 30");
	int cout = dsSV.size();
	oxoy* selected = new oxoy[cout + 2];
	ox = 60;
	oy = 2;
	gotoxy(ox, oy, L"Danh sách sinh viên", false);
	oy = 6;
	ox = 30;
	//gotoxy(ox, oy, L"STT\t Mã sinh viên\t Mã lớp\t\t Tên sinh viên\t\t Ngày sinh\t Điểm trung bình", false);
	gotoxy(25, oy, L"STT", true);
	gotoxy(35, oy, L"Mã sinh viên", true);
	gotoxy(55, oy, L"Mã lớp ", true);
	gotoxy(75, oy, L"Họ và tên", true);
	gotoxy(100, oy, L"Ngày sinh", true);
	gotoxy(115, oy, L"Điểm trung bình", false);
	oy += 2;

	for (int i = 0; i < cout; i++)
	{
		selected[i].ox = 26;
		selected[i].oy = oy - 1;
		gotoxy(26, oy, to_wstring(i + 1), true);
		gotoxy(36, oy, dsSV.at(i).GetId(), true);
		gotoxy(54, oy, dsSV.at(i).GetIdClass(), true);
		gotoxy(73, oy, dsSV.at(i).GetName(), true);
		gotoxy(99, oy, dsSV.at(i).GetDateTime(), true);
		gotoxy(117, oy, dsSV.at(i).GetNumBer(), false);
	}
	gotoxy(0, oy, L"---------------------------------------------------------------------------------------------------------------------------------------------------", false);
	selected[cout + 1].ox = ox;
	selected[cout + 1].oy = oy;
	gotoxy(ox, oy, L"Quay lại", true);
	selected[cout + 2].ox = 100;
	selected[cout + 2].oy = oy;
	gotoxy(100, oy, L"Thoát", true);
	cout += 2;
	int vtriHTai = cout;
	while (true)
	{
		if (viTriMenu == 2) {
			KEY_EVENT_RECORD key;
			getconchar(key);
			switch (key.wVirtualKeyCode)
			{
			case 37://trai quay lại
			{
				viTriMenu = 0;
				break;
			}
			case 38://lên
			{
				if (vtriHTai >= 0)
				{
					vtriHTai--;
					if (vtriHTai < 0)
						vtriHTai = cout;
				}
				gotoxy(selected[vtriHTai].ox, selected[vtriHTai].oy, L"", true);
				break;
			}

			case 40://xuống
			{

				if (vtriHTai <= cout)
				{
					vtriHTai++;
					if (vtriHTai > cout)
						vtriHTai = 0;
				}

				gotoxy(selected[vtriHTai].ox, selected[vtriHTai].oy, L"", true);
				break;
			}
			case 13: //enter lựa chọn
			{
				if (vtriHTai == cout)
					viTriMenu = 6;
				else if (vtriHTai == cout - 1)
					viTriMenu = 0;
				else {
					HuongDanMenu_SangTrai();
					viTriMenu = 2;
				}
				return;
			}
			default://nhập giá trị
			{
				int x = (int)key.uChar.AsciiChar - 48;
				if (x == 6) {
					system("CLS");
					gotoxy(ox + 20, oy / 2, L"Chương trình đã kết thúc.Hẹn gặp lại bạn :)\n\n\n\n\n\n\n\n", false);
					return;
				}
				viTriMenu = x;
				break;
			}
			}
		}
		else
		{
			break;
		}
	}

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
Student NhapThongTinSV(Student st) {
	while (st.GetId() == L"" && !st.Thoat && !st.NhapLai)
	{
		gotoxy(ox, oy, L"1.Mã sinh viên: ", false);
		st.InPutId();
		if (st.GetId().length() != 8)
			st.SetId(L"");
	}
	//gotoxy(ox, oy, st.GetId());

	//mã lớp
	while (st.GetIdClass() == L"" && !st.Thoat && !st.NhapLai)
	{
		gotoxy(ox, oy, L"2.Mã lớp: ", false);
		st.InPutIdClass();
		if (st.GetIdClass().length() != 8)
			st.SetIdClass(L"");
	}
	//gotoxy(ox, oy, st.GetIdClass());

	//tên 
	while (st.GetName() == L"" && !st.Thoat && !st.NhapLai)
	{
		gotoxy(ox, oy, L"3.Tên sinh viên: ", false);
		st.InputName();
		if (st.GetName().length() == 0)
			st.SetName(L"");
	}
	//gotoxy(ox, oy, st.GetName());

	//datetime
	while (st.GetDateTime() == L"" && !st.Thoat && !st.NhapLai)
	{
		gotoxy(ox, oy, L"4.Ngày tháng năm sinh: ", false);
		st.InPutDateTime();
		if (!st.CheckDate(st.GetDateTime()))
			st.SetDateTime(L"");
	}
	//gotoxy(ox, oy, st.GetDateTime());
	//number
	while (st.GetNumBer() == L"" && !st.Thoat && !st.NhapLai)
	{
		gotoxy(ox, oy, L"5.Điểm trung bình: ", false);
		st.InputNumBer();
		if (st.GetNumBer().length() == 0)
			st.SetNumBer(L"");
		else viTriMenu = 0;
	}
	return st;
}
Student AddStudent()
{
	/*wstring a[5];
	a[0] = L"1.Mã sinh viên: ";
	a[1] = L"2.Mã lớp: ";
	a[2] = L"3.Tên sinh viên: ";
	a[3] = L"4.Ngày tháng năm sinh: ";
	a[4] = L"5.Điểm trung bình: ";*/
	Student st = Student();
	oy -= 4;
	ox = 20;
	while (!st.NhapLai && !st.Thoat && viTriMenu == 1)
	{
		st = NhapThongTinSV(st);
		if (st.Thoat) {
			if (HuongDanMenu_Thoat() == 1)
			{
				st.Thoat = false;
			}
		}
		else if (st.NhapLai)
		{

			if (HuongDanMenu_NhapLai() == 1) {

				st.NhapLai = false;
			}
			else
			{
				viTriMenu = 1;

			}

		}
	}
	return st;
}
int removeScrollbar(int x)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + x,
		info.srWindow.Bottom - info.srWindow.Top + x
	};
	SetConsoleScreenBufferSize(handle, new_size);
	return new_size.Y;
}

void InputSelect()
{
	switch (viTriMenu)
	{
	case 0: {
		Menu_Main();
		break;
	}
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
		Thoat = true;
	}
	default:
		break;
	}
}

void HuongDanMenu_Main(wstring str)
{
	system("CLS");
	system("color 20");
	//title ox=50,oy=2
	ox = 40;
	oy = 1;//L"Chào mừng bạn đến với quản lý sinh viên"
	gotoxy(ox, oy, str, false);
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
	gotoxy(ox, oy, L"Thông tin sinh viên:", false);
	gotoxy(ox, oy, L"Mã sinh viên(8 ký tự).", false);
	gotoxy(ox, oy, L"Mã lớp(8 ký tự).", false);
	gotoxy(ox, oy, L"Họ tên(tối đa 30 ký tự).", false);
	gotoxy(ox, oy, L"Ngày tháng năm sinh(dd/mm/yyyy)", false);
	gotoxy(ox, oy, L"Điểm trung bình[0,10]", false);
	gotoxy(ox, oy, L"ASC:Thoát", false);
	gotoxy(ox, oy, L"ALT:Nhập lại", false);
}

int HuongDanMenu_Luu()
{
	system("CLS");
	oy = 5;
	system("color 31");
	oxoy selected[2];

	gotoxy(ox, oy, L"Bạn có muốn lưu hay không ?", false);
	selected[0].ox = ox;
	selected[0].oy = oy;
	gotoxy(ox, oy, L"1.Lưu.", false);

	ox += 20;
	oy -= 2;
	selected[1].ox = ox;
	selected[1].oy = oy;
	gotoxy(ox, oy, L"2.không lưu.", false);
	ox -= 20;
	int vtriHTai = 0;
	while (true)
	{
		gotoxy(selected[vtriHTai].ox, selected[vtriHTai].oy, L"", true);
		KEY_EVENT_RECORD key;
		getconchar(key);
		switch (key.wVirtualKeyCode)
		{
		case 37://trai
		{
			if (vtriHTai == 0)
				vtriHTai = 1;
			else
			{
				vtriHTai = 0;
			}
			break;
		}

		case 39://phải 
		{
			if (vtriHTai == 0)
				vtriHTai = 1;
			else
			{
				vtriHTai = 0;
			}
			break;
		}
		case 13: //enter lựa chọn
		{
			return vtriHTai;
		}
		default:
		{

			break;
		}
		}
	}
}

int HuongDanMenu_Thoat()
{
	oxoy selected[2];
	gotoxy(ox, oy, L"Bạn có muốn thoát không ?", false);
	selected[0].ox = ox;
	selected[0].oy = oy;
	gotoxy(ox, oy, L"1.Có", false);

	ox += 20;
	oy -= 2;
	selected[1].ox = ox;
	selected[1].oy = oy;
	gotoxy(ox, oy, L"2.Không", false);
	ox -= 20;
	int vtriHTai = 0;
	while (true)
	{
		gotoxy(selected[vtriHTai].ox, selected[vtriHTai].oy, L"", true);
		KEY_EVENT_RECORD key;
		getconchar(key);
		switch (key.wVirtualKeyCode)
		{
		case 37://trai
		{
			if (vtriHTai == 0)
				vtriHTai = 1;
			else
			{
				vtriHTai = 0;
			}
			break;
		}

		case 39://phải 
		{
			if (vtriHTai == 0)
				vtriHTai = 1;
			else
			{
				vtriHTai = 0;
			}
			break;
		}
		case 13: //enter lựa chọn
		{
			return vtriHTai;
		}
		default:
		{
			break;
		}
		}
	}
}

int HuongDanMenu_NhapLai()
{
	system("color 31");
	oxoy selected[2];
	gotoxy(ox, oy, L"Bạn có muốn nhập lại không ?", false);
	selected[0].ox = ox;
	selected[0].oy = oy;
	gotoxy(ox, oy, L"1.Có", false);

	ox += 20;
	oy -= 2;
	selected[1].ox = ox;
	selected[1].oy = oy;
	gotoxy(ox, oy, L"2.Không", false);

	ox -= 20;
	int vtriHTai = 0;
	while (true)
	{
		gotoxy(selected[vtriHTai].ox, selected[vtriHTai].oy, L"", true);
		KEY_EVENT_RECORD key;
		getconchar(key);
		switch (key.wVirtualKeyCode)
		{
		case 37://trai
		{
			if (vtriHTai == 0)
				vtriHTai = 1;
			else
			{
				vtriHTai = 0;
			}
			break;
		}

		case 39://phải 
		{
			if (vtriHTai == 0)
				vtriHTai = 1;
			else
			{
				vtriHTai = 0;
			}
			break;
		}
		case 13: //enter lựa chọn
		{
			return vtriHTai;
		}
		default:
		{
			break;
		}
		}
	}
}

void HuongDanMenu_KetQuaLuu(wstring st)
{
	system("color 31");
	oxoy selected[1];
	gotoxy(ox, oy, st, false);
	ox += 20;
	selected[0].ox = ox;
	selected[0].oy = oy;
	gotoxy(ox, oy, L"OK", false);
	ox -= 20;
	while (true)
	{
		gotoxy(selected[0].ox, selected[0].oy, L"", true);
		KEY_EVENT_RECORD key;
		getconchar(key);
		switch (key.wVirtualKeyCode)
		{
		case 13: //enter lựa chọn
			return;
		default:
			return;
		}
	}
}

void HuongDanMenu_SangTrai(wstring st)
{
	system("cls");
	system("color 31");
	oxoy selected[1];
	ox = 30;
	oy = 0;
	gotoxy(ox, oy, st, false);
	ox += 20;
	selected[0].ox = ox;
	selected[0].oy = oy;
	gotoxy(ox, oy, L"OK", false);
	ox -= 20;
	while (true)
	{
		gotoxy(selected[0].ox, selected[0].oy, L"", true);
		KEY_EVENT_RECORD key;
		getconchar(key);
		switch (key.wVirtualKeyCode)
		{
		case 13: //enter lựa chọn
			return;
		default:
			return;
		}
	}
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
