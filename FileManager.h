#pragma once
#include "student.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
class FileManager
{
public:
    FileManager();
    vector<student> OpenFile();
    void SaveData(wstring data);
private:
    string path = "C:/Users/thutte/source/repos/ThucTapKyThuatLapTrinhNam2/ThucTapKyThuatLapTrinhNam2/Data/DataStudent.txt";
};

