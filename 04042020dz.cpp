/*
Лабораторная работа по курсу
Язык программирования С
Тема : Многомерные динамические массивы
Задание

1. Написать функцию, добавляющую строку двухмерному массиву в конец.
#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;
int** createArr2D(int  rows, int cols) {
	int** mas = new int* [rows];
	for (size_t r = 0; r < rows; r++)
		mas[r] = new int[cols] { 0 };
	return mas;
}
void deleteArr2D(int** mas, int rows) {
	for (size_t r = 0; r < rows; r++)
		delete[]  mas[r];
	delete[]  mas;
}
void Print(int** mas2d, int ryadkiv, int stovpciv) {
	for (size_t r = 0; r < ryadkiv; r++)
	{
		for (size_t c = 0; c < stovpciv; c++)
			cout << *(*(mas2d + r) + c) << "\t";
		cout << endl;
	}
}
void Set(int** mas2d, int ryadkiv, int stovpciv) {
	for (size_t r = 0; r < ryadkiv; r++)
		for (size_t c = 0; c < stovpciv; c++)
			mas2d[r][c] = -100 + rand() % 201;
}
void AddRowEnd(int**& mas2d, int& r, int& c) {
	int** newmas2d = createArr2D(r + 1, c);
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			newmas2d[i][j] = mas2d[i][j];
		}
	}
	delete[]mas2d;
	mas2d = newmas2d;
	r++;
}
int main()
{
	int rows, cols;
	cout << "rows="; cin >> rows;
	cout << "cols="; cin >> cols;
	int** arr = createArr2D(rows, cols);
	Set(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "***********************************************" << endl;
	AddRowEnd(arr, rows, cols);
	Print(arr, rows, cols);
	deleteArr2D(arr, rows);
	return 0;
}
*/
/*
2. Написать функцию, добавляющую строку двухмерному массиву в начало
#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;
int** createArr2D(int  rows, int cols) {
	int** mas = new int* [rows];
	for (size_t r = 0; r < rows; r++)
		mas[r] = new int[cols] { 0 };
	return mas;
}
void deleteArr2D(int** mas, int rows) {
	for (size_t r = 0; r < rows; r++)
		delete[]  mas[r];
	delete[]  mas;
}
void Print(int** mas2d, int ryadkiv, int stovpciv) {
	for (size_t r = 0; r < ryadkiv; r++)
	{
		for (size_t c = 0; c < stovpciv; c++)
			cout << *(*(mas2d + r) + c) << "\t";
		cout << endl;
	}
}
void Set(int** mas2d, int ryadkiv, int stovpciv) {
	for (size_t r = 0; r < ryadkiv; r++)
		for (size_t c = 0; c < stovpciv; c++)
			mas2d[r][c] = -100 + rand() % 201;
}
void AddRowStart(int**& mas2d, int& r, int& c) {
	int** newmas2d = createArr2D(r + 1, c);
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			newmas2d[i + 1][j] = mas2d[i][j];
		}
	}
	delete[]mas2d;
	mas2d = newmas2d;
	r++;
}
int main()
{
	int rows, cols;
	cout << "rows="; cin >> rows;
	cout << "cols="; cin >> cols;
	int** arr = createArr2D(rows, cols);
	Set(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "***********************************************" << endl;
	AddRowStart(arr, rows, cols);
	Print(arr, rows, cols);
	deleteArr2D(arr, rows);
	return 0;
}
*/
/*
3. Написать функцию, добавляющую строку двухмерному массиву в указанную позицию.
4. Написать функцию, удаляющую строку двухмерного массива по указанному номеру.
5. Написать функцию, добавляющую столбец двухмерному массиву в указанную позицию.
#include <iostream>
#include <Windows.h>
#include <ctime>
//5. Написать функцию, добавляющую столбец двухмерному массиву в указанную позицию.
using namespace std;
int** createArr2D(int  rows, int cols) {
	int** mas = new int* [rows];
	for (size_t r = 0; r < rows; r++)
		mas[r] = new int[cols] { 0 };
	return mas;
}
void deleteArr2D(int** mas, int rows) {
	for (size_t r = 0; r < rows; r++)
		delete[]  mas[r];
	delete[]  mas;
}
void Print(int** mas2d, int ryadkiv, int stovpciv) {
	for (size_t r = 0; r < ryadkiv; r++)
	{
		for (size_t c = 0; c < stovpciv; c++)
			cout << *(*(mas2d + r) + c) << "\t";
		cout << endl;
	}
}
void Set(int** mas2d, int ryadkiv, int stovpciv) {
	for (size_t r = 0; r < ryadkiv; r++)
		for (size_t c = 0; c < stovpciv; c++)
			mas2d[r][c] = -100 + rand() % 201;
}
void AddColumn(int**& mas2d, int r, int& c, int pos) {

	int** nmat = createArr2D(r, c + 1);
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < pos; j++)
		{
			nmat[i][j] = mas2d[i][j];
		}
	}
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = pos; j < c; j++)
		{
			nmat[i][j + 1] = mas2d[i][j];
		}
	}
	deleteArr2D(mas2d, r);
	mas2d = nmat;
	c++;
}
int main()
{
	int rows, cols;
	cout << "rows="; cin >> rows;
	cout << "cols="; cin >> cols;
	int** arr = createArr2D(rows, cols);
	Set(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "***********************************************" << endl;
	AddColumn(arr, rows, cols, 4);
	Print(arr, rows, cols);
	deleteArr2D(arr, rows);
	return 0;
}

6.     Написать функцию, удаляющую столбец двухмерного массива по указанному номеру.
7.     Дана матрица порядка MxN(M строк, N столбцов).Необходимо заполнить ее значениями и написать функцию, осуществляющую циклический сдвиг строк и / или столбцов массива указанное количество раз и в указанную сторону.
*/

