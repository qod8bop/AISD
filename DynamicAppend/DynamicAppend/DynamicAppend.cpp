#include <iostream>


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

int* append_to_dynamic_array(int* arr, int* logical_size, int* actual_size, int appendee)
{
	if (*logical_size != *actual_size)
	{
		
		*logical_size+=1;
		arr[*logical_size - 1] = appendee;

		return arr;
	}
	
	else
	{
		*logical_size = *actual_size;
		*actual_size *= 2;

		int* mas = new int[*actual_size];

		for(int i=0; i<*logical_size; i++)
		{
			mas[i] = arr[i];
		}

		*logical_size += 1;
		mas[*logical_size - 1] = appendee;

		return mas;
	}
}

int main()
{
	int fact;
	int logi;
	int apnd;

	std::cout << "Введите фактичеcкий размер массива: ";
	std::cin >> fact;
	std::cout << std::endl;

	std::cout << "Введите логический размер массива (он должен быть меньше, чем фактический): ";
	std::cin >> logi;
	std::cout << std::endl;

	if (logi > fact)
	{
		std::cout << "Дурак";
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
		std::cout << "Введите элемент для добавления: ";
		std::cin >> apnd;
		if(apnd == 0)
		{
			std::cout << "ББ!";
			exit(0);
		}
		std::cout << std::endl;
		arr = append_to_dynamic_array(arr, &logi, &fact, apnd);
		print_dynamic_array(arr, logi, fact);
		
	}

	return 0;
}