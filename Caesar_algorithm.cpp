#include <iostream>
#include "Cesar_algorithm.h"

Caesar::Caesar(const std::string& new_sourse_text, const size_t& new_key)
	:sourse_text{new_sourse_text}
	,key{new_key} 
{

};

void Caesar::setSourse_text(const std::string& new_sourse_text) {
	sourse_text = new_sourse_text;
}

std::string Caesar::getSourse_text() {
	return sourse_text;
}

void Caesar::setKey(const size_t& new_key) {
	key = new_key;
}
size_t Caesar::getKey() {
	return key;
}
	
void Caesar::encrypt(const std::string& text, size_t key) {
	unsigned size = text.size();
	char formatted_text[size + 1];
	for(size_t i = 0; i < size; ++i) {
		char ch = text[i];
		if(ch == ' ') {
			formatted_text[i] = ' ';
		} else if (ch + key >= 'Z' && ch <= ('a' - 1) || ch + key > 'z'){
			ch += key - am_letter_count;
			formatted_text[i] = ch;
		} else {
			ch += key;
			formatted_text[i] = ch;
		}
	}
	formatted_text[size] = '\0';
	std::cout << formatted_text << std::endl;
}

void Caesar::decrypt(const std::string& text, size_t key) {
	unsigned size = text.size();
	char sourse_text[size + 1];
	for(size_t i = 0; i < size; ++i) {
		char ch = text[i];
		if(ch == ' ') {
			sourse_text[i] = ' ';
		}  

		if(ch >= 'a' && ch <= 'z') {
			if(ch - key >= 'a') {
				ch -= key;
				sourse_text[i] = ch;
			} else {
				ch -=key + am_letter_count;
				sourse_text[i] = ch;
			}
		}
		if(ch >= 'A' && ch <= 'Z') {
			if(ch - key >= 'A') {
				ch -= key;
				sourse_text[i] = ch;
			} else {
				ch -= key + am_letter_count;
				sourse_text[i] = ch;
			}
		}
	}
	sourse_text[size] = '\0';
	std::cout << sourse_text << std::endl;
}



