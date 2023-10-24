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
//1. ССОРТИРОВКА ВЫБОРОМ

void SelectionSort(int* arr, int size) {

	int min = 0;	// для записи минимального значения
	int buf = 0;	// для обмена значениями 

	for (int i = 0; i < size; i++)
	{
		min = i; // запомним номер текущей ячейки, как ячейки с минимальным значением
		// в цикле найдем реальный номер ячейки с минимальным значением
		for (int j = i + 1; j < size; j++)
			min = (arr[j] < arr[min]) ? j : min;
		// cделаем перестановку этого элемента, поменяв его местами с текущим
		if (i != min)
		{
			buf = arr[i];
			arr[i] = arr[min];
			arr[min] = buf;
		}
	}

}

//2. СОРТИРОВКА ВСТАВКАМИ

void InsertSort(int* arr, int size) {
	int buf = 0; // для хранения перемещаемого значения
	for (int i = 1; i < size; i++)
	{
		buf = arr[i]; // запомним обрабатываемый элемент
		// и начнем перемещение элементов слева от него
		// пока запомненный не окажется меньше чем перемещаемый
		int j = i - 1;
		while (j >= 0 && arr[j] > buf) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			arr[j + 1] = arr[j]; // перестановка элементов массива
			arr[j] = buf;
			j--;
		}
	}
	//cout << "\nМассив в отсортированном виде (вставками): " << endl;
	//for (int i = 0; i < size; i++) // вывод отсортированного массива
	//	cout << arr[i] << " ";
	//cout << endl;
}

//3. СОРТИРОВКА ПУЗЫРЬКОМ

void BubbleSort(int* arr, int size) {
	int buff = 0; // для временного хранения значения, при перезаписи

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
	/*cout << "\nМассив в отсортированном виде (пузырьком): " << endl;

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}*/
}

//4 СОРТИРОВКА СЛИЯНИЕМ-------------------------

// Объединяем два отсортированных подмассива `arr[low…mid]` и `arr[mid+1…high]`
void Merge(int arr[], int aux[], int low, int mid, int high)
{
	int k = low, i = low, j = mid + 1;

	// пока есть элементы в левом и правом рядах
	while (i <= mid && j <= high)
	{
		if (arr[i] <= arr[j]) {
			aux[k++] = arr[i++];
		}
		else {
			aux[k++] = arr[j++];
		}
	}

	// копируем оставшиеся элементы
	while (i <= mid) {
		aux[k++] = arr[i++];
	}

	// Вторую половину копировать не нужно (поскольку остальные элементы
	// уже находятся на своем правильном месте во вспомогательном массиве)

	// копируем обратно в исходный массив, чтобы отразить порядок сортировки
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

// Сортируем массив `arr[low…high]`, используя вспомогательный массив `aux`
void mergeSort(int arr[], int aux[], int low, int high)
{
	// базовый вариант
	if (high <= low) {        // если размер прогона <= 1
		return;
	}

	// найти середину
	int mid = (low + ((high - low) >> 1));

	// рекурсивно разделяем прогоны на две половины до тех пор, пока размер прогона не станет <= 1,
	// затем объединяем их и возвращаемся вверх по цепочке вызовов

	mergeSort(arr, aux, low, mid);          // разделить/объединить левую половину
	mergeSort(arr, aux, mid + 1, high);     // разделить/объединить правую половину

	Merge(arr, aux, low, mid, high);        // объединить два полупрогона.

}

//========================================================================

//5. БЫСТРАЯ СОРТИРОВКА

// Разделение по схеме Lomuto
int partition(int a[], int start, int end)
{
	// Выбираем крайний правый элемент в качестве опорного элемента массива
	int pivot = a[end];

	// элементы, меньшие точки поворота, будут перемещены влево от `pIndex`
	// элементы больше, чем точка поворота, будут сдвинуты вправо от `pIndex`
	// равные элементы могут идти в любом направлении
	int pIndex = start;

	// каждый раз, когда мы находим элемент, меньший или равный опорному, `pIndex`
	// увеличивается, и этот элемент будет помещен перед опорной точкой.
	for (int i = start; i < end; i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}

	// поменять местами `pIndex` с пивотом
	swap(a[pIndex], a[end]);

	// вернуть `pIndex` (индекс опорного элемента)
	return pIndex;
}

// Процедура быстрой сортировки
void quicksortRun(int* a, int size)
{
	quicksort(a, 0, size - 1);
}

// Процедура быстрой сортировки
void quicksort(int a[], int start, int end)
{
	// базовое условие
	if (start >= end) {
		return;
	}

	// переставить элементы по оси
	int pivot = partition(a, start, end);

	// повторяем подмассив, содержащий элементы, меньшие опорной точки
	quicksort(a, start, pivot - 1);

	// повторяем подмассив, содержащий элементы, превышающие точку опоры
	quicksort(a, pivot + 1, end);
}

//=================================================================

//6. СОРТИРОВКА ШЕЛЛА

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
	cout << "\nМассив в отсортированном виде (сортировка Шелла): " << endl;

	for (int k = 0; k < size; k++) {
		cout << arr[k] << " ";
	}
	cout << endl;*/
	//return 0;
}


