#include "stdafx.h"
#pragma once

using namespace std;

class StringToFile
{
	string * table = NULL;
	int lines;
	fstream plik;

	void buffer(int numberOfLines);
	void loadFile(string filename);
public:
	StringToFile();
	void ToFile(string filename, int numberOfLines);
	void ToFile(string filename, string * FileString, int numberOfLines);
	void setString(string * FileString);
};

