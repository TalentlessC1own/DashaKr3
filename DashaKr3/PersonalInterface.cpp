#include "PersonalInterface.h"


void ShowGreetings()
{
	std::cout << "����������� ������ �3 ������� ��������� 415�" << std::endl;
}


void ShowInputChoice()
{
	std::cout << "��� ���� ������ ������� ������������?" << std::endl;
	std::cout << "1)����������" << std::endl;
	std::cout << "2)���������� �������" << std::endl;
	std::cout << "3)��������" << std::endl;
}
void ShowInputOutType()
{
	std::cout << "�� ������ ��������� �������� ������ � ����?" << std::endl;
	std::cout << "1)��" << std::endl;
	std::cout << "2)���" << std::endl;
	
}
void ShowOutputChoise()
{
	std::cout << "�� ������ ������������ ������ ����?" << std::endl;
	std::cout << "1)��" << std::endl;
	std::cout << "2)������ ����� ���(���� � �����)" << std::endl;
}
void ShowOutputType() {
	std::cout << "�� ������ �������� ������ � ����?" << std::endl;
	std::cout << "1)��" << std::endl;
	std::cout << "2)���" << std::endl;
}

void Showtask()
{
	std::cout << "����������� ������ ������ ������� �� ����������� ���������� �������,�������� ���������� ���������� � � ��������� ������� ������������" << std::endl;
}

void ShowMenuPoint(int* n,int* m)
{
	std::cout << "������� ����������� �������(n �� m):" << std::endl;
	std::cout << "n=";
	*n = GetPositiveInt();
	std::cout << "m="; *m = GetPositiveInt();
}
