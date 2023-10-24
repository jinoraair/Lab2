#pragma once

#include <fstream>
#include <algorithm>
using namespace std;

void SelectionSort(int* arr, int size);
void InsertSort(int* arr, int size);
void BubbleSort(int* arr, int size);
void mergeSortRun(int* arr, int size);
void quicksortRun(int* a, int size);
void shellSort(int* arr, int size);
void heapSort(int* arr, int size);
void introsortRun(int* a, int size);
void mergeSort(int arr[], int aux[], int low, int high);
void quicksort(int a[], int start, int end);
void introsort(int* a, int* begin, int* end, int maxdepth);
void timSort(int* arr, int n);
//1. ����������� �������

void SelectionSort(int* arr, int size) {

	int min = 0;	// ��� ������ ������������ ��������
	int buf = 0;	// ��� ������ ���������� 

	for (int i = 0; i < size; i++)
	{
		min = i; // �������� ����� ������� ������, ��� ������ � ����������� ���������
		// � ����� ������ �������� ����� ������ � ����������� ���������
		for (int j = i + 1; j < size; j++)
			min = (arr[j] < arr[min]) ? j : min;
		// c������ ������������ ����� ��������, ������� ��� ������� � �������
		if (i != min)
		{
			buf = arr[i];
			arr[i] = arr[min];
			arr[min] = buf;
		}
	}

}

//2. ���������� ���������

void InsertSort(int* arr, int size) {
	int buf = 0; // ��� �������� ������������� ��������
	for (int i = 1; i < size; i++)
	{
		buf = arr[i]; // �������� �������������� �������
		// � ������ ����������� ��������� ����� �� ����
		// ���� ����������� �� �������� ������ ��� ������������
		int j = i - 1;
		while (j >= 0 && arr[j] > buf) // ���� ������ �� ����� 0 � ���������� ������� ������� ������ ��������
		{
			arr[j + 1] = arr[j]; // ������������ ��������� �������
			arr[j] = buf;
			j--;
		}
	}
	//cout << "\n������ � ��������������� ���� (���������): " << endl;
	//for (int i = 0; i < size; i++) // ����� ���������������� �������
	//	cout << arr[i] << " ";
	//cout << endl;
}

//3. ���������� ���������

void BubbleSort(int* arr, int size) {
	int buff = 0; // ��� ���������� �������� ��������, ��� ����������

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				buff = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = buff;
			}
		}
	}
	/*cout << "\n������ � ��������������� ���� (���������): " << endl;

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}*/
}

//4 ���������� ��������-------------------------

// ���������� ��� ��������������� ���������� `arr[low�mid]` � `arr[mid+1�high]`
void Merge(int arr[], int aux[], int low, int mid, int high)
{
	int k = low, i = low, j = mid + 1;

	// ���� ���� �������� � ����� � ������ �����
	while (i <= mid && j <= high)
	{
		if (arr[i] <= arr[j]) {
			aux[k++] = arr[i++];
		}
		else {
			aux[k++] = arr[j++];
		}
	}

	// �������� ���������� ��������
	while (i <= mid) {
		aux[k++] = arr[i++];
	}

	// ������ �������� ���������� �� ����� (��������� ��������� ��������
	// ��� ��������� �� ����� ���������� ����� �� ��������������� �������)

	// �������� ������� � �������� ������, ����� �������� ������� ����������
	for (int i = low; i <= high; i++) {
		arr[i] = aux[i];
	}
}

void mergeSortRun(int* arr, int size)
{
	int* aux = new int[size];

	for (int i = 0; i < size; i++) {
		aux[i] = arr[i];
	}
	cout << endl;
	mergeSort(arr, aux, 0, size - 1);
}

// ��������� ������ `arr[low�high]`, ��������� ��������������� ������ `aux`
void mergeSort(int arr[], int aux[], int low, int high)
{
	// ������� �������
	if (high <= low) {        // ���� ������ ������� <= 1
		return;
	}

	// ����� ��������
	int mid = (low + ((high - low) >> 1));

	// ���������� ��������� ������� �� ��� �������� �� ��� ���, ���� ������ ������� �� ������ <= 1,
	// ����� ���������� �� � ������������ ����� �� ������� �������

	mergeSort(arr, aux, low, mid);          // ���������/���������� ����� ��������
	mergeSort(arr, aux, mid + 1, high);     // ���������/���������� ������ ��������

	Merge(arr, aux, low, mid, high);        // ���������� ��� �����������.

}

