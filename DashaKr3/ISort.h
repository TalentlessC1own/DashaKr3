#pragma once
#include <math.h>
#include <iostream>
#include <vector>
#include "NegativeNunb.h"

class ISort
{
protected:
	std::string name;
	int comparison_counter = 0;
	int permutation_counter = 0;
public:
	virtual double** Sort(double** Matrix,int n,int m) = 0;
	~ISort()=default;
	std::string GetName();
	int GetComparison();
	int GetPermutation();
};
class BubbleSort :public ISort {
public:
	double** Sort(double** Matrix, int n, int m) override;
};
class SelectionSort :public ISort {

public:
	double** Sort(double** Matrix, int n, int m)override;

};
class InsertionSort :public ISort {

public:
	double** Sort(double** Matrix, int n, int m)override;
};
class ShellSort :public ISort {
public:
	double** Sort(double** Matrix, int n, int m)override;
};
class QuickSortMat :public ISort {
private:
	void QuickSort(std::vector <NegativeNunb>& arr, int start, int end);
	int Partition(std::vector <NegativeNunb>&  arr, int start, int end);
public:
	double**  Sort(double** Matrix, int n, int m)override;
	
};