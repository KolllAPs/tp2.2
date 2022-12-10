#include<iostream>
#include <utility>
#include<fstream>
#include"datastruct.h"

bool compare_by_date(Sign s1, Sign s2);

DataStruct::DataStruct() :arr(NULL), size(0) {};

DataStruct::DataStruct(int sz) : arr(new Sign[sz]), size(sz) {};

DataStruct::DataStruct(const DataStruct& dataStruct) {
	this->size = dataStruct.size;
	this->arr = new Sign[size];
	for (int i = 0; i < size; i++)
		this->arr[i] = dataStruct.arr[i];
}

DataStruct::~DataStruct() { delete[] arr; }

bool isBigger(int* firstD, int* secondD) {
	if (firstD[2] > secondD[2])
		return true;
	else if (firstD[2] < secondD[2])
		return false;
	else {
		if (firstD[1] > secondD[1])
			return true;
		else if (firstD[1] < secondD[1])
			return false;
		else {
			if (firstD[0] >= secondD[0])
				return true;
			else
				return false;
		}
	}
}

DataStruct& DataStruct::operator=(const DataStruct& dataStruct) {
	this->size = dataStruct.size;
	this->arr = new Sign[size];
	for (int i = 0; i < size; i++) {
		this->arr[i] = dataStruct.arr[i];
	}
	return *this;
}

DataStruct DataStruct::operator+(const Sign& signObject) {
	DataStruct buf;
	buf.size = this->size + 1;
	buf.arr = new Sign[buf.size];
	for (int i = 0; i < this->size; i++)
		buf.arr[i] = this->arr[i];
	buf.arr[buf.size - 1] = signObject;
	return buf;
}

DataStruct& operator+=(DataStruct& obj, const DataStruct& arg) {
	DataStruct buf(obj);
	delete[] obj.arr;
	obj.size = obj.size + arg.size;
	obj.arr = new Sign[obj.size];
	int id;
	for (id = 0; id < buf.size; id++)
		obj.arr[id] = buf.arr[id];
	for (int j = 0; j < (arg.arr == obj.arr ? arg.size / 2 : arg.size); j++, id++)
		obj.arr[id] = arg.arr[j];
	return obj;
}

DataStruct DataStruct::operator-(int index) {
	DataStruct buf;
	try {
		if ((this->size - index) < 0)
			throw std::out_of_range("no such element");
	}
	catch (const std::exception& exp) {
		std::cout << exp.what() << std::endl; return *this;
	}
	buf.size = this->size - index;
	buf.arr = new Sign[buf.size];
	for (int i = 0; i < buf.size; i++)
		buf.arr[i] = this->arr[i];
	return buf;
}

DataStruct& operator-=(DataStruct& obj, int index) {
	index -= 1;
	try {
		if (index < 0 || index > obj.size)
			throw std::out_of_range("no such element");
	}
	catch (const std::exception& exp) {
		std::cout << exp.what() << std::endl; index = 0;
		return obj;
	}

	DataStruct buf(obj);
	delete[] obj.arr;
	obj.size -= 1;
	obj.arr = new Sign[obj.size];

	for (int i = 0, j = 0; j < buf.size; i++, j++) {
		if (i == index)
			j++;
		obj.arr[i] = buf.arr[j];
	}
	return obj;
}

std::ostream& operator<<(std::ostream& output, DataStruct& dataStruct) {
	for (int i = 0; i < dataStruct.size; i++) {
		output << i + 1 << ". " << dataStruct.arr[i].getName() << " " << dataStruct.arr[i].getSurename() <<
			" " << dataStruct.arr[i].getSign() << " ";

		int data = dataStruct.arr[i].getBirthday(0); //day
		if (data / 10 == 0)
			output << "0" << data << ".";
		else
			output << data << ".";

		data = dataStruct.arr[i].getBirthday(1); //month
		if (data / 10 == 0)
			output << "0" << data << ".";
		else
			output << data << ".";
		output << dataStruct.arr[i].getBirthday(2); //year
		output << std::endl;
	}
	return output;
}

void DataStruct::birthdaySort(gr gr_) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (gr_ ? (compare_by_date(arr[i], arr[j])) :
				(compare_by_date(arr[j], arr[i]))) {
				std::swap(arr[i], arr[j]);
			}
		}
	}
}

void DataStruct::getByIndex(int index) {
	std::cout << arr[index].getName() << " " << arr[index].getSurename() <<
		" " << arr[index].getSign() << " ";

	int data = arr[index].getBirthday(0); //day
	if (data / 10 == 0)
		std::cout << "0" << data << ".";
	else
		std::cout << data << ".";

	data = arr[index].getBirthday(1); //month
	if (data / 10 == 0)
		std::cout << "0" << data << ".";
	else
		std::cout << data << ".";
	std::cout << arr[index].getBirthday(2); //year
	std::cout << std::endl;

}

void DataStruct::getBySurename(std::string input) {
	bool flag = false;
	for (int i = 0; i < size; i++) {
		if (arr[i].getSurename() == input) {
			this->getByIndex(i);
			flag = true;
		}
	}
	if (flag == false)
		std::cout << "There is no such surename as " << input << std::endl;
}

void DataStruct::save(std::string path) {
	std::ofstream f(path);
	f << size << std::endl;
	for (int i = 0; i < size; i++) {
		f << arr[i].getName() << "\n" << arr[i].getSurename() <<
			"\n" << arr[i].getSign() << "\n";
		for (int j = 0; j < 3; j++)
			f << arr[i].getBirthday(j) << " ";
		f << "\n";
	}
	f.close();
}

void DataStruct::extract(std::string path) {
	std::ifstream f(path);
	if (!f.is_open())
		return;
	delete[] arr;
	f >> size;
	arr = new Sign[size];

	std::string n, s, sign;
	int birth[3] = { 0 };
	for (int i = 0; i < size; i++) {
		f >> n >> s >> sign;
		for (int j = 0; j < 3; j++)
			f >> birth[j];
		arr[i].setNameArg(n);
		arr[i].setSurnameArg(s);
		arr[i].setSignArg(sign);
		arr[i].setBirthArg(birth);
	}
	f.close();
}

bool compare_by_date(Sign s1, Sign s2) {
	if (s1.getBirthday(2) < s2.getBirthday(2)) //year
		return less_;
	else if (s1.getBirthday(2) > s2.getBirthday(2))
		return great_;
	else if (s1.getBirthday(1) < s2.getBirthday(1)) //month
		return less_;
	else if (s1.getBirthday(1) > s2.getBirthday(1))
		return great_;
	else if (s1.getBirthday(0) < s2.getBirthday(0)) //day
		return less_;
	else return great_;
}
