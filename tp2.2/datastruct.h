#pragma once
#include"sign.h"

class DataStruct {
private:
	Sign* arr;
	int size;
public:
	DataStruct();
	DataStruct(int);
	DataStruct(const DataStruct&);
	~DataStruct();

	DataStruct& operator=(const DataStruct&);
	DataStruct operator+(const Sign&);
	DataStruct& operator+=(const Sign&);
	DataStruct operator-(int);
	DataStruct& operator-=(const Sign&);

	void input(int);
	void output();
};