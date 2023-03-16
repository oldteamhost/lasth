#pragma once
#include <iostream>
class output
{
public:
	void initFolders();
	void initFoldersAdvanced(std::string name);
	bool writeMode(const char* mode, const char* path);
	bool writeStringTxt(const char* path, const char* str, long responceCode);

};

