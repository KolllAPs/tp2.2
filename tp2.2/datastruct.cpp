#include<iostream>
#include"datastruct.h"

DataStruct::DataStruct() :arr(NULL), size(0) {};

DataStruct::DataStruct(int sz) : arr(new Sign[sz]), size(sz) {};

DataStruct::DataStruct(const DataStruct& dataStruct) {
	this->size = dataStruct.size;
	for (int i = 0; i < size; i++) {
		this->arr[i] = dataStruct.arr[i];
	}
}

DataStruct::~DataStruct() {
	delete[] arr;
}

bool isBigger(int& firstD, int& secondD) {
	
}

DataStruct& DataStruct::operator=(const DataStruct& dataStruct) {
	this->size = dataStruct.size;
	for (int i = 0; i < size; i++) {
		this->arr[i] = dataStruct.arr[i];
	}
}

DataStruct DataStruct::operator+(const Sign& signObject) {
	Sign* temp = new Sign[size + 1];
	for (int i = 0; i < size; i++)
		temp[i] = this->arr[i];
	temp[size] = signObject;
	size += 1;
	delete[] arr;
	arr = temp;
	return *this;
}

DataStruct& operator+=(DataStruct& firstDS, const DataStruct& secondDS) {
	Sign* temp = new Sign[firstDS.size + secondDS.size];
	for (int i = 0; i < firstDS.size; i++)
		temp[i] = firstDS.arr[i];
	for (int i = firstDS.size; i < (firstDS.size + secondDS.size); i++)
		temp[i] = secondDS.arr[i];
	firstDS.size += secondDS.size;
	delete[] firstDS.arr;
	firstDS.arr = temp;
	return firstDS;
}

DataStruct DataStruct::operator-(int index) {
	try {
		if ((this->size - index) < 0)
			throw std::out_of_range("no such element");
	}
	catch (const std::exception& exp) {
		std::cout << exp.what() << std::endl; return
			*this;
	}

	Sign* temp = new Sign[size - index];
	for (int i = 0; i < size - index; i++)
		temp[i] = this->arr[i];
	size -= index;
	delete[] arr;
	arr = temp;
	std::cout << "Element/s was removed" << std::endl;
	return *this;
}

DataStruct& operator-=(DataStruct& dataStruct, int index) {
	index -= 1;
	try {
		if (index < 0 || index > dataStruct.size)
			throw std::out_of_range("no such element");
	}
	catch (const std::exception& exp) {
		std::cout << exp.what() << std::endl; index = 0; 
		return dataStruct;
	}
	DataStruct buf(dataStruct);
	delete[] dataStruct.arr;
	dataStruct.size -= 1;
	dataStruct.arr = new Sign[dataStruct.size];
	for (int i = 0, j = 0; j < buf.size; i++, j++) {
		if (i == index)
			j++;
		dataStruct.arr[i] = buf.arr[j];
	}	return dataStruct;

}

std::ostream& operator<<(std::ostream& output, DataStruct& dataStruct) {
	for (int i = 0; i < dataStruct.size; i++) {
		output << i + 1 << ". " << dataStruct.arr[i].getName() << " " << dataStruct.arr[i].getSurename() <<
			" " << dataStruct.arr[i].getSign()<<" ";
		std::string day, month;
		int* birthday = dataStruct.arr[i].getBirthday();
		if (birthday[0] / 10 == 0)
			output << "0" << birthday[0]<<".";
		else
			output << birthday[0]<<".";
		if (birthday[1] / 10 == 0)
			output << "0" << birthday[1] << ".";
		else
			output << birthday[1] << ".";
		output << birthday[2];
		output<<std::endl;
	}
	return output;
}

void DataStruct::birthdaySort() {
	
}