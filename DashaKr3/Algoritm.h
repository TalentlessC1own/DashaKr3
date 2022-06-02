#pragma once
#include "Check.h"
#include "ISort.h"
#include <iomanip>
#include <ctime>
void ConsoleInput(double** matrix, int n, int m);
void RandomInput(double** matrix, int n, int m);
void copy(double** a, double** b, int n, int m);
template <class T> void swap(T& a, T& b)
{
	T c(a); a = b; b = c;
}
void ConsoleOutput(double** matrix, int n, int m);

void ShowResult(std::vector <std::shared_ptr<ISort>>& sorts, int n, int m, double*** matrixs);