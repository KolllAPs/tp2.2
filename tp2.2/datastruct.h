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
	DataStruct& operator+=(DataStruct&,const DataStruct&);
	DataStruct operator-(int);
	DataStruct& operator-=(const Sign&);

	friend std::ostream& operator<<(std::ostream&, DataStruct&);
		
	void birthdaySort();
	void getBySurename();
	void getByIndex();
	void save();
	void extract();

};