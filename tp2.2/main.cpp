#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "datastruct.h"
#include "sign.h"
#include "filestr.h"

using namespace std;

void set_sign(DataStruct&);

void menu_output(short); //отрисовка меню
void set_color(WORD color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
enum colors_ {
	RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
	WHITE = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN |
	FOREGROUND_RED
};
int main() {
	DataStruct data;
	const string stack_pth = "data.txt";
	menu_output(1);
	char key_tmp; //временный символ
	char key; //опция
	short func = 1; //запуск функции
	bool ENTER_;
	bool exit = false;
	while (!exit) {
		ENTER_ = false;
		key_tmp = _getch();
		key_tmp == 224 ? key = _getch() : key = key_tmp;
		//управление меню
		switch (key) {
		case 80: //вниз
			func++;
			if (func > 9)
				func = 1;
			break;
		case 72: //вверх
			func--;
			if (func < 1)
				func = 9;
			break;
		case 13: //enter
			ENTER_ = true;
			break;
		}
		//switch var
		int del_id;
		string surname;
		int sort;
		FileStr t2;
		string task2_pth;

		if (ENTER_) {
			switch (func) {
			case 1: //добавить sign
				set_sign(data);
				break;
			case 2: //удалить несколько последних
				cout << "Enter the number to delete\n";
				cin >> del_id;
				data = data - del_id;
				break;
			case 3: //удалить по индексу
				cout << "Enter the index\n";
				cin >> del_id;
				data -= del_id;
				break;
			case 4: //сохранить в файл
				data.save(stack_pth);
				break;
			case 5: //вывести из файла
				data.extract(stack_pth);
				break;
			case 6: //сортировка по дню рождения
				cout << "Sort by birth 1 - less, 2 - great\n";
				cin >> sort;
				(sort == 1) ? data.birthdaySort(less_) : data.birthdaySort(great_);

				break;
			case 7: //сортировка по surname
				cout << "Enter the surname\n";
				cin >> surname;
				data.getBySurename(surname);
				system("pause");
				break;
			case 8: //task 2
				system("cls");
				cout << "Enter the path to file\n";
				cin >> task2_pth;
				t2.read(task2_pth);
				t2.proc();
				system("pause");
				break;
			case 9:
				exit = true;
				break;
			}
		}
		menu_output(func);
		cout << data;
	}
	return 0;
}

void menu_output(short menu) {
	set_color(WHITE);
	system("cls");
	cout << endl << "====================================\n\n";
	if (menu == 1)
		set_color(RED);
	else set_color(WHITE);
	cout << "Add a sign to data\n";
	if (menu == 2)
		set_color(RED);
	else set_color(WHITE);
	cout << "Delete the last few sign from stack\n";
	if (menu == 3)
		set_color(RED);
	else set_color(WHITE);
	cout << "Delete by index\n";
	if (menu == 4)
		set_color(RED);
	else set_color(WHITE);
	cout << "Save data to file\n";
	if (menu == 5)
		set_color(RED);
	else set_color(WHITE);
	cout << "Extract data from file\n";
	if (menu == 6)
		set_color(RED);
	else set_color(WHITE);
	cout << "Sort stack by birth\n";
	if (menu == 7)
		set_color(RED);
	else set_color(WHITE);
	cout << "Sort stack by surname\n";
	if (menu == 8)
		set_color(RED);
	else set_color(WHITE);
	cout << "Task 2(file and string stream)\n";
	if (menu == 9)
		set_color(RED);
	else set_color(WHITE);
	cout << "Exit\n" << endl;
	set_color(WHITE);
}


void set_sign(DataStruct& st) {
	string n, s, sign;
	int birth[3] = { 0 };

	cout << "Eneter name: "; cin >> n;
	cout << "Enter surname: "; cin >> s;
	cout << "Enter a sign: "; cin >> sign;
	cout << "Ener the birth (DDMMYYYY): ";
	for (int i = 0; i < 3; i++)
		cin >> birth[i];
	Sign tmp(n, s, sign, birth);
	st = st + tmp;
}