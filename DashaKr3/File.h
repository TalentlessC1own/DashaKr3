#pragma once
#include "Algoritm.h"
#include "Check.h"
#include <string>
double** InputDataFileInput(int& n, int& m);
void InputDataFileOutput(double** matrix, int n, int m);
void FileOutput(std::vector<std::shared_ptr<ISort>>& sorts, int n, int m, double*** matrixs);