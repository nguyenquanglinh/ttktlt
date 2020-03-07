#pragma once
#include<iostream>
using namespace std;
class student
{
public:
	student();
	student(int id, int idClass, wstring name, wstring dateTime, float number);
	void SetIdClass(int idClass);
	void SetId(int id);
	void SetName(wstring name);
	void SetNumBer(float number);
	void SetDateTime(wstring dateTime);

	int GetIdClass();
	int GetId();
	wstring GetName();
	float GetNumBer();
	wstring GetDateTime();
private:
	int idClass;
	int id;
	std::wstring name;
	std::wstring dateTime;
	float number;
};

