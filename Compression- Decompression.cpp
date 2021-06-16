#include <iostream>
#include <string>
#include <fstream>

std::string StringCompression(std::string str) {
	std::string fromFile;
	std::string line;
	std::fstream myfile(str);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			fromFile += line;
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";
	int index = 0;
	int count = 1;
	for (int i = 1; i < fromFile.size() + 1; ++i) {
		if (fromFile[i] == fromFile[index])
			++count;
		else {
			if (count > 1) {
				fromFile[index + 1] = '0' + count;
				fromFile[index + 2] = fromFile[i];
				index += 2;
				count = 1;
			}
			else {
				fromFile[index + 1] = fromFile[i];
				++index;
				count = 1;
			}
		}
	}
	fromFile.resize(fromFile.size() - (fromFile.size() - index));
	return fromFile;
}

std::string StringDecompression(std::string str) {
	std::string newstr;
	for (int i = 0; i < str.size(); ++i) {
		char ch = str[i];
		if (isdigit(str[i + 1])) {
			int count = str[i + 1] - '0';
			for (int i = 0; i < count; ++i) {
				newstr += ch;
			}
			++i;
		}
		else {
			newstr += ch;
		}
	}
	str = newstr;
	std::string line;
	std::ofstream myfile("filename1.txt");
	if (myfile.is_open())
	{
		myfile << str;
		myfile.close();
	}
	else std::cout << "Unable to open file";
	return str;
}

int main()
{
	std::cout << StringCompression("filename.txt") << std::endl;
	std::cout << StringDecompression("A5b377vf");
}