﻿#include "pch.h"
#include <stdio.h>
#include <locale.h>
#include <memory.h>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>
#include <time.h>
#include "math.h"

int FuncMenu();
void Input(int**&, int&, int&, int&, int&);
void Processing(int**&, int&, int&, int&, int&);
void Print(int**, int, int, int&);
int Sum(int**&, int&, int&, int&);


int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);
	setlocale(LC_ALL, "Rus");

	int** a = NULL;
	int height = 0; // высота 
	int widht = 0; // ширина
	int fakeheight = 0; //запоминает значение высоты(для очистки памяти после смещения массива)
	int menu = 0;
	int sum = 0;
	int sum1 = 0;
	int sum2 = 0;
	int k = 0;
	int sequence = 0;

	char c = '\0';

	do
	{
		menu = FuncMenu();
		switch (menu)
		{
		case 1:
			Input (a, height, widht, fakeheight, sequence);
			fakeheight = height;
			break;
		case 2:
			Processing(a, height, widht, sequence, fakeheight);
			break;
		case 3:
			Print(a, height, widht, sequence);
			break;
		case 4:
			Sum(a, height, widht, sequence);
			
			break;
		case 0:
			for (int i = 0; i < height; i++)
			{
				delete[] a[i];
			}
			delete[] a;
			break;
		default:
			printf("Введен неверный пункт меню\n");
			break;
		}
	} while (menu != 0);
	_CrtDumpMemoryLeaks();
	return 0;
}
int FuncMenu()
{
	int m = 0;
	printf("------------------\n");
	printf("1.Ввод данных \n");
	printf("2.Обработка массива \n");
	printf("3.Вывод результата \n");
	printf("4.Сумма модулей \n");
	printf("-------------------\n");
	printf("0.Выход \n");
	printf("-------------------\n");
	printf("Над проектом усердно работал ответственный и умный и красивый ученик Института Космических и информационных технологий Дан Родя <3");
	scanf_s("%d", &m);
	printf("-------------------\n");
	getchar();
	return m;
}

void Input(int**& arr,int &h,int &w, int &fakeh, int &sequence) // Ввод данных
{
	char c = 0;
	if (arr != NULL)
	{
		for (int i = 0; i < h; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}
	do
	{
		printf("Введите высоту : ");
		while (scanf_s("%d%c", &h, &c, 1) != 2 || c != '\n')
		{
			printf("Ошибка \n");
			while (getchar() != '\n');
		}
		if (h < 0)
		{
			printf("Ошибка \n");
		}
	} while (h < 0);
	
	do
	{
		printf("Введите ширину : ");
		while (scanf_s("%d%c", &w, &c, 1) != 2 || c != '\n')
		{
			printf("Ошибка \n");
			while (getchar() != '\n');
		}
		if (w < 0)
		{
			printf("Ошибка\n");
		}
	} while (w < 0);
	arr = new int*[h];
	for (int i = 0; i < h; i++)
	{
		arr[i] = new int[w];
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			printf("Введите значение элемента[%d][%d]", i + 1, j + 1);
			while (scanf_s("%d%c", &arr[i][j], &c, 1) != 2 || c != '\n')
			{
				printf("Ошибка \n");
				while (getchar() != '\n');
			}
		}
	}
	fakeh = h;
	sequence = 1;
}

void Print(int** arr, int PrintHeight, int PrintWidht, int &sequence) // Вывод на экран
{
	if (sequence == 0)
	{
		printf("Для начала нужно заполнить массив\n");
	}

	for (int i = 0; i < PrintHeight; i++)
	{
		for (int j = 0; j < PrintWidht; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int Sum(int**& a, int &h, int &w, int &sequence) // Сумма 
{
	if (sequence == 0)
	{
		printf("Для начала нужно заполнить массив\n");
	}
	if (sequence == 1)
	{
		int sum = 0;
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < h; i++)
		{
			sum1 = 0;
			sum2 = 0;
			for (int j = 0; j < w; j++)
			{
				if (i > j)
				{
					sum = a[i][j];
					sum1 = sum1 + abs(sum);
					sum2 = sum2 + sum1;
				}
			}
		}
		printf("Сумма модулей : %d\n", sum2);

		return sum2;
	}
}

void Processing(int**& arr, int &h, int &w, int &sequence, int &fakeh) // обработка
{
	if (sequence == 0)
	{
		printf("Для начала нужно заполнить массив\n");
	}
	bool check;

	for (int i = 0; i < h; i++)
	{
		check = true;
		for (int j = 0; j < w; j++)
		{
			if (arr[i][j] >= 0)
			{
				check = false;
			}
		}
		if (check == true)
		{
			for (int k = i; k < h - 1; k++)
			{
				for (int j = 0; j < w; j++)
				{
					arr[k][j] = arr[k + 1][j];
				}
			}
			h--;
			i--;
		}
		
	}

	for (int j = 0; j < w; j++)
	{
		check = true;
		for (int i = 0; i < h; i++)
		{
			if (arr[i][j] >= 0)
			{
				check = false;
			}
		}
		if (check == true)
		{
			for (int k = j; k < w - 1; k++)
			{
				for (int i = 0; i < h; i++)
				{
					arr[i][k] = arr[i][k + 1];
				}
			}
			w--;
			j--;
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	h = fakeh;
}





