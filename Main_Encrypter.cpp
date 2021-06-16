#include "Header.h"

int main() 
{
	std::cout << "Enter your string, please!" << std::endl;
	std::string str;
	std::getline(std::cin, str);
	Cube c;
	c.Encryption(str);
	c.Decryption();
}
