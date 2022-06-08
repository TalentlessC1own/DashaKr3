#include "Check.h"
int GetPositiveInt()
{

    while (true) {
        int value;
        try {
            if (std::cin >> value, std::cin.good()&&value>0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
              
            }
            else {
                throw std::invalid_argument("Были введены не корректные данные. Повторите ввод.");
            }
        }
        catch (std::invalid_argument& e) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << e.what() << std::endl;
        }
    }
}
double CheckLineD(std::ifstream& file)
{
    std::string temp_v = "";
    double temp_d = 0.0;
    try
    {
        std::getline(file, temp_v);

    }
    catch (const std::exception&)
    {
        std::cout << "Произошла ошибка при чтении информации из фаила: " << std::endl;
        throw std::invalid_argument("Были введены не корректные данные. Повторите ввод.");

    }
    try
    {
        temp_d = stod(temp_v);

            return temp_d;
    }
    catch (std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
        throw 1;
    }
}
int CheckLineI(std::ifstream& file)
{
    std::string temp_v = "";
    int temp_d = 0;
    try
    {
        std::getline(file, temp_v);

    }
    catch (const std::exception&)
    {
        std::cout << "Произошла ошибка при чтении информации из фаила: " << std::endl;
        throw 1;

    }
    try
    {
        temp_d = stoi(temp_v);
        if (temp_d <= 0)

        {
            throw  1;
        }
        else {
            return temp_d;
        }
    }
    catch (const std::exception&)
    {
        std::cout << "Не верный тип данных" << std::endl;
        throw 1;
    }
}
std::string CheckLineS(std::ifstream& file)
{
    std::string temp_v = "";
    try
    {
        std::getline(file, temp_v);
        return temp_v;

    }
    catch (const std::exception&)
    {
        std::cout << "Произошла ошибка при чтении информации из фаила:" << std::endl;
        throw 1;

    }
}
int Get3Choise()
{

    while (true) {
        try {

            int value = 0;
            std::cin >> value;
            if (value == 1 || value == 2||value==3) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;

            }
            else {
                throw std::invalid_argument("Были введены не корректные данные. Повторите ввод.");
            }
        }
     
        catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }
    }
}
int GetChoise()
{

    while (true) {
        try {

            int value = 0;
            std::cin >> value;
            if (value == 1 || value == 2) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;

            }
            else {
                throw std::invalid_argument("Были введены не корректные данные. Повторите ввод.");
            }
        }
      
        catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }
    }
}
double GetDouble()
{
    while (true) {
        double value=0.;
        try {
            if (std::cin >> value, std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
        }
            else {
                throw std::invalid_argument("Были введены не корректные данные. Повторите ввод.");
            }
        }
        catch (std::invalid_argument& e) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << e.what() << std::endl;
        }
    }
}