//========================================================================

//5. ������� ����������

// ���������� �� ����� Lomuto
int partition(int a[], int start, int end)
{
	// �������� ������� ������ ������� � �������� �������� �������� �������
	int pivot = a[end];

	// ��������, ������� ����� ��������, ����� ���������� ����� �� `pIndex`
	// �������� ������, ��� ����� ��������, ����� �������� ������ �� `pIndex`
	// ������ �������� ����� ���� � ����� �����������
	int pIndex = start;

	// ������ ���, ����� �� ������� �������, ������� ��� ������ ��������, `pIndex`
	// �������������, � ���� ������� ����� ������� ����� ������� ������.
	for (int i = start; i < end; i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}

	// �������� ������� `pIndex` � �������
	swap(a[pIndex], a[end]);

	// ������� `pIndex` (������ �������� ��������)
	return pIndex;
}

// ��������� ������� ����������
void quicksortRun(int* a, int size)
{
	quicksort(a, 0, size - 1);
}

// ��������� ������� ����������
void quicksort(int a[], int start, int end)
{
	// ������� �������
	if (start >= end) {
		return;
	}

	// ����������� �������� �� ���
	int pivot = partition(a, start, end);

	// ��������� ���������, ���������� ��������, ������� ������� �����
	quicksort(a, start, pivot - 1);

	// ��������� ���������, ���������� ��������, ����������� ����� �����
	quicksort(a, pivot + 1, end);
}

//=================================================================

//6. ���������� �����

void swapEl(int* arr, int i)
{
	int buff;
	buff = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = buff;
}

void shellSort(int* arr, int size)
{
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < size; i += 1)
		{
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
	/*cout << endl;
	cout << "\n������ � ��������������� ���� (���������� �����): " << endl;

	for (int k = 0; k < size; k++) {
		cout << arr[k] << " ";
	}
	cout << endl;*/
	//return 0;
}


//7. ������������� ����������

// ��������� ��� �������������� � �������� ���� ��������� � �������� ����� i, ��� ��������
// �������� � arr[]. n - ������ ����

void heapify(int arr[], int n, int i)
{
	int largest = i; // �������������� ���������� ������� ��� ������

	int l = 2 * i + 1; // ����� = 2*i + 1
	int r = 2 * i + 2; // ������ = 2*i + 2

	// ���� ����� �������� ������� ������ �����
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// ���� ����� ������� ������� �� ������
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// ���������� ����������� � �������� ���� ���������� ���������
		heapify(arr, n, largest);
	}
}

//������� ������������� ����������
void heapSort(int* arr, int size)
{
	// ���������� ���� (�������������� ������)
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);

	// ���� �� ������ ��������� �������� �� ����
	for (int i = size - 1; i >= 0; i--)
	{
		// ���������� ������� ������ � �����
		swap(arr[0], arr[i]);

		// �������� ��������� heapify �� ����������� ����
		heapify(arr, i, 0);
	}
	/*cout << "\n������ � ��������������� ���� (������������� ����������): " << endl;

	for (int k = 0; k < size; k++) {
		cout << arr[k] << " ";
	}
	cout << endl;*/
}

//8. TIMSORT

