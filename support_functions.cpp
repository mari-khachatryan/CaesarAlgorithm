#include <iostream>
#include "Cesar_algorithm.h"
#include "support_functions.h"

void start() {
	size_t choice_num{};
	size_t key{};
	std::string text;
	std::cout << "For encrypt or dycrypt text by Caesar algorithm please enter text and choose option!\n";
	std::cout << "In first enter text\n";
	while (true)
	{
		std::cin >> text;
		if(check_text(text)) {
			break;
		} else {
			std::cout << "Please enter correct text, there are not-letter symbols!" << std::endl;
		}
	}
	std::cout << "And enter the size of letter move: ";
	while (true)
	{
		std::cin >> key;
		if(check_key(key)) {
			break;
		} else {
			std::cout << "Please enter correct number!" << std::endl;
		}
	}
	std::cout << "For encrypt text, please enter 1 \n";
	std::cout << "For dycrypt text , please enter 2 \n";
	std::cin >> choice_num;
	Caesar alg(text, key);

	switch(choice_num){
		case 1:
			alg.encrypt(text, key);
			break;
		case 2:
			alg.decrypt(text, key);
			break;
		default:
			std::cout << "Please enter correct option!";
			break;
	}

}

bool check_text(const std::string& text) {
	for (size_t i = 0; i < text.size(); ++i) {
		if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z') || text[i] == ' ') {
			continue;
		} else {
			return false;
		}
	}
	return true;
}

bool check_key(const size_t& key) {
	const unsigned am_letter_count = 26;
	if(key < 0 || key > am_letter_count) {
		return false;
	}
	return true;
}