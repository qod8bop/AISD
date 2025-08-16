#include <iostream>


void simple_string_hash(std::string line)
{
	int code = 0;
	for(int i=0; i<line.length();i++)
	{
		code +=	line[i];
	}
	
	std::cout << "Наивный хеш строки " << line << " = " << code;
}


int main()
{
	std::string line;

	while(true)
	{
		std::cout << "Введите строку: ";
		std::cin >> line;
		if(line == "exit")
		{
			simple_string_hash(line);
			exit(0);
		}
		simple_string_hash(line);
		std::cout << std::endl;
		std::cout << std::endl;
	}

	return 0;
}