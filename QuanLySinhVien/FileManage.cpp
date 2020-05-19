#include "stdafx.h"
#include "FileManage.h"
#include"Student.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


FileManage::FileManage()
{
}


FileManage::~FileManage()
{
}

vector<Student> FileManage::OpenFile()
{
	string line;
	ifstream myfile(this->path);
	//vector<Student>*dsSV=new vewc
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (line.find("Thông tin sinh viên"))
				continue;
			else if(line.find("idSinhVien"))

			cout << line << '\n';
		}
		myfile.close();
	}

	else cout << "Unable to open file";
	return vector<Student>();
}

bool FileManage::SaveData(wstring data)
{
	try
	{
		ofstream myfile;
		myfile.open(this->path);
		string str(data.begin(), data.end());
		myfile << str;
		myfile.close();
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
	
}
