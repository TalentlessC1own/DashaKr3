#include <iostream>
#include<vector>
#include"Algoritm.h"
#include"PersonalInterface.h"
#include "Check.h"
#include"ISort.h"
#include "File.h"
#include <memory>
#include <string>
#include <conio.h>
#define QUIT 27//Присваивание Esc значение 27
enum YesOrNo
{
	yes = 1,
	no = 2,
};
int main(void) {
	setlocale(LC_CTYPE, "RU");
	const int manual_input = 1;
	const int random_input = 2;
	const int file_input = 3;
	const int sorts_count = 5;
	int n=0;
	int m=0;
	int UserChoice = 0;

	std::vector <std::shared_ptr<ISort>> sorts;
	sorts.emplace_back(std::make_shared <QuickSortMat>());
	sorts.emplace_back(std::make_shared <BubbleSort>());
	sorts.emplace_back(std::make_shared <ShellSort>());
	sorts.emplace_back(std::make_shared <SelectionSort>());
	sorts.emplace_back(std::make_shared <InsertionSort>());
	do {

		ShowGreetings();//Приветствие
		Showtask();//Задание
		ShowInputChoice();//Выбор ввода
		UserChoice = Get3Choise();
		double***  Matrix = nullptr;
		


		switch (UserChoice)
		{
		case  (manual_input):
			ShowMenuPoint(&n, &m);
			Matrix = new double** [sorts_count];
			for (int j = 0; j < sorts_count; j++)
			{
				Matrix[j] = new double* [n];
				for (int i = 0; i < n; i++) {
					Matrix[j][i] = new double[m];
				}
			}
			 std::cout << "Введите данные" << std::endl;
			 ConsoleInput(Matrix[0], n, m);
			 break;
		case random_input:
			ShowMenuPoint(&n, &m);
			Matrix = new double** [sorts_count];
			for (int j = 0; j < sorts_count; j++)
			{
				Matrix[j] = new double* [n];
				for (int i = 0; i < n; i++) {
					Matrix[j][i] = new double[m];
				}
			}
				RandomInput(Matrix[0], n, m);
				break;
		case (file_input):
			//ShowMenuPoint(&n, &m);
			Matrix = new double** [sorts_count];
			for (int j = 0; j < sorts_count; j++)
			{
				Matrix[j] = new double* [n];
				for (int i = 0; i < n; i++) {
					Matrix[j][i] = new double[m];
				}
			}
			Matrix[0] = InputDataFileInput(n, m);
			break;
		}
		std::cout << "Исходная матрица" << std::endl;
		ConsoleOutput(Matrix[0], n, m);
		if (UserChoice == manual_input || UserChoice == random_input) {
			ShowInputOutType();
			UserChoice = GetChoise();
			if (UserChoice == yes) {
				InputDataFileOutput(Matrix[0], n, m);
			}
		}
		for (int i = 1; i < sorts_count; i++)
		{	
			memcpy(Matrix[i], Matrix[0], sizeof(Matrix[i]) * n);
		}

		for (int i = 0; i < sorts_count; i++)
		{
			Matrix[i] = sorts[i]->Sort(Matrix[i], n, m);
		}
		ShowResult(sorts, n, m, Matrix);
		ShowOutputType();
		UserChoice = GetChoise();
		if (UserChoice == yes) {
			FileOutput(sorts, n, m , Matrix);
		}
		std::cout << "Нажмите Esc чтобы завершить работу программы." << std::endl;
		std::cout << "Нажмите Enter чтобы продолжить." << std::endl;
		for (int i = 0; i < n; i++)
			delete[]Matrix[i];
		delete[] Matrix;
		Matrix = nullptr;
		UserChoice = _getch();
	} while (UserChoice != QUIT);

	return 0;
}
