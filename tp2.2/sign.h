#pragma once
#include<string>
#include<iostream>

class Sign {
	std::string name;
	std::string surename;
	std::string sign;

	int birthday[3] = { 0 };
public:
	Sign();
	Sign(std::string, std::string, std::string, int[]);
	Sign(const Sign&);

	Sign& operator=(const Sign&);

	void setName();
	void setSurename();
	void setSign();
	void setBirthday();

	void setNameArg(std::string);
	void setSurnameArg(std::string);
	void setSignArg(std::string);
	void setBirthArg(int[]);


	std::string& getName();
	std::string& getSurename();
	std::string& getSign();
	int getBirthday(int); //0-day, 1-month, 2-year

};