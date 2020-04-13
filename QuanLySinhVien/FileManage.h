#pragma once
#include "Student.h"
#include <vector>
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
class FileManage
{
public:
	FileManage();
	~FileManage();

	vector<Student> OpenFile();
	void SaveData(wstring data);
private:
	string path = "C:/Users/thutte/source/repos/ThucTapKyThuatLapTrinhNam2/ThucTapKyThuatLapTrinhNam2/Data/DataStudent.txt";
};

