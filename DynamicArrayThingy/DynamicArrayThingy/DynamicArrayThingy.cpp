#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
	std::cout << "Динамический массив: ";
	for(int i=0; i<logical_size; i++)
	{
		//if(i = logical_size - 1) 
		//{ 
		//	std::cout << arr[i];		По какой-то причине else не выполняется вообще, почему?
		//}
		//else { std::cout << arr[i] << " "; }
		
		std::cout << arr[i] << " ";
		
	}

	for(int i = logical_size; i< actual_size; i++)
	{
		std::cout << " _";
	}
}

int main()
{
	int fact;
	int logi;

	std::cout << "Введите фактичеcкий размер массива: ";
	std::cin >> fact;
	std::cout << std::endl;

	std::cout << "Введите логический размер массива: ";
	std::cin >> logi;
	std::cout << std::endl;

	int* arr = new int[fact];

	for(int i=0; i<logi; i++)
	{
		std::cout << "arr[" << i << "] :  ";
		std::cin >> arr[i];
	}

	print_dynamic_array(arr, logi, fact);

	return 0;
}