#include <cmath>
#include <iostream>
#include <string>
#include "bdconverter.hpp"

BDConverter::BDConverter(std::string s): str_(s)
{
}

void BDConverter::GetInput(std::string s) {
	str_ = s;
}

bool BDConverter::IsDecimal() {
	bool decimal = false;

	for (int i = 0; i < str_.size(); i++) {
		if ((str_[i] - '0') > 1) {
			decimal = true;
			break;
		}
	}

	return decimal;
}

void BDConverter::ShowB2D() {
	int decimal = std::stoi(str_, nullptr, 2);

	std::cout << "BIN " << str_ << " = " << decimal << std::endl;
	ShowD2B();
}

void BDConverter::ShowD2B() {
	std::string binary = "";
	int decimal = std::stoi(str_, nullptr, 10);

	while (decimal > 0) {
		binary = (char)(decimal % 2 + '0') + binary;	// Can't use std::to_string in my g++ compiler.
		decimal /= 2;
	}

	std::cout << "DEC " << str_ << " = " << binary << std::endl;
}
