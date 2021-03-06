#include "stdafx.h"
#pragma once

class FileToString
{
	std::vector <std::string> storage;

	//////////////////////////////////////////////////
	///\brief
	///internal function for buffering
	//////////////////////////////////////////////////
	void buffer(std::fstream*);

	//////////////////////////////////////////////////
	///\brief
	///opens file and checks if it's currupted
	//////////////////////////////////////////////////
	std::fstream loadFile(std::string);
public:
	//////////////////////////////////////////////////
	///\brief
	///opens file and converts it to string table
	///file path can be like that
	///"C://doc/mydocument.txt" or
	///"mydocument.txt" if document is inside app folder
	//////////////////////////////////////////////////
	void loadUp(std::string);

	//////////////////////////////////////////////////
	///\brief
	///returns pointer to table with data
	//////////////////////////////////////////////////
	std::string* getString();

	//////////////////////////////////////////////////
	///\brief
	///returns number of lines in file
	//////////////////////////////////////////////////
	int getNumber();

	//////////////////////////////////////////////////
	///\brief
	///returns vector with data
	//////////////////////////////////////////////////
	std::vector <std::string>* getVector();
};

