#include <iostream>

void PrintArray(int* arr, int n)
{
	std::cout << "массив: ";
	for(int i=0; i<n; i++)
	{
		std::cout << arr[i] << " ";
	}
}


void merge(int* arr, int left, int mid, int right)
{
	int* hlp = new int[right - left];
	int it1 = 0;
	int it2 = 0;

	while(left + it1<mid && mid + it2<right)
	{
		if(arr[left + it1] < arr[mid + it2])
		{
			hlp[it1 + it2] = arr[left + it1];
			it1++;
		}

		else
		{
			hlp[it1 + it2] = arr[mid + it2];
			it2++;
		}
	}

	while(left+it1 < mid)
	{
		hlp[it1 + it2] = arr[left + it1];
		it1++;
	}

	while (left + it1 < mid)
	{
		hlp[it1 + it2] = arr[mid + it2];
		it2++;
	}

	for(int i=0; i < it1+it2; i++)
	{
		arr[left + i] = hlp[i];
	}

	delete[] hlp;
}




void merge_sort_recursive(int* arr, int left, int right)
{
	if (left + 1 >= right) { return; }

	int mid = (left + right) / 2;

	merge_sort_recursive(arr, left, mid);
	merge_sort_recursive(arr, mid, right);
	merge(arr, left, mid, right);
}





void merge_sort(int* arr, int size)
{
	merge_sort_recursive(arr, 0, size);
	std::cout << "Отсортированный ";
	PrintArray(arr, 10);
}



int main()
{
	int mas[10] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
	std::cout << "Исходный ";
	PrintArray(mas, 10);
	std::cout << std::endl;

	merge_sort(mas, 10);

	std::cout << std::endl << std::endl;
	std::cout << std::endl << std::endl;

	int msa[15] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	std::cout << "Исходный ";
	PrintArray(msa, 15);
	std::cout << std::endl;

	merge_sort(msa, 15);

	std::cout << std::endl << std::endl;
	std::cout << std::endl << std::endl;

	int sam[18] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	std::cout << "Исходный ";
	PrintArray(sam, 18);
	std::cout << std::endl;

	merge_sort(sam, 18);

	return 0;
}