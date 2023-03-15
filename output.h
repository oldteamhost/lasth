#pragma once
#include <iostream>
class output
{
public:
	void initFolders();
	void initFoldersAdvanced(std::string name);
	void printOutput(long code,const char* mode, const char* link, bool status);
	void printMain(const char* name);
	void printEnd(int count);
	void printHelpMenu();
	void printHelpMenuRu();
	bool writeMode(const char* mode, const char* path);
	bool writeStringTxt(const char* path, const char* str, long responceCode);

};