//7. ПИРАМИДАЛЬНАЯ СОРТИРОВКА

// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи

void heapify(int arr[], int n, int i)
{
	int largest = i; // Инициализируем наибольший элемент как корень

	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2

	// Если левый дочерний элемент больше корня
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Если самый большой элемент не корень
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(arr, n, largest);
	}
}

//Функция пирамидальной сортировки
void heapSort(int* arr, int size)
{
	// Построение кучи (перегруппируем массив)
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);

	// Один за другим извлекаем элементы из кучи
	for (int i = size - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(arr[0], arr[i]);

		// вызываем процедуру heapify на уменьшенной куче
		heapify(arr, i, 0);
	}
	/*cout << "\nМассив в отсортированном виде (пирамидальная сортировка): " << endl;

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

//сортировка Timsort
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

// Функция для выполнения сортировки вставками в подмассиве `a[low…high]`
void insertionsort(int a[], int low, int high)
{
	// начинаем со второго элемента подмассива
	// (элемент с индексом `low` уже отсортирован)
	for (int i = low + 1; i <= high; i++)
	{
		int value = a[i];
		int j = i;

		// найти индекс `j` в отсортированном подмножестве a[0…i-1]
		// где находится элемент a[i]
		while (j > low && a[j - 1] > value)
		{
			a[j] = a[j - 1];
			j--;
		}

		// Обратите внимание, что подмассив `a[j…i-1]` сдвинут на
		// вправо на одну позицию, т.е. `a[j+1…i]`

		a[j] = value;
	}
}

// Функция для разбиения массива по схеме разбиения Lomuto
int Partition(int a[], int low, int high)
{
	// Выбираем крайний правый элемент в качестве опорного элемента массива
	int pivot = a[high];

	// элементы, меньшие точки поворота, будут перемещены влево от `pIndex`
	// элементы больше, чем точка поворота, будут сдвинуты вправо от `pIndex`
	// равные элементы могут идти в любом направлении
	int pIndex = low;

	// каждый раз, когда мы находим элемент, меньший или равный опорному, `pIndex`
	// увеличивается, и этот элемент будет помещен перед опорной точкой.
	for (int i = low; i < high; i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}

	// поменять местами `pIndex` с пивотом
	swap(a[pIndex], a[high]);

	// вернуть `pIndex` (индекс опорного элемента)
	return pIndex;
}

// Быстрая сортировка рандомизированного раздела для перестановки элементов по оси
int randPartition(int a[], int low, int high)
{
	// выбираем случайный индекс между `[low, high]`
	int pivotIndex = rand() % (high - low + 1) + low;

	// поменять местами конечный элемент с элементом, имеющим случайный индекс
	swap(a[pivotIndex], a[high]);

	// вызов процедуры разделения
	return Partition(a, low, high);
}

// Функция для выполнения пирамидальной сортировки заданного диапазона элементов
void heapsort(int* begin, int* end)
{
	make_heap(begin, end);
	sort_heap(begin, end);
}

void introsortRun(int* a, int size)
{
	int maxdepth = log(size) * 2;

	// сортируем массив, используя алгоритм introsort
	introsort(a, a, a + size - 1, maxdepth);
}

// Функция для выполнения начальной сортировки заданного массива
void introsort(int* a, int* begin, int* end, int maxdepth)
{
	// выполняем сортировку вставками, если размер раздела 16 или меньше
	if ((end - begin) < 16) {
		insertionsort(a, begin - a, end - a);
	}
	// выполнить пирамидальную сортировку, если максимальная глубина равна 0
	else if (maxdepth == 0) {
		heapsort(begin, end + 1);
	}
	else {
		// иначе выполняем быструю сортировку
		int pivot = randPartition(a, begin - a, end - a);
		introsort(a, begin, a + pivot - 1, maxdepth - 1);
		introsort(a, a + pivot + 1, end, maxdepth - 1);
	}
}