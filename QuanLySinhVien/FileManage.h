#pragma once
#include "Student.h"
#include <vector>
#include <iostream>
#include <fstream>
#include<string>
#include <stdio.h>
#include <stdlib.h>
#include <codecvt>
#include <fstream>
#include <locale>
#include <vector>
using namespace std;
class FileManage
{
public:
	FileManage();
	~FileManage();

	vector<Student> OpenFile();
	bool SaveData(wstring data );
	vector< wstring> SlitLine(wstring line, wstring charS);
	vector<Student> FindSV(wstring line, vector<int> listFind);
	void SaveDataList(vector<Student> dssv );
private:
	char* path = "E:/NguyenQuangLinh/TTKTLT/QuanLySinhVien/Data/DataStudent.txt";
};
