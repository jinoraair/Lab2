#pragma once

#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;
int readFile(int** arr, const char* fname) {
	ifstream f;
	f.open(fname); //�������� �����

	//�������� �������� �����
	if (!f.is_open()) {
		cout << "������ �������� �����!"; //���� ���� �� ����������, �� ��������� �������� �����������
		return -1;
	}
	else {
		if (f.peek() == EOF) {
			cout << "���� ������" << endl;
			return -1;
		}
		else {
			int L; //������ �������

			f >> L; //���������� ���������� ���������

			if (L >= 0) { //�������� �� ��������� L � �������� [0,N];
				int i = 0;
				*arr = new int[L] {};
				while (i < L) //���� �� ����� �����, ��������� ��������!!!!!!!!!!f.eof()
				{
					f >> (*arr)[i];

					if ((*arr)[i] < 0) { //���� ��������� ������������� �����, ���������� ����������
						break;
						L = -1;
						cout << "Incorrect data!";
					}

					i++;
				}

				if (i < L) {
					L = i;
				}

				return L; //������� ���������� ���������� ���������

			}
			else {
				cout << "������ ������!";
				return -1;
			}
		}
	}

	f.close();
}

//������� ��� �������� ���� �� �����

void showArray(int arr[], int size) {

	cout << "���������� ���������: " << size << endl;
	cout << "�������� ���������������� �������: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}