void insertionSort(int arr[], int left, int right)
{
	for (int i = left + 1; i <= right; i++) {
		int temp = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

// Merge function merges the sorted runs
void merge(int arr[], int l, int m, int r)
{

	// Original array is broken in two
	// parts left and right array
	int len1 = m - l + 1, len2 = r - m;
	int* left = new int[len1], * right = new int[len2];
	for (int i = 0; i < len1; i++)
		left[i] = arr[l + i];
	for (int i = 0; i < len2; i++)
		right[i] = arr[m + 1 + i];

	int i = 0;
	int j = 0;
	int k = l;

	// After comparing, we
	// merge those two array
	// in larger sub array
	while (i < len1 && j < len2) {
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		}
		else {
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	// Copy remaining elements of
	// left, if any
	while (i < len1) {
		arr[k] = left[i];
		k++;
		i++;
	}

	// Copy remaining element of
	// right, if any
	while (j < len2) {
		arr[k] = right[j];
		k++;
		j++;
	}
}

//���������� Timsort
//
// Iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
void timSort(int* arr, int n)
{
	const int RUN = 32;
	// Sort individual subarrays of size RUN
	for (int i = 0; i < n; i += RUN)
		insertionSort(arr, i, min((i + RUN - 1), (n - 1)));

	// Start merging from size RUN (or 32).
	// It will merge
	// to form size 64, then 128, 256
	// and so on ....
	for (int size = RUN; size < n; size = 2 * size) {

		// pick starting point of
		// left sub array. We
		// are going to merge
		// arr[left..left+size-1]
		// and arr[left+size, left+2*size-1]
		// After every merge, we
		// increase left by 2*size
		for (int left = 0; left < n; left += 2 * size) {

			// Find ending point of
			// left sub array
			// mid+1 is starting point
			// of right sub array
			int mid = left + size - 1;
			int right = min((left + 2 * size - 1), (n - 1));

			// merge sub array arr[left.....mid] &
			// arr[mid+1....right]
			if (mid < right)
				merge(arr, left, mid, right);
		}
	}
}

//9. INTROSORT

// ������� ��� ���������� ���������� ��������� � ���������� `a[low�high]`
void insertionsort(int a[], int low, int high)
{
	// �������� �� ������� �������� ����������
	// (������� � �������� `low` ��� ������������)
	for (int i = low + 1; i <= high; i++)
	{
		int value = a[i];
		int j = i;

		// ����� ������ `j` � ��������������� ������������ a[0�i-1]
		// ��� ��������� ������� a[i]
		while (j > low && a[j - 1] > value)
		{
			a[j] = a[j - 1];
			j--;
		}

		// �������� ��������, ��� ��������� `a[j�i-1]` ������� ��
		// ������ �� ���� �������, �.�. `a[j+1�i]`

		a[j] = value;
	}
}

// ������� ��� ��������� ������� �� ����� ��������� Lomuto
int Partition(int a[], int low, int high)
{
	// �������� ������� ������ ������� � �������� �������� �������� �������
	int pivot = a[high];

	// ��������, ������� ����� ��������, ����� ���������� ����� �� `pIndex`
	// �������� ������, ��� ����� ��������, ����� �������� ������ �� `pIndex`
	// ������ �������� ����� ���� � ����� �����������
	int pIndex = low;

	// ������ ���, ����� �� ������� �������, ������� ��� ������ ��������, `pIndex`
	// �������������, � ���� ������� ����� ������� ����� ������� ������.
	for (int i = low; i < high; i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}

	// �������� ������� `pIndex` � �������
	swap(a[pIndex], a[high]);

	// ������� `pIndex` (������ �������� ��������)
	return pIndex;
}

// ������� ���������� ������������������ ������� ��� ������������ ��������� �� ���
int randPartition(int a[], int low, int high)
{
	// �������� ��������� ������ ����� `[low, high]`
	int pivotIndex = rand() % (high - low + 1) + low;

	// �������� ������� �������� ������� � ���������, ������� ��������� ������
	swap(a[pivotIndex], a[high]);

	// ����� ��������� ����������
	return Partition(a, low, high);
}

// ������� ��� ���������� ������������� ���������� ��������� ��������� ���������
void heapsort(int* begin, int* end)
{
	make_heap(begin, end);
	sort_heap(begin, end);
}

void introsortRun(int* a, int size)
{
	int maxdepth = log(size) * 2;

	// ��������� ������, ��������� �������� introsort
	introsort(a, a, a + size - 1, maxdepth);
}

// ������� ��� ���������� ��������� ���������� ��������� �������
void introsort(int* a, int* begin, int* end, int maxdepth)
{
	// ��������� ���������� ���������, ���� ������ ������� 16 ��� ������
	if ((end - begin) < 16) {
		insertionsort(a, begin - a, end - a);
	}
	// ��������� ������������� ����������, ���� ������������ ������� ����� 0
	else if (maxdepth == 0) {
		heapsort(begin, end + 1);
	}
	else {
		// ����� ��������� ������� ����������
		int pivot = randPartition(a, begin - a, end - a);
		introsort(a, begin, a + pivot - 1, maxdepth - 1);
		introsort(a, a + pivot + 1, end, maxdepth - 1);
	}
}