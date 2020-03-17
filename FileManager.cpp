#include "FileManager.h"

FileManager::FileManager()
{
}

vector<student> FileManager::OpenFile()
{
	return vector<student>();
}

void FileManager::SaveData(wstring data)
{
	ofstream myfile;
	myfile.open(this->path);
	string str(data.begin(), data.end());
	myfile << str;
	myfile.close();
}
