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

DataStruct& DataStruct::operator=(const DataStruct& dataStruct) {
	this->size = dataStruct.size;
	for (int i = 0; i < size; i++) {
		this->arr[i] = dataStruct.arr[i];
	}
}
