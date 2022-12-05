#pragma once
#include<string>
#include<iostream>

class Sign {
	std::string name;
	std::string surename;
	std::string sign;
	
	int birthday[3]={0};
public:
	Sign();
	Sign(std::string, std::string, std::string, int[]);
	Sign(const Sign&);
	~Sign();

	void setName();
	void setSurename();
	void setSign();
	void setBirthday();

	std::string& getName();
	std::string& getSurename();
	std::string& getSign();
	int& getBithday();

};