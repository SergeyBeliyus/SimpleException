#include <iostream>
#include "windows.h"

int function(std::string str, int forbidden_length) {
	int strSize;
	if (str.length() == forbidden_length) {
		throw std::length_error("Вы ввели слово запретной длины! До свидания");
	}
	strSize = str.length();
	return strSize;
}

int main() {
	int size;
	std::string str;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "Введите запретную длину: ";
	std::cin >> size;

	bool pass = true;

	while (pass) {
		std::cout << "Введите слово: ";
		std::cin >> str;
		try {
			std::cout << "Длина слова '" << str << "' равна " << function(str, size) << "\n";
		}
		catch (const std::length_error &err) {
			std::cout << err.what();
			pass = false;
		}
	}
}