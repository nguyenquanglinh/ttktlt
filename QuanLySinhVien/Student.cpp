#include "stdafx.h"
#include "Student.h"
#include <string>

Student::Student()
{
	this->idClass = L"";
	this->id = L"";
	this->name = L"";
	this->number = L"";
	this->dateTime = L"";
}


Student::~Student()
{
}

Student::Student(wstring id, wstring idClass, wstring name, wstring dateTime, wstring number)
{
	this->idClass = idClass;
	this->id = id;
	this->name = name;
	this->number = number;
	this->dateTime = dateTime;
}

void Student::SetIdClass(int idClass)
{

	this->idClass = idClass;

}

void Student::SetId(int id)
{
	this->id = id;

}

void Student::SetName(wstring name)
{
	this->name = name;
}

void Student::SetNumBer(wstring number)
{
	this->number = number;
}

void Student::SetDateTime(wstring dateTime)
{
	this->dateTime = dateTime;
}

void Student::InPutId()
{
	if (CheckKey(1))
		return;

}

void Student::InPutIdClass()
{
	if (CheckKey(2))
		return;
}

void Student::InputName()
{
	/*if (CheckKey(3))
		return;*/
	getline(std::wcin, this->name);
}

void Student::InPutDateTime()
{
	if (CheckKey(4))
		return;
	else
	{
		wcin >> this->dateTime;
		if (!CheckDate(this->dateTime))
		{
			this->dateTime = L"0";
			return;
		}
	}

}

void Student::InputNumBer()
{
	if (CheckKey(5))
		return;
}

bool Student::CheckKey(int x)
{
	KEY_EVENT_RECORD key;
	if (!GetConChar(key))
		return false;

	switch (key.wVirtualKeyCode)
	{
	case 16:
	{
		std::wcout << "LƯU";
		return true;
	}
	case 27:
	{
		std::wcout << "THOÁT";
		return true;
	}
	case 18:
	{
		std::wcout << "NHẬP LẠI";
		return true;
	}
	/*case 32:
	{
		std::wcout << "Dấu cách";
		return true;
	}*/
	case 13:
	{

		if (x == 1) {
			if (this->id.length() != 8)
				this->id = L"";
		}
		else if (x == 2)
		{
			if (this->idClass.length() != 8)
				this->idClass = L"";
		}
		else if (x == 3)
		{

		}
		else if (x == 4)
		{
			if (!CheckDate(this->dateTime))
			{
				this->dateTime = L"";
			}
		}
		else if (x == 5) {
			try
			{
				int y = stoi(this->number);
				if (10 < y || y < 1) {
					this->number = L"0";
				}
				this->number = std::to_wstring(y);
			}
			catch (const std::exception&)
			{
				wcout << L"\tSai điểm [1-10]";
			}

		}
		return true;
	}
	default:

		if (x == 1)
		{
			if (this->id.length() < 40) {
				std::wcout << key.uChar.AsciiChar;
				this->id += key.uChar.AsciiChar;
			}
		}
		else if (x == 2)
		{
			if (this->idClass.length() < 40) {
				std::wcout << key.uChar.AsciiChar;
				this->idClass += key.uChar.AsciiChar;
			}
		}
		else if (x == 3)
		{
			getline(std::wcin, this->name);

		}
		else if (x == 4) {
			if (this->dateTime.length() < 40) {
				std::wcout << key.uChar.AsciiChar;
				this->dateTime += key.uChar.AsciiChar;
			}
		}
		else if (x == 5) {
			if (this->number.length() < 40) {
				if (Isnumber(key.uChar.AsciiChar))
				{
					std::wcout << key.uChar.AsciiChar;
					this->number += key.uChar.AsciiChar;
				}
			}
		}
		CheckKey(x);
	}
}

bool Student::CheckDate(wstring str)
{
	try
	{
		std::string delimiter = "/";
		std::string s(this->dateTime.begin(), this->dateTime.end());
		size_t pos = 0;
		std::string token;
		int dem = 1;

		while ((pos = s.find(delimiter)) != std::string::npos) {
			token = s.substr(0, pos);
			if (token == "")
				continue;
			if (dem > 2) {
				wcout << "Sai định dạng";
				return false;
			}
			else {
				int x = stoi(token);
				if (dem == 1) {
					if (1 > x || x > 32)
					{
						return false;
						wcout << L"\tNgày sai";
					}
				}
				else if (dem == 2)
				{
					if (0 > x || x > 12)
					{
						wcout << L"\tTháng sai";
						return false;
					}

				}
				dem++;
				s.erase(0, pos + delimiter.length());
			}

		}
		if (dem == 2)
		{
			wcout << L"\tKhông thể định dạng kiểu dữ liệu";
			return false;
		}
		if (1990 > stoi(s) || stoi(s) > 2020)
		{
			wcout << L"\tNăm sai";
			return false;
		}
		return true;
	}
	catch (const std::exception&)
	{
		wcout << L"\tKhông thể định dạng kiểu dữ liệu";
		return false;
	}

}

bool Student::CheckStudentNull()
{
	return this->GetId() == L"0" &&
		this->GetIdClass() == L"0" &&
		this->GetName() == L"0";

}

wstring Student::GetIdClass()
{
	return this->idClass;
}

wstring Student::GetId()
{
	return this->id;
}

wstring Student::GetName()
{
	return this->name;
}

wstring Student::GetNumBer()
{
	return this->number;
}

wstring Student::GetDateTime()
{
	return this->dateTime;
}

wstring Student::toString()
{
	return L"Thông tin sinh viên: \nid: " + this->GetId()
		+
		L"\nidClass: " + this->GetIdClass()
		+
		L"\nName: " + this->GetName()
		+
		L"\nDateTime: " + this->GetDateTime()
		+
		L"\nNumBer: " + this->GetNumBer();
}

bool Student::GetConChar(KEY_EVENT_RECORD& krec)
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

bool Student::Isnumber(char x)
{
	if (x == 46)
		return true;
	else if (x >= 48 && x < 57)
	{
		return true;
	}
	else
	{
		return false;
	}
}
