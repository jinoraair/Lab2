#pragma once

#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;
int readFile(int** arr, const char* fname) {
	ifstream f;
	f.open(fname); //Открытие файла

	//Проверка открытия файла
	if (!f.is_open()) {
		cout << "Ошибка открытия файла!"; //Если файл не существует, то программа аварийно завершается
		return -1;
	}
	else {
		if (f.peek() == EOF) {
			cout << "Файл пустой" << endl;
			return -1;
		}
		else {
			int L; //размер массива

			f >> L; //считывание количества элементов

			if (L >= 0) { //Проверка на попадание L в диапазон [0,N];
				int i = 0;
				*arr = new int[L] {};
				while (i < L) //пока не конец файла, считываем значения!!!!!!!!!!f.eof()
				{
					f >> (*arr)[i];

					if ((*arr)[i] < 0) { //если встречено отрицательное число, прекращаем считывание
						break;
						L = -1;
						cout << "Incorrect data!";
					}

					i++;
				}

				if (i < L) {
					L = i;
				}

				return L; //функция возвращает количество элементов

			}
			else {
				cout << "Ошибка памяти!";
				return -1;
			}
		}
	}

	f.close();
}

//ВЫВЕДЕМ ЭТУ ЧИСЛОВУЮ КАШУ НА ЭКРАН

void showArray(int arr[], int size) {

	cout << "Количество элементов: " << size << endl;
	cout << "Элементы отсортированного массива: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}