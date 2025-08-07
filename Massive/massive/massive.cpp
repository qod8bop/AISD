#include <iostream>



int main()
{
	short mid;
	short amount = 9;
	short pt = 0;
	short arr[9] = { 14,16,19,32,32,32,56,69,72 };
	std::cout << "Введите точку остчёта: ";
	std::cin >> pt;

	short left = 0;
	short right = sizeof(arr) / sizeof(arr[0]) - 1;

	short max = arr[sizeof(arr) / sizeof(arr[0]) - 1];


	while (left < right) 
	{
		 mid = (left + right) / 2;

		if(arr[mid] <= pt)
		{
			if (pt > max) 
			{ 
				amount = 0; 
				break;
			}
			left = mid;
			if (arr[mid + 1] > pt) 
			{ 
				amount = (sizeof(arr) / sizeof(arr[0])-1) - mid;  //при попытке засунуть весь этот код в функцию, эта строка выдаёт предупреждение, а значения высчитываются неправильно.
				break;
			}
		}

		if (arr[mid] > pt)
		{
			right = mid;
		}

	}
	
	std::cout << "Количество элементов в массиве больших, чем " << pt << ": " << amount;

	return 0;
}