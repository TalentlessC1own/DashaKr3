#pragma once
#include<iostream>
#include <string>
#include<fstream>
#include <limits>
int GetPositiveInt();
double CheckLineD(std::ifstream& file);
int CheckLineI(std::ifstream& file);
std::string CheckLineS(std::ifstream& file);
int GetChoise();
int Get3Choise();
double GetDouble();