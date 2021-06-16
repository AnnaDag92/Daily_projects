#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

class Cube
{
public:
	void Encryption(std::string);
	void Decryption();
private:
	void DivideCube(std::string);
	void RandomGenerator();
	void Encrypt();
	void Decrypt(std::vector<char>&, std::vector<std::vector<char>>&);
	void Encrypted_cube();
	void Rotate_Up(std::vector<char>&);
	void Rotate_Down(std::vector<char>&);
	void Rotate_Left(std::vector<char>&);
	void Rotate_Right(std::vector<char>&);
	void Print_String();
	int random(int, int);

private:
	std::vector<std::vector<char>> cube;
	std::vector<std::vector<char>> code;
	std::vector<char> enc_cube;
};
