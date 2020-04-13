#include "stdafx.h"
#include "Student.h"
#include <string>

Student::Student()
{
	this->idClass = L"0";
	this->id = L"0";
	this->name = L"0";
	this->number = L"0.0";
	this->dateTime = L"0";
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
	if (CheckKey())
		return;
	else
	{
		wcin >> this->id;
		if (this->id.length() != 8)
		{
			this->id = L"0";
			return;
		}
	}
}

void Student::InPutIdClass()
{
	if (CheckKey())
		return;
	else
	{
		wcin >> this->idClass;

		if (this->idClass.length() != 8)
		{
			this->idClass = L"0";
			return;
		}
	}
}

void Student::InputName()
{
	if (CheckKey())
		return;
	else
	{
		wcin >> this->name;
		int x = this->name.length();
		if (x < 8 || x>30)
		{
			this->name = L"0";
			return;
		}
	}

}

void Student::InPutDateTime()
{
	if (CheckKey())
		return;
	else
	{
		wcin>> this->dateTime;
		if (!CheckDate(this->dateTime))
		{
			this->dateTime = L"0";
			return;
		}
	}

}

void Student::InputNumBer()
{
	if (CheckKey())
		return;
	else
	{
		wcin >> this->number;
		//std::stoi(ws);
		int i = stoi(this->number);
		if (i > 10 || i <= 0) {
			this->number = L"0";
		}
	}

}

bool Student::CheckKey()
{
	KEY_EVENT_RECORD key;
	if (!GetConChar(key)) return false;

	switch (key.wVirtualKeyCode)
	{
	case 16:
	{
		std::wcout << "LƯU";
		return true;
	}
	case 17:
	{
		std::wcout << "THOÁT";
		return true;
	}
	case 18:
	{
		std::wcout << "NHẬP LẠI";
		return true;
	}
	case 32:
	{
		std::wcout << "Dấu cách";
		return true;
	}
	case 13:
	{
		std::wcout << "Enter";
		return true;
	}
	default:
		return false;
	}
}

bool Student::CheckDate(wstring str)
{

	int vtDau = 0;
	//std::vector<int> parts;
	int dem = 0;
	int length = str.length();
	if (length == 0 || length < 8 || length>10)return false;
	for (int i = 0; i < length; i++) {
		if (str[i] == '/')
		{
			dem++;

			if (dem > 2)
				return false;
			else
			{
				if (i - vtDau > 2) {
					return false;
				}
				else
				{
					vtDau = i + 1;
				}
			}
		}
	}
	return true;

}

bool Student::CheckStudentNull()
{
	return this->GetId() == L"0"&&
		this->GetIdClass() == L"0"&&
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
