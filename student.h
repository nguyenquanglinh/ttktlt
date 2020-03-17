#pragma once
#include<iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;

class student
{
public:
	student();
	student(wstring id, wstring idClass, wstring name, wstring dateTime, wstring number);
	void SetIdClass(int idClass);
	void SetId(int id);
	void SetName(wstring name);
	void SetNumBer(wstring number);
	void SetDateTime(wstring dateTime);
	void InPutId();
	void InPutIdClass();
	void InputName();
	void InPutDateTime();
	void InputNumBer();
	bool CheckKey();
	bool CheckDate(wstring str);
	bool CheckStudentNull();
	wstring GetIdClass();
	wstring GetId();
	wstring GetName();
	wstring GetNumBer();
	wstring GetDateTime();
	wstring toString();
	bool getconchar(KEY_EVENT_RECORD& krec);
private:
	std::wstring idClass;
	std::wstring id;
	std::wstring name;
	std::wstring dateTime;
	std::wstring number;
};

