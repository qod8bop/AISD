#include <iostream>


void real_string_hash(unsigned long long p, int n, std::string line)
{
	unsigned long long code = 0;

	for(int i=0; i< line.length(); i++)
	{
		code = code + line[i] * p;
		p *= p;
	}

	std::cout << "Хеш строки " << line << " = " << code % n;
}


int main()
{
	int p = 0;
	int n = 0;
	std::string line;

	while(true)
	{
		std::cout << "Введите p: ";
		std::cin >> p;
		std::cout << "Введите n: ";
		std::cin >> n;

		std::cout << "Введите строку: ";
		std::cin >> line;

		if(line == "exit")
		{
			real_string_hash(p, n, line);
			exit(0);
		}

		real_string_hash(p,n,line);
		std::cout << std::endl << std::endl;
	}

	return 0;
}