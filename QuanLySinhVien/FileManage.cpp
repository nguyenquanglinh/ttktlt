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
	vector<Student>dsSV = vector<Student>();
	if (myfile.is_open())
	{
		Student sv;
		while (getline(myfile, line))
		{
			if (line.find("Thông tin sinh viên: ") != string::npos)
			{
				if (!sv.CheckStudentNull())
					dsSV.push_back(sv);
				sv = Student();
			}
			else if (line.find("id: ") != string::npos) {
				sv.SetId(SlitLine(line,"id: ").at(0));
			}
			else if (line.find("idClass: ") != string::npos) {
				sv.SetIdClass(SlitLine(line, "idClass: ").at(0));
			}
			else if (line.find("Name: ") != string::npos) {
				sv.SetName(SlitLine(line, "Name: ").at(0));
			}
			else if(line.find("DateTime: ")!=string::npos)
			{
				sv.SetDateTime(SlitLine(line, "DateTime: ").at(0));
			}
			else if (line.find("NumBer: ") != string::npos)
			{
				sv.SetNumBer(SlitLine(line, "NumBer: ").at(0));
			}
		}
		if (!sv.CheckStudentNull())
			dsSV.push_back(sv);
		myfile.close();
	}
	return dsSV;
}

bool FileManage::SaveData(wstring data)
{
	try
	{
		ofstream myfile;
		myfile.open(this->path, std::ios_base::app);
		string str(data.begin(), data.end());
		str += "\n";
		myfile << str;
		myfile.close();
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}

}

vector<wstring> FileManage::SlitLine(string line, string charS)
{
	vector<wstring>dsChuoi = vector<wstring>();
	size_t pos = 0;
	std::string token;
	while ((pos = line.find(charS)) != std::string::npos) {
		token = line.substr(0, pos);
		if (token!="")
			dsChuoi.push_back(wstring(token.begin(), token.end()));
		line.erase(0, pos + charS.length());
	}
	dsChuoi.push_back(wstring(line.begin(), line.end()));
	return dsChuoi;
}

