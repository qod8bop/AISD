# include <iostream>
#include <cmath>

void print_pyramid(int* arr, int size)
{

	std::cout << "Исходный массив: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	int level = 0;
	std::cout << "Пирамида: " << std::endl;

	std::cout << level << "  " << "Root: " << arr[0] << std::endl << std::endl;

	for (int i = 0; i < size; i++)
	{
		level = log2(2 * i + 1 + 1);

		if (2 * i + 2 >= size) { std::cout << level << "  " << "Left (" << arr[i] << ") " << arr[2 * i + 1] << std::endl; break; }
		if (2 * i + 1 >= size) { break; }

		std::cout << level << "  " << "Left (" << arr[i] << ") " << arr[2 * i + 1] << std::endl;
		std::cout << level << "  " << "Right(" << arr[i] << ") " << arr[2 * i + 2] << std::endl;
		std::cout << std::endl;
	}
}



int main()
{
	std::string word;
	std::string choice;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int parent = 0;
	int level = 0;
	int pos = 0;

	print_pyramid(arr, 10);
	std::cout << "Вы находитесь здесь: " << "0 Root " << arr[0]<<std::endl << std::endl;


	while (true)
	{
		std::cout << "Введите команду: ";
		std::cin >> choice;
		

		if(choice == "left")
		{
			pos *= 2;
			pos += 1;
			word = "left";
			level++;
		}

		if(choice == "right")
		{
			pos *= 2;
			pos += 2;
			word = "right";
			level++;
		}

		if(choice == "exit")
		{
			exit(0);
		}

		if(choice == "up")
		{
			pos -= 1;
			if (pos < 0) { std::cout << "Выше поднятся невозможно"; }
			pos /= 2;
			level--;
		}

		parent = (pos - 1) / 2;

		if(pos>=(sizeof(arr)/sizeof(arr[0])))
		{
			std::cout << "Ошибка, отсутсвует наследник" << std::endl;
			level--;
			pos = parent;
			parent = (pos - 1) / 2;
		}


		if (pos == 0) 
		{ 
			word = "Root "; 
			level = 0; 
			std::cout << "Вы находитесь здесь: " << level << "  " << word <<  arr[pos] << std::endl;
		}
		else{ std::cout << "Вы находитесь здесь: " << level << "  " << word << "(" << arr[parent] << ")  " << arr[pos] << std::endl; }

		std::cout << std::endl;
		
	}
}
