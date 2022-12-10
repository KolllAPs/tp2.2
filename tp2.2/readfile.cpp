#include <iostream>
#include "filestr.h"

using namespace std;

FileStr::FileStr() : data(""), pth("") {}
FileStr::FileStr(string pth_) : data(""), pth(pth_) {}
FileStr::FileStr(const FileStr& tmp) {
	data = tmp.data;
	pth = tmp.pth;
}

bool FileStr::read(string pth_) {
	file.open(pth_, ios::in);
	if (!file.is_open())
		return false;

	string tmp;
	while (!file.eof()) {
		getline(file, tmp);
		if (tmp[0] != '\0')
			data += tmp, data += '\n';
	}
	cout << data;
	file.close();
	return tmp[0] != '\0' ? true : false;
}

void FileStr::proc() {
	string tmp_word;
	string max_word;
	bool word;
	int count = 0;
	//ищем самое большое слово
	for (int i = 0; i < data.length(); i++) {
		word = true;
		if (data[i] == '.' || data[i] == ',' || data[i] == '!' || data[i] == '?' || data[i] == ' ' || data[i] == '\n') { //разделители
			if (tmp_word.length() > max_word.length())
				max_word = tmp_word, count = 0;
			if (!strcmp(tmp_word.c_str(), max_word.c_str()))
				count++;
			tmp_word.clear();
			word = false;
		}
		if (word) {
			tmp_word += data[i];
		}
	}
	cout << "====================================\nMax len word : " << max_word << " : " << count << "\n";
}