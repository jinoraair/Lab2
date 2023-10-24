#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <stdio.h> 
#include <time.h> 
#include <vector>

#include "SortingAlgorithms.h"
#include "InputOutput.h"


using namespace std;


//СЧИТЫВАЕМ ЭЛЕМЕНТЫ МАССИВА С ФАЙЛА


//sort - укаазатель на функцию сортировки
int getSortRuntimeTics(int* arr, int size, void (*sort)(int*, int))
{
	clock_t start = clock();
	sort(arr, size);
	clock_t end = clock();
	double ticks = (double)(end - start); // microsec
	return ticks;
}

int main() {
	setlocale(LC_ALL, "Russian");

	std::vector<std::string> random_data
	{
		//"input_100.txt" ,
		//"input_500.txt" ,
		//"input_1000.txt" ,
		//"input_2500.txt" , 
		//"input_5000.txt" ,
		//"input_10000.txt" ,
		//"input_20000.txt" ,
		//"input_25000.txt" ,
		//"input_40000.txt" ,
		//"input_80000.txt" ,
		/*"input_sorted_100.txt" ,
		"input_sorted_500.txt" ,
		"input_sorted_1000.txt" ,
		"input_sorted_5000.txt" ,
		"input_sorted_10000.txt" ,
		"input_sorted_20000.txt" ,*/
		"reversed_100.txt" ,
		"reversed_1000.txt" ,
		"reversed_5000.txt" ,
		"reversed_10000.txt" ,
		"reversed_20000.txt" ,
		"reversed_40000.txt" ,
	};

	std::vector<std::string> sorted_data
	{
		//"input_sorted_100.txt" ,
		//"input_sorted_500.txt" ,
		//"input_sorted_1000.txt" ,
		//"input_sorted_5000.txt" ,
		////"input_sorted_2500.txt" ,
		//"input_sorted_10000.txt" ,
		//"input_sorted_20000.txt" ,	
		//"input_sorted_25000.txt" ,
		//"input_sorted_40000.txt" ,
		//"input_sorted_80000.txt" ,
	};

	std::vector<std::string> reversed_data
	{
		/*"input_reversed_100.txt" ,
		"input_reversed_1000.txt" ,
		"input_reversed_5000.txt" ,
		"input_reversed_10000.txt" ,
		"input_reversed_20000.txt" ,
		"input_reversed_40000.txt" ,*/
		//"input_reversed_80000.txt"
	};

	//Можно менять random_data на sorted_data или reversed_data
	for (std::string file : random_data)
	{
		int* arr = nullptr;
		int size = readFile(&arr, file.c_str());
		//Можно менять SelectionSort на другой алгоритм
		int ticks = getSortRuntimeTics(arr, size, InsertSort);
		cout << ticks << endl;
		//Для больших массивов долгий вывод, поэтому закомментим большие массивы
		//showArray(arr, size);
	}

}
