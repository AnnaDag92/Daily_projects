#include <iostream>

std::string CheckPassword(std::string str) {
	int password_min_size = 8;
	int password_max_size = 24;
	int upper_min_quantity = 2;
	int lower_min_quantity = 2;
	int symbols_quantity = 2;
	if (str.size() < password_min_size || str.size() > password_max_size) {
		std::cout << "Password length should be from 8 to 24 symbols" << std::endl;
		return " ";
	}
	int count_upper = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] >= 65 && str[i] <= 90) ++count_upper;
	}
	if (count_upper < upper_min_quantity) {
		std::cout << "Password should have min 2 UpperCases" << std::endl;
		return " ";
	}
	int count_lower = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] >= 97 && str[i] <= 122) ++count_lower;
	}
	if (count_lower < lower_min_quantity) {
		std::cout << "Password should have min 2 LowerCases" << std::endl;
		return " ";
	}
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == 40 || str[i] == 42) {
			std::cout << "Password sholdn't include * or (" << std::endl;
			return " ";
		}
	}
	int count_symbols = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] >= 0 && str[i] <= 39 || str[i] >= 43 && str[i] <= 47 || str[i] >= 58 && str[i] <= 64 || str[i] >= 91 && str[i] <= 96 || str[i] >= 123 && str[i] <= 255  ) ++count_symbols;
	}
	if (count_symbols != symbols_quantity) {
		std::cout << "Password should have 2 symbols" << std::endl;
		return " ";
	}
	return str;
}

int main()
{
	std::cout << "Enter a password, please!" << std::endl;
	std::string str;
	std::cin >> str;
	CheckPassword(str);
}