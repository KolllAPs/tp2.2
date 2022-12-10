#pragma once
#include <string>
#include <fstream>

class FileStr {
	std::string data;
	std::string pth;
	std::ifstream file;

public:
	FileStr();
	FileStr(std::string);
	FileStr(const FileStr&);

	bool read(std::string);
	void proc();
};
