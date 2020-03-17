﻿#include "student.h"

student::student()
{
	this->idClass = L"0";
	this->id = L"0";
	this->name = L"0";
	this->number = L"0.0";
	this->dateTime = L"0";
}

student::student(wstring id, wstring idClass, wstring name, wstring dateTime, wstring number)
{
	this->idClass = idClass;
	this->id = id;
	this->name = name;
	this->number = number;
	this->dateTime = dateTime;
}

void student::SetIdClass(int idClass)
{

	this->idClass = idClass;

}

void student::SetId(int id)
{
	this->id = id;

}

void student::SetName(wstring name)
{
	this->name = name;
}

void student::SetNumBer(wstring number)
{
	this->number = number;
}

void student::SetDateTime(wstring dateTime)
{
	this->dateTime = dateTime;
}


void student::InPutId()
{
	if (CheckKey())
		return;
	else
	{
		wcin >> this->id;
	}
}

void student::InPutIdClass()
{
	if (CheckKey())
		return;
	else
	{
		wcin >> this->idClass;
	}
}


void student::InputName()
{
	if (CheckKey())
		return;
	else
	{
		wcin >> this->name;
	}
	
}

void student::InPutDateTime()
{
	if (CheckKey())
		return;
	else
	{
		wcin >> this->dateTime;
	}
	
}

void student::InputNumBer()
{
	if (CheckKey())
		return;
	else
	{
		wcin >> this->number;
	}

}

bool student::CheckKey()
{
	KEY_EVENT_RECORD key;
	getconchar(key);
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
		std::wcout <<"Dấu cách";
		return true;
	}
	default:
		return false;
	}
}

wstring student::GetIdClass()
{
	return this->idClass;
}

wstring student::GetId()
{
	return this->id;
}

wstring student::GetName()
{
	return this->name;
}

wstring student::GetNumBer()
{
	return this->number;
}

wstring student::GetDateTime()
{
	return this->dateTime;
}

wstring student::toString()
{
	return L"Thông tin sinh viên: \nid: " + this->GetId()
		+
		L"\nidClass: " + this->GetIdClass()
		+
		L"\nName: " + this->GetName()
		+
		L"\nDateTime: " + this->GetDateTime()
		+
		L"\nNumBer: " + number;
}

bool student::getconchar(KEY_EVENT_RECORD& krec)
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
