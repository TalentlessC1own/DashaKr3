#include "File.h"

double** InputDataFileInput(int &n,int &m)
{
	std::string file_name = "";
	std::ifstream file;
	double** tmp_matrix = nullptr;
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	while (true)
	{
		std::cout << "������� ��� �����. " << std::endl << "���� : ";
		std::cin >> file_name;
		try
		{
			file.open(file_name);
			std::cout << "���� ������ ������� " << std::endl;
		}
		catch (const std::exception&)
		{
			std::cout << "�� ������ ��� ����� ��� ����.��������� ���� " << std::endl;
			continue;


		}
		try
		{
			std::string str;
			n = CheckLineI(file);
			m = CheckLineI(file);
			double** new_matrix = new double* [n];
			for (int k = 0; k < n; k++) {
				new_matrix[k] = new double[m];
			}
			for (int i = 0; i < n; i++) {
				str = CheckLineS(file);
				std::vector<std::string> strin;
				std::string tmp_string;
					for (int j = 0; j <= str.size(); j++) {
						if ((!isdigit(str[j]) && str[j] != '.' && str[j] != '-')||str[j] == '\n')
						{
							strin.push_back(tmp_string);
							tmp_string = "";
						}
						tmp_string += str[j];
					}
					
					for (int k = 0; k < strin.size(); k++) {
						if (strin[k] == " ") {
							strin.erase(strin.begin() + k);
						}
					}
					if (strin.size() != m) {
						throw 1;
					}
					for (int j = 0; j < m; j++) {
						new_matrix[i][j] = stod(strin[j]);
					}
			}
			tmp_matrix = new_matrix;
		}
		catch (int)
		{
			file.close();
			std::cout << "� ����� ���������� ������������ ������" << std::endl;
			continue;
		}
		file.close();
		return tmp_matrix;
	}
}

void InputDataFileOutput(double** matrix, int n, int m)
{
	const int Yes = 1;
	std::string name;
	std::ofstream  FileRecorder;
	FileRecorder.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	std::ifstream CheckExist;
	CheckExist.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	while (true)
	{


		std::cout << "������� ��� ����� ��� ������ ����." << std::endl << "ENTER:";
		std::getline(std::cin, name);
		if (name.find(".txt") >= std::string::npos) {
			std::cout << "�� ������ ��� �����\n" << std::endl;
			continue;
		}
		try
		{
			CheckExist.open(name);
			std::cout << "���� � ����� ������ ����������. " << std::endl
				<< "1 - ������������ ���� ���� " << std::endl
				<< "2 - ������ ����� ��� ����� " << std::endl;
			int var = GetChoise();
			if (var == Yes)
			{
				FileRecorder.open(name);
				CheckExist.close();
			}
			else
			{
				CheckExist.close();
				continue;
			}
		}
		catch (const std::exception&)
		{
			try
			{
				FileRecorder.open(name);
			}
			catch (const std::exception&)
			{
				std::cout << " ������ ���������� " << std::endl;
				continue;
			}

		}
		break;


	}
	FileRecorder << n << std::endl;
	FileRecorder << m << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			FileRecorder << matrix[i][j] << " ";
		FileRecorder << std::endl;
	}
	FileRecorder.close();
	std::cout << "������ ������� ���������" << std::endl;

}


void FileOutput(std::vector<std::shared_ptr<ISort>>& sorts, int n, int m, double*** matrixs)
{
	const int Yes = 1;
	std::string name;
	std::ofstream  FileRecorder;
	FileRecorder.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	std::ifstream CheckExist;
	CheckExist.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	while (true)
	{


		std::cout << "������� ��� ����� ��� ������ ����." << std::endl << "ENTER:";
		std::getline(std::cin, name);
		if (name.find(".txt") >= std::string::npos) {
			std::cout << "�� ������ ��� �����\n" << std::endl;
			continue;
		}
		try
		{
			CheckExist.open(name);
			std::cout << "���� � ����� ������ ����������. " << std::endl
				<< "1 - ������������ ���� ���� " << std::endl
				<< "2 - ������ ����� ��� ����� " << std::endl;
			int var = GetChoise();
			if (var == Yes)
			{
				FileRecorder.open(name);
				CheckExist.close();
			}
			else
			{
				CheckExist.close();
				continue;
			}
		}
		catch (const std::exception&)
		{
			try
			{
				FileRecorder.open(name);
			}
			catch (const std::exception&)
			{
				std::cout << " ������ ���������� " << std::endl;
				continue;
			}

		}
		break;


	}
	FileRecorder << "�������������� �������: " << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				FileRecorder << std::setw(12) << matrixs[0][i][j] << " ";
			FileRecorder << std::endl;
		}
		FileRecorder << std::endl;
	for (int index = 0; index < 5; index++) {
		FileRecorder << "�������� ������ ����������: " << sorts[index]->GetName() << std::endl;
		FileRecorder << "����������� ���������: " << sorts[index]->GetComparison() << std::endl;
		FileRecorder << "����������� ���������: " << sorts[index]->GetPermutation() << std::endl;
	}
	FileRecorder << std::endl;
	FileRecorder << "�������� ������ ����������       ���������        �������������" << std::endl;
	for (int index = 0; index < 5; index++) {
		if (sorts[index]->GetName() == "SelectionSort" || sorts[index]->GetName() == "InsertionSort") {
			FileRecorder << sorts[index]->GetName() << "                        " << sorts[index]->GetComparison() << "                  " << sorts[index]->GetPermutation() << std::endl;
		}
		else if (sorts[index]->GetName() == "BubbleSort") {
			FileRecorder << sorts[index]->GetName() << "                           " << sorts[index]->GetComparison() << "                  " << sorts[index]->GetPermutation() << std::endl;
		}
		else {
			FileRecorder << sorts[index]->GetName() << "                            " << sorts[index]->GetComparison() << "                 " << sorts[index]->GetPermutation() << std::endl;
		}
	}
	std::cout << "������ ������� ���������" << std::endl;

	FileRecorder.close();
}
