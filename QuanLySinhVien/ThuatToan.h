#pragma once
#include<vector>
#include"Student.h"
class ThuatToan
{
public:
	ThuatToan();
	ThuatToan(int thuatToan, int loai);
	vector<Student>Run(vector<Student>dssv);
	vector<Student> BubbleSort(vector<Student> dssv, int loai);
	vector<Student> QuickSort(vector<Student> dssv, int loai);
	vector<Student> SelectSort(vector<Student> dssv, int loai);
	vector<Student> HeapSort(vector<Student> dssv, int loai);
	vector<Student> InsertSort(vector<Student> dssv, int loai);
	vector<Student> ShellSort(vector<Student> dssv, int loai);
	vector<Student> MergeSort(vector<Student> dssv, int loai);
	private:
	bool SoSanh(Student sv1, Student sv2, int loai);
	int GetHashCode(wstring wt);
	Student* ConvertVectorToArray(vector<Student> dssv);
	vector<Student> ConvertArrayToVector(Student* dssv, int x);
	int GetMiddle(Student* dssv, int left, int right, int loai);
	void _quickSort(Student* dssv, int left, int right, int loai);
	void swap_T(int i, int j, Student* dssv);
	void maxHeapify(int index, int len, Student* dssv, int loai);
	void  merge(Student* dssv, int  left, int  center, int  right, int loai);
	void  MgSort(Student* dssv, int  left,  int  right, int loai);
	int thuatToan;
	int loai;
};

