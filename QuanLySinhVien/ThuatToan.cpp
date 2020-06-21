#include "stdafx.h"
#include "ThuatToan.h"

ThuatToan::ThuatToan()
{
}

vector<Student> ThuatToan::BubbleSort(vector<Student> dssv, int loai)
{
	int coit = dssv.size();
	Student* a = ConvertVectorToArray(dssv);
	for (int i = 0; i < coit - 1; i++) {
		for (int j = 0; j < coit - 1 - i; j++) {
			if (SoSanh(a[j], a[j + 1], loai)) {
				swap(a[j], a[j + 1]);
			}
		}
	}
	return ConvertArrayToVector(a, coit);
}

vector<Student> ThuatToan::QuickSort(vector<Student> dssv, int loai)
{
	int coit = dssv.size();
	Student* a = ConvertVectorToArray(dssv);
	_quickSort(a, 0, coit - 1, loai);
	return ConvertArrayToVector(a, coit);
}

vector<Student> ThuatToan::SelectSort(vector<Student> dssv, int loai)
{
	int cout = dssv.size();
	int  position = 0;
	for (int i = 0; i < cout; i++) {
		int  j = i + 1;
		position = i;
		Student  temp = dssv[i];
		for (; j < cout; j++) {
			if (SoSanh(temp, dssv[j], loai)) {
				temp = dssv[j];
				position = j;
			}
		}
		dssv[position] = dssv[i];
		dssv[i] = temp;
	}
	return dssv;
}

vector<Student> ThuatToan::HeapSort(vector<Student> dssv, int loai)
{
	Student* a = ConvertVectorToArray(dssv);
	int len = dssv.size() - 1;
	int beginIndex = (len - 1) >> 1;
	for (int i = beginIndex; i >= 0; i--) {
		maxHeapify(i, len, a, loai);
	}

	for (int i = len; i > 0; i--) {
		swap_T(0, i, a);
		maxHeapify(0, i - 1, a, loai);
	}
	return ConvertArrayToVector(a, len + 1);
}

vector<Student> ThuatToan::InsertSort(vector<Student> dssv, int loai)
{
	int coit = dssv.size();
	for (int i = 1; i < coit; i++) {
		Student  temp = dssv[i];
		int  j = i - 1;
		for (; j >= 0 && SoSanh(dssv[j], temp, loai); j--) {
			// Moves the value greater than temp back by one unit  
			dssv[j + 1] = dssv[j];
		}
		dssv[j + 1] = temp;
	}
	return dssv;
}

vector<Student> ThuatToan::ShellSort(vector<Student> dssv, int loai)
{
	int  i;
	int  j;
	Student  temp;
	int  gap = 1;
	int  len = dssv.size();
	while (gap < len / 3) { gap = gap * 3 + 1; }
	for (; gap > 0; gap /= 3) {
		for (i = gap; i < len; i++) {
			temp = dssv[i];
			for (j = i - gap; j >= 0 && SoSanh(dssv[j], temp, loai); j -= gap) {
				dssv[j + gap] = dssv[j];
			}
			dssv[j + gap] = temp;
		}
	}
	return dssv;
}

vector<Student> ThuatToan::MergeSort(vector<Student> dssv, int loai)
{
	int coit = dssv.size();
	Student* a = ConvertVectorToArray(dssv);

	MgSort(a, 0, coit-1,loai);
	return ConvertArrayToVector(a,coit);
}

bool ThuatToan::SoSanh(Student sv1, Student sv2, int loai)
{
	///mã sv
	if (loai == 1)
		return GetHashCode(sv1.GetId()) > GetHashCode(sv2.GetId());
	else if (loai == 2)
		return  GetHashCode(sv1.GetIdClass()) > GetHashCode(sv2.GetIdClass());
	else if (loai == 3)
		return  GetHashCode(sv1.GetName()) > GetHashCode(sv2.GetName());
	else if (loai == 4)
		return  GetHashCode(sv1.GetNumBer()) > GetHashCode(sv2.GetNumBer());
	/*else if(loai==5)
		return  GetHashCode(sv1.GetNumBer()) > GetHashCode(sv2.GetNumBer());*/
	return false;
}

int ThuatToan::GetHashCode(wstring wt)
{
	int x = 0;
	for each (wchar_t it in wt)
	{
		if (it == '\n')
			continue;
		x ^= it;
	}
	return x;
}

Student* ThuatToan::ConvertVectorToArray(vector<Student> dssv)
{
	int coit = dssv.size();
	Student* a = new Student[coit * sizeof(Student)];
	for (int i = 0; i < coit; i++)
	{
		a[i] = dssv.at(i);
	}
	return a;
}

vector<Student> ThuatToan::ConvertArrayToVector(Student* dssv, int x)
{
	vector<Student>ret;
	for (size_t i = 0; i < x; i++)
	{
		ret.push_back(dssv[i]);
	}
	return ret;
}

int ThuatToan::GetMiddle(Student* dssv, int low, int hight, int loai)
{
	Student tmp = dssv[hight];
	int l = low;
	int r = hight - 1;
	while (true) {
		while (l <= r && SoSanh(tmp, dssv[l], loai)) {
			l++;
		}
		while (r >= l && SoSanh(dssv[r], tmp, loai)) {
			r--;
		}
		if (l >= r) break;
		swap(dssv[l], dssv[r]);

		l++;
		r--;
	}
	swap(dssv[l], dssv[hight]);
	return l;
}

void ThuatToan::_quickSort(Student* dssv, int left, int right, int loai)
{
	if (left < right) {
		int middle = GetMiddle(dssv, left, right, loai);
		_quickSort(dssv, left, middle - 1, loai);
		_quickSort(dssv, middle + 1, right, loai);
	}
}

void ThuatToan::swap_T(int i, int j, Student* dssv)
{
	Student temp = dssv[i];
	dssv[i] = dssv[j];
	dssv[j] = temp;
}

void ThuatToan::maxHeapify(int index, int len, Student* dssv, int loai)
{
	int li = (index << 1) + 1;
	int ri = li + 1;
	int cMax = li;
	if (li > len) {
		return;
	}
	if (ri <= len && SoSanh(dssv[ri], dssv[li], loai))
	{
		cMax = ri;
	}
	if (SoSanh(dssv[cMax], dssv[index], loai)) {
		swap_T(cMax, index, dssv);
		maxHeapify(cMax, len, dssv, loai);
	}
}


void ThuatToan::merge(Student* arr, int l, int m, int r, int loai)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	Student* L = new Student[n1];
	Student* R = new Student[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2) {
		if (!SoSanh(L[i], R[j], loai)) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void ThuatToan::MgSort(Student* dssv, int l, int r, int loai)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		MgSort(dssv, l, m, loai);
		MgSort(dssv, m + 1, r, loai);
		merge(dssv, l, m, r, loai);
	}
}
