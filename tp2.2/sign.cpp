#include <iostream>
#include "sign.h"

Sign::Sign() :name(""), surename(""), sign("") {}

Sign::Sign(std::string nm, std::string srnm, std::string sgn, int brthd[]) :
	name(nm), surename(srnm), sign(sgn) {
	for (int i = 0; i < 3; i++) {
		birthday[i] = brthd[i];
	}
}

Sign::Sign(const Sign& signObject) {
	this->name = signObject.name;
	this->surename = signObject.surename;
	this->sign = signObject.sign;
	for (int i = 0; i < 3; i++) {
		this->birthday[i] = signObject.birthday[i];
	}
}

void Sign::setName() {
	std::cin >> this->name;
}

void Sign::setSurename() {
	std::cin >> this->surename;
}

void Sign::setSign() {
	std::cin >> this->sign;
}

void Sign::setBirthday() {
	for (int i = 0; i < 3; i++) {
		std::cin >> this->birthday[i];
	}
}

void Sign::setNameArg(std::string n) { this->name = n; }
void Sign::setSurnameArg(std::string s) { this->surename = s; }
void Sign::setSignArg(std::string sig) { this->sign = sig; }
void Sign::setBirthArg(int b[3]) {
	for (int i = 0; i < 3; i++)
		this->birthday[i] = b[i];
}



std::string& Sign::getName() {
	return name;
}

std::string& Sign::getSurename() {
	return surename;
}

std::string& Sign::getSign() {
	return sign;
}

int Sign::getBirthday(int i) {
	return birthday[i];
}

Sign& Sign::operator=(const Sign& signObject) {
	this->name = signObject.name;
	this->surename = signObject.surename;
	this->sign = signObject.sign;
	for (int i = 0; i < 3; i++) {
		this->birthday[i] = signObject.birthday[i];
	}
	return *this;
}
