#include <iostream>
#include <string>
#include <Windows.h>

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
	std::cout << "Динамический массив: ";
	for (int i = 0; i < logical_size; i++)
	{
		std::cout << arr[i] << " ";
	}

	for (int i = logical_size; i < actual_size; i++)
	{
		std::cout << " _";
	}
}

int* eraser(int* arr, int* fact, int* logi)
{
	if(*logi == 1)
	{
		std::cout << "Ничего не осталось";
		exit(0);
	}

	if (*logi - 1 > *fact / 3)
	{
		std::cout << "РАЮОТАЯ";
		*logi -= 1;
		for(int i=0; i<*logi; i++)
		{
			arr[i] = arr[i + 1];
		}

		return arr;
	}

	else 
	{
		*fact /= 3;
		*logi -= 1;

		int* mas = new int[*fact];

		for(int i = 0; i<*logi;i++)
		{
			mas[i] = arr[i + 1];
		}

		return mas;
	}
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(CP_UTF8);


	int fact;
	int logi;
	// static char* choice; 
	int choice;


	std::cout << "Введите фактичеcкий размер массива: ";
	std::cin >> fact;
	std::cout << std::endl;

	std::cout << "Введите логический размер массива: ";
	std::cin >> logi;
	std::cout << std::endl;

	if (logi > fact)
	{
		exit(0);
	}

	int* arr = new int[fact];

	for (int i = 0; i < logi; i++)
	{
		std::cout << "arr[" << i << "] :  ";
		std::cin >> arr[i];
	}

	print_dynamic_array(arr, logi, fact);

	while(true)
	{
		std::cout << std::endl;
		std::cout << "Удалить первый элемент?\n";
		std::cout << "1 - ДА\n";
		std::cout << "2 - НЕТ\n";
		std::cout << "Выбор: ";
		std::cin >> choice;

		if(choice == 1) //При использовании слов да, вместо цифр, оба последующих блока кода отказывались рабоать.
		{
			arr = eraser(arr, &fact, &logi);
			print_dynamic_array(arr, logi, fact);
		}
		else
		{
			std::cout << "ББ!";
			exit(0);
		}
	}

	return 0;
};