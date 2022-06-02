#include "ISort.h"
#include"Algoritm.h"



double** SelectionSort::Sort(double** Matrix, int n, int m)
{
   std::vector< std::vector <NegativeNunb>> negative;
   
   for (int i = 0; i < n; i++)
       negative.push_back(std::vector <NegativeNunb>{});
    name = "SelectionSort";
    double** new_matrix = new double* [n];
    for (int k = 0; k < n; k++) {
        new_matrix[k] = new double[m];
    }
    copy(new_matrix, Matrix, n, m);
    for(int i = 0; i < n; i++)
        for (int j = 0; j < m;j++)
        {
            if (new_matrix[i][j] < 0)
                negative[i].emplace_back(NegativeNunb(new_matrix[i][j], i, j));
        }
    for(int n = 0; n < negative.size();n++)
    for (int i = 0; i < negative[n].size() - 1; i++)
    {
        int tmp = negative[n][i].numb;
        int tmpid = i;
        for (int j = i + 1; j < negative[n].size(); j++)
        {
            comparison_counter++;
            if (negative[n][tmpid].numb > negative[n][j].numb)
            {
                tmp = negative[n][j].numb;
                tmpid = j;
            }
        }
        if (tmpid != i)
        {
            permutation_counter++;
            std::swap(negative[n][i].numb, negative[n][tmpid].numb);
        }
    }
    for (int i = 0; i < negative.size();i++)
        for (int j = 0; j < negative[i].size(); j++)
        {
            new_matrix[negative[i][j].i][negative[i][j].j] = negative[i][j].numb;
        }
   
    return new_matrix;
   
}

double** InsertionSort::Sort(double** Matrix, int n, int m)
{
    std::vector< std::vector <NegativeNunb>> negative;

    for (int i = 0; i < n; i++)
        negative.push_back(std::vector <NegativeNunb>{});
    name = "InsertionSort";
    double** new_matrix = new double* [n];
    for (int k = 0; k < n; k++) {
        new_matrix[k] = new double[m];
    }
    copy(new_matrix, Matrix, n, m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (new_matrix[i][j] < 0)
                negative[i].emplace_back(NegativeNunb(new_matrix[i][j], i, j));
        }
    for (int n = 0; n < negative.size(); n++)
        for (int k = 1; k < negative[n].size(); k++)
        {
            double temp = negative[n][k].numb;
            int j = k - 1;
            comparison_counter++;
            while (j >= 0 && temp < negative[n][j].numb)
            {
                comparison_counter++;
                permutation_counter++;
                negative[n][j + 1].numb = negative[n][j].numb;
                j--;
                if (j == 0)
                    comparison_counter --;

            }
            negative[n][j + 1].numb = temp;
        }
    for (int i = 0; i < negative.size(); i++)
        for (int j = 0; j < negative[i].size(); j++)
        {
            new_matrix[negative[i][j].i][negative[i][j].j] = negative[i][j].numb;
        }
    return new_matrix;
}

double** ShellSort::Sort(double** Matrix, int n, int m)
{
    std::vector< std::vector <NegativeNunb>> negative;

    for (int i = 0; i < n; i++)
        negative.push_back(std::vector <NegativeNunb>{});
    name = "ShellSort";
  
    double** new_matrix = new double* [n];
    for (int k = 0; k < n; k++) {
        new_matrix[k] = new double[m];
    }
    copy(new_matrix, Matrix, n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (new_matrix[i][j] < 0)
                negative[i].emplace_back(NegativeNunb(new_matrix[i][j], i, j));
        }
    
    for (int n = 0; n < negative.size(); n++)
    {
        for (int gap = negative[n].size(); gap > 0; gap /= 2) {
            for (int i = gap; i < negative[n].size(); i++) {

                double temp = negative[n][i].numb;
                int k = i;
                comparison_counter++;
                for (k = i; k >= gap && negative[n][k - gap].numb > temp; k -= gap) {
                    negative[n][k].numb = negative[n][k - gap].numb; permutation_counter++;
                    if (k == gap)
                        comparison_counter--;
                }
                negative[n][k].numb = temp;
            }
        }
    }
    for (int i = 0; i < negative.size(); i++)
        for (int j = 0; j < negative[i].size(); j++)
        {
            new_matrix[negative[i][j].i][negative[i][j].j] = negative[i][j].numb;
        }
    return new_matrix;
}
double** BubbleSort::Sort(double** Matrix, int n, int m)
{
    std::vector< std::vector <NegativeNunb>> negative;

    for (int i = 0; i < n; i++)
        negative.push_back(std::vector <NegativeNunb>{});
    name = "BubbleSort";
    
    double** new_matrix = new double* [n];
    for (int k = 0; k < n; k++) {
        new_matrix[k] = new double[m];
    }
    copy(new_matrix, Matrix, n, m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (new_matrix[i][j] < 0)
                negative[i].emplace_back(NegativeNunb(new_matrix[i][j], i, j));
        }
    for (int n = 0; n < negative.size(); n++){
        for (int j = 0; j < negative[n].size() - 1; j++) {
            bool flag = true;
            for (int k = 0; k < negative[n].size() - (j + 1); k++) {
                comparison_counter++;
                if (negative[n][k].numb > negative[n][k + 1].numb) {
                    flag = false;
                    swap(negative[n][k].numb, negative[n][k + 1].numb);
                    permutation_counter++;
                }
            }
            if (flag) {
                break;
            }
        }
    }
    for (int i = 0; i < negative.size(); i++)
        for (int j = 0; j < negative[i].size(); j++)
        {
            new_matrix[negative[i][j].i][negative[i][j].j] = negative[i][j].numb;
        }
    return new_matrix;
}

void QuickSortMat::QuickSort(std::vector <NegativeNunb>& arr, int start, int end)
{
    if (start < end) {
        int p = Partition(arr, start, end);
        QuickSort(arr, start, p - 1);
        QuickSort(arr, p + 1, end);
    }
    
}

int QuickSortMat::Partition(std::vector <NegativeNunb>& arr, int start, int end)
{
    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i) {
        comparison_counter++;
        if (arr[i].numb < arr[pivot].numb) {
            permutation_counter++;
            swap(arr[i].numb, arr[j].numb);
            ++j;
        }
    }
   
        swap(arr[j].numb, arr[pivot].numb);
        if (permutation_counter > 0)
            permutation_counter ++;
  
    return j;

}

double** QuickSortMat::Sort(double** Matrix, int n, int m)
{
    std::vector< std::vector <NegativeNunb>> negative;
    for (int i = 0; i < n; i++)
        negative.push_back(std::vector <NegativeNunb>{});
    name = "QuickSort";
    
    double** new_matrix = new double* [n];
    for (int k = 0; k < n; k++) {
        new_matrix[k] = new double[m]; 
    }
   copy(new_matrix, Matrix, n, m);

   for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++)
       {
           if (new_matrix[i][j] < 0)
               negative[i].emplace_back(NegativeNunb(new_matrix[i][j], i, j));
       }
   for (int i = 0; i < negative.size(); i++) {
           QuickSort(negative[i], 0, negative[i].size() - 1);
   }
   for (int i = 0; i < negative.size(); i++)
       for (int j = 0; j < negative[i].size(); j++)
       {
           new_matrix[negative[i][j].i][negative[i][j].j] = negative[i][j].numb;
       }
   return new_matrix;
}

std::string ISort::GetName()
{
    return name;
}

int ISort::GetComparison()
{
    return comparison_counter;
}

int ISort::GetPermutation()
{
    return permutation_counter;
}
