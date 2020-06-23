#include "stdafx.h"
#include "FileManage.h"

FileManage::FileManage()
{
}


FileManage::~FileManage()
{
}
wstring ReadOneLine(FILE* File, wstring Line) {

	wchar_t LineOfChars[512];
	fgetws(LineOfChars, 512, File);

	Line.clear();
	Line.append(LineOfChars);

	return Line;
}

vector<Student> FileManage::OpenFile()
{
	/*return	PrintFile();*/
	vector<Student>dsSV = vector<Student>();
	FILE* file;
	wstring line;
	wstring FileName = L"C:/Users/huyen/Source/Repos/ttktlt/QuanLySinhVien/Data/DataStudent.txt";
	_wfopen_s(&file, FileName.c_str(), L"r,ccs=UTF-16LE");
	Student sv;

	while (!feof(file) && !ferror(file)) {
		line = ReadOneLine(file, line);
		if (line.size() < 500)
		{
			if (line.find(L"Thông tin sinh viên: ") != wstring::npos)
			{
				if (!sv.CheckStudentNull())
					dsSV.push_back(sv);
				sv = Student();
			}
			else if (line.find(L"id: ") != string::npos) {

				sv.SetId(SlitLine(line, L"id: ").at(0));
			}
			else if (line.find(L"idClass: ") != string::npos) {
				sv.SetIdClass(SlitLine(line, L"idClass: ").at(0));
			}
			else if (line.find(L"Name: ") != string::npos) {
				wstring name = SlitLine(line, L"Name: ").at(0);
				vector<wstring>listname = SlitLine(name, L" ");
				wstring ret = L"";
				for each (wstring it in listname)
				{
					std::transform(it.begin(), it.begin() + 1, it.begin(), ::toupper);
					std::transform(it.begin() + 1, it.end(), it.begin() + 1, ::tolower);
					ret += L" " + it;
				}
				sv.SetName(ret);
			}
			else if (line.find(L"DateTime: ") != string::npos)
			{
				sv.SetDateTime(SlitLine(line, L"DateTime: ").at(0));
			}
			else if (line.find(L"NumBer: ") != string::npos)
			{
				sv.SetNumBer(SlitLine(line, L"NumBer: ").at(0));
			}
		}
	}
	if (!sv.CheckStudentNull())
		dsSV.push_back(sv);
	fclose(file);
	return dsSV;
}

bool FileManage::SaveData(wstring data)
{
	//xoas file cux

	wofstream file(this->path, ios_base::binary | ios_base::app); //binary is important to set!  
	try
	{
		wchar_t buffer[128];
		file.rdbuf()->pubsetbuf(buffer, 128);
		file.put(0xFEFF); //this is the BOM flag, UTF16 needs this, but mirosoft's UNICODE doesn't, so you can skip this line, if any.  
		file << data + L"\n";
		file.close();
		return true;
	}
	catch (const std::exception&)
	{
		file.close();
		return false;
	}

}

vector<wstring> FileManage::SlitLine(wstring line, wstring charS)
{
	vector<wstring>dsChuoi = vector<wstring>();
	size_t pos = 0;
	std::wstring token;
	while ((pos = line.find(charS)) != std::string::npos) {
		token = line.substr(0, pos);
		if (token != L"")
			dsChuoi.push_back(token);
		line.erase(0, pos + charS.length());
	}
	dsChuoi.push_back(wstring(line.begin(), line.end()));
	return dsChuoi;
}

vector<Student> FileManage::FindSV(wstring line, vector<int>listFind)
{
	vector<Student> dssv = OpenFile();
	vector<Student>ret;
	for (size_t i = 0; i < dssv.size(); i++)
	{
		for each (int id in listFind)
		{
			switch (id + 1)
			{
			case 1:
			{
				if (dssv.at(i).GetId().find(line) != wstring::npos)
					ret.push_back(dssv.at(i));
				break;
			}
			case 2:
			{
				if (dssv.at(i).GetIdClass().find(line) != wstring::npos)
					ret.push_back(dssv.at(i));
				break;
			}
			case 3:
			{
				if (dssv.at(i).GetName().find(line) != wstring::npos)
					ret.push_back(dssv.at(i));
				break;
			}
			case 4:
			{
				if (dssv.at(i).GetDateTime().find(line) != wstring::npos)
					ret.push_back(dssv.at(i));
				break;
			}
			case 5:
			{
				if (dssv.at(i).GetNumBer().find(line) != wstring::npos)
					ret.push_back(dssv.at(i));
				break;
			}
			default:
				break;
			}
		}
	}
	return ret;
}

void FileManage::SaveDataList(vector<Student> dssv)
{

	wofstream file(this->path);
	for each (Student var in dssv)
	{
		SaveData(var.toString());
	}
}

vector<vector<int>> FileManage::Statistic(vector<wstring> dsIdLop)
{
	int gioi = 0, kha = 0, tb = 0, yeu = 0;
	vector<vector<int>>ret;
	for each (wstring var in dsIdLop)
	{
		if (var != L"\n")
			ret.push_back(StatisticClass(var));
	}
	return ret;
}

vector<wstring> FileManage::GetIdClass()
{
	vector<wstring>dsmaLop;
	vector<Student>dssv = OpenFile();
	for each (Student var in dssv)
	{
		bool x = find(dsmaLop.begin(), dsmaLop.end(), var.GetIdClass()) == dsmaLop.end();
		if (x)
			dsmaLop.push_back(var.GetIdClass());
	}
	return dsmaLop;
}

vector<int> FileManage::StatisticClass(wstring id)
{
	vector<Student>dssv = OpenFile();
	int gioi = 0, kha = 0, tb = 0, yeu = 0;
	for each (Student var in dssv)
	{
		if (var.GetIdClass() == id) {
			float dtb = stoi(var.GetNumBer());
			if (dtb < 5)
				yeu++;
			else if (dtb < 7)
				tb++;
			else if (dtb < 8)
				kha++;
			else
			{
				gioi++;
			}
		}

	}
	return vector<int>{gioi, kha, tb, yeu};
}
