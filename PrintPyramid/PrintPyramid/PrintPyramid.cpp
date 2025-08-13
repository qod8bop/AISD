#include <iostream>
#include <cmath>

void print_pyramid(int* arr, int size)
{

	std::cout << "Исходный массив: ";
	for(int i=0; i<size; i++)
	{
		std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	int level = 0;

	std::cout << level << "  " << "Root: " << arr[0] << std::endl << std::endl;

	for(int i=0; i<size; i++)
	{
		level = log2(2*i + 1 + 1);

		if (2 * i + 2 >= size) { std::cout << level << "  " << "Left (" << arr[i] << ") " << arr[2 * i + 1] << std::endl; break; }
		if (2 * i + 1 >= size) { break; }

		std::cout << level << "  " << "Left (" << arr[i] << ") " << arr[2 * i + 1] << std::endl;
		std::cout << level << "  " << "Right(" << arr[i] << ") " << arr[2 * i + 2] << std::endl;
		std::cout << std::endl;
	}
}


int main()
{

	int arr[8] = { 94, 67, 18, 44, 55, 12, 6, 42 };

	print_pyramid(arr, 8);

	return 0;
}