#pragma once
#include "Student.h"
#include <vector>
#include <iostream>
#include <fstream>
#include<string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class FileManage
{
public:
	FileManage();
	~FileManage();

	vector<Student> OpenFile();
	bool SaveData(wstring data);
	vector< wstring> SlitLine(string line,string charS);
private:
	char* path = "E:/NguyenQuangLinh/TTKTLT/QuanLySinhVien/Data/DataStudent.txt";
};
