#include <iostream>


int find_substring_light_rabin_karp(std::string line, std::string subline)
{
	bool correct = true;

	for (int i = 0; i < line.length(); i++)
	{

		for (int j = 0; j < subline.length(); j++)
		{
			if (line[i + j] != subline[j])
			{
				correct = false;
			}
		}
		if (correct) { return i; }
	}

	return -1;
}


int main()
{
	std::string subline;
	std::string line;

	std::cout << "Введите строку, в которой будет осуществляться поиск: ";
	std::cin >> line;

	std::cout << "Введите подстроку, которую нужно найти: ";
	std::cin >> subline;

	switch (find_substring_light_rabin_karp(line, subline))
	{
	case -1:
		std::cout << "Не найдено";
		break;
	default:
		std::cout << "Подстрока найдена. Индекс: " << find_substring_light_rabin_karp(line, subline);
	}



	return 0;
}