#include <iostream>

int Fibonaci(int n)	//По памяти 0
{				    
	if (n == 1) { return 0; }	
	if (n == 2) { return 1; }
	else { return (Fibonaci(n - 2) + Fibonaci(n - 1)); }
}					//По времени O(n)  (2 проверки, 1 вывод, всё это вызывается 2n раз -> 6n)

int main()
{
	std::cout << Fibonaci(4);

	return 0;
}
