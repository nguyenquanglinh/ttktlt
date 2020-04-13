#include "stdafx.h"
#include "FileManage.h"


FileManage::FileManage()
{
}


FileManage::~FileManage()
{
}

vector<Student> FileManage::OpenFile()
{
	return vector<Student>();
}

void FileManage::SaveData(wstring data)
{
	ofstream myfile;
	myfile.open(this->path);
	string str(data.begin(), data.end());
	myfile << str;
	myfile.close();
}
