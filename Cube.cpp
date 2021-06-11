#include "Header.h"
void Cube::DivideCube(std::string str)
{
	int k = 0;
	for (int i = 0; i < (str.size() / 8) && k < str.size(); ++i) {
		std::vector<char> _cube;
		for (int j = 0; j < 8 && k < str.size(); ++j)
			_cube.push_back(str[k++]);
		cube.push_back(_cube);
	}
	int x = 0;
	std::vector<char> _cube;
	for (x = 0; k < str.size(); ++x) {
		_cube.push_back(str[k++]);
	}
	for (; x < 8; ++x) {
		_cube.push_back(' ');
	}
	cube.push_back(_cube);
}
void Cube::RandomGenerator()
{
	std::vector<char> symbol{ 'U', 'D', 'L', 'R' };
	for (int x = 0; x < cube.size(); ++x) {
		std::vector<char> _code;
		for (int i = 0; i < 4; ++i) {
			_code.push_back(symbol[random(0, 3)]);
		}
		code.push_back(_code);
	}
}
void Cube::Rotate_Up(std::vector<char>& v)
{
	std::swap(v[0], v[2]);
	std::swap(v[4], v[6]);
	std::swap(v[2], v[3]);
	std::swap(v[6], v[7]);
	std::swap(v[3], v[1]);
	std::swap(v[7], v[5]);
}
void Cube::Rotate_Down(std::vector<char>& v)
{
	std::swap(v[0], v[1]);
	std::swap(v[4], v[5]);
	std::swap(v[1], v[3]);
	std::swap(v[5], v[7]);
	std::swap(v[3], v[2]);
	std::swap(v[7], v[6]);
}
void Cube::Rotate_Right(std::vector<char>& v)
{
	std::swap(v[0], v[4]);
	std::swap(v[2], v[6]);
	std::swap(v[4], v[5]);
	std::swap(v[6], v[7]);
	std::swap(v[5], v[1]);
	std::swap(v[7], v[3]);
}
void Cube::Rotate_Left(std::vector<char>& v)
{
	std::swap(v[0], v[1]);
	std::swap(v[2], v[3]);
	std::swap(v[1], v[5]);
	std::swap(v[3], v[7]);
	std::swap(v[5], v[4]);
	std::swap(v[7], v[6]);
}
void Cube::Encrypted_cube()
{
	for (int i = 0; i < cube.size(); ++i) {
		for (int j = 0; j < 8; ++j) {
			enc_cube.push_back(cube[i][j]);
		}
	}
	for (int i = 0; i < enc_cube.size(); ++i) {
		std::cout << enc_cube[i];
	}
	std::cout << std::endl;
}
void Cube::Encrypt()
{
	for (int x = 0; x < cube.size(); ++x) {
		for (int i = 0; i < code[x].size(); ++i) {
			if (code[x][i] == 'U') Rotate_Up(cube[x]);
			if (code[x][i] == 'D') Rotate_Down(cube[x]);
			if (code[x][i] == 'L') Rotate_Left(cube[x]);
			if (code[x][i] == 'R') Rotate_Right(cube[x]);
		}
	}
}
void Cube::Print_String() {
	for (int i = 0; i < cube.size(); ++i) {
		for (int j = 0; j < cube[i].size(); ++j) {
			std::cout << cube[i][j];
		}
	}
}
void Cube::Decrypt(std::vector<char>& vec, std::vector<std::vector<char>>& enc_code)
{
	std::vector<std::vector<char>> new_cube;
	for (int i = 0, x = 0; i < vec.size() / 8; ++i) {
		std::vector<char>_new_cube;
		for (int j = 0; j < 8; ++j) {
			_new_cube.push_back(vec[x++]);
		}
		new_cube.push_back(_new_cube);
	}
	for (int i = enc_code.size() - 1; i >= 0; --i) {
		for (int j = enc_code[i].size() - 1; j >= 0; --j) {
			if (enc_code[i][j] == 'U') Rotate_Down(new_cube[i]);
			if (enc_code[i][j] == 'D') Rotate_Up(new_cube[i]);
			if (enc_code[i][j] == 'L') Rotate_Right(new_cube[i]);
			if (enc_code[i][j] == 'R') Rotate_Left(new_cube[i]);
		}
	}
	for (int i = 0; i < new_cube.size(); ++i) {
		for (int j = 0; j < new_cube[i].size(); ++j) {
			std::cout << new_cube[i][j];
		}
	}
	std::cout << std::endl;
}
void Cube::Decryption()
{
	Decrypt(enc_cube, code);
}
void Cube::Encryption(std::string str)
{
	DivideCube(str);
	RandomGenerator();
	Encrypt();
	Encrypted_cube();
}
int Cube::random(int min, int max)
{
	static bool first = true;
	if (first)
	{
		srand(std::time(nullptr));
		first = false;
	}
	return min + rand() % ((max + 1) - min);
}