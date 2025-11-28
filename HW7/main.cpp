#include <iostream>
#include <string>
#include <Windows.h>

bool Find(std::string words, std::string search) {
	if (words.find(search) != std::string::npos) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string words, search;
	std::cout << "Введите предложение\n>>: ";
	std::getline(std::cin, words, '\n');
	//2
	if (words.empty()) {
		std::cout << "Строка пуста!\n";
	}
	else {
		//1 работает только на английском :c
		bool newWord = true;
		for (int i = 0; i < words.size(); i++) {
			if (words[i] == ' ') {
				newWord = true;
				continue;
			}
			if (newWord) {
				words[i] = std::toupper(words[i]);
				newWord = false;
			}
			else {
				words[i] = std::tolower(words[i]);
			}
			
		}
		std::cout << "После 1-го форматирования получилось: " << words << "\n";
		//3
		if (words.back() != '.') {
			words += '.';
		}
		std::cout << "После 2-го форматирования получилось: " << words << "\n";
		//4
		std::cout << "Введите искоиое слово\n>>: ";
		std::getline(std::cin, search, '\n');
		if (Find(words, search) == 1) {
			std::cout << "Такое слово есть!";
		}
		else {
			std::cout << "Такого слова нет!";
		}
	}
	
	
	//5
}