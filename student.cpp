#include "student.h"

student::student()
{
}

student::student(int id, int idClass, wstring name, wstring dateTime, float number)
{
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

void student::SetNumBer(float number)
{
	this->number = number;
}

void student::SetDateTime(wstring dateTime)
{
	this->dateTime = dateTime;
}

int student::GetIdClass()
{
	return this->idClass;
}

int student::GetId()
{
	return this->id;
}

wstring student::GetName()
{
	return this->name;
}

float student::GetNumBer()
{
	return this->number;
}

wstring student::GetDateTime()
{
	return this->dateTime;
}
