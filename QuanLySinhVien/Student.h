#pragma once
#include<iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;

class Student
{
public:
	Student();
	~Student();
	Student(wstring id, wstring idClass, wstring name, wstring dateTime, wstring number);
	void SetIdClass(wstring idClass);
	void SetId(wstring id);
	void SetName(wstring name);
	void SetNumBer(wstring number);
	void SetDateTime(wstring dateTime);
	void InPutId();
	void InPutIdClass();
	void InputName();
	void InPutDateTime();
	void InputNumBer();
	bool CheckKey(int x);
	bool CheckDate(wstring str);
	bool CheckStudentNull();
	wstring Print_SV(int x);
	wstring GetIdClass();
	wstring GetId();
	wstring GetName();
	wstring GetNumBer();
	wstring GetDateTime();
	wstring toString();
	bool GetConChar(KEY_EVENT_RECORD & krec);
	bool Isnumber(char x);
	bool Thoat = false;
	bool NhapLai = false;
	
private:
	std::wstring idClass;
	std::wstring id;
	std::wstring name;
	std::wstring dateTime;
	std::wstring number;
};

