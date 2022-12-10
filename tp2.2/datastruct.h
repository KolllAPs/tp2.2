#pragma once
#include"sign.h"

enum gr { less_ = 0, great_ };

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
	DataStruct operator+(const Sign&); //st + sign
	friend DataStruct& operator+=(DataStruct&, const DataStruct&); //st + st
	DataStruct operator-(int); //удаление x последних
	friend DataStruct& operator-=(DataStruct&, int); //удаление по индексу

	friend std::ostream& operator<<(std::ostream&, DataStruct&);

	void birthdaySort(gr);
	void getBySurename(std::string);
	void getByIndex(int);
	void save(std::string);
	void extract(std::string);

};