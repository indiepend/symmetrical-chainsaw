#include "stdafx.h"
#pragma once

using namespace std;

class FileToString
{
	string * table = NULL;
	int lines;

	void buffer(fstream * file);
	fstream loadFile(string filename);
public:
	FileToString();
	void loadUp(string filename);
	string * getString();
	int getNumber();
	//~FileToString();
};

