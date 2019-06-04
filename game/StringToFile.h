#include "stdafx.h"
#pragma once

class StringToFile
{
	std::string * table = NULL;
	std::vector <std::string>* storage;

	//////////////////////////////////////////////////
	///\brief
	///writes data to file and closes file
	//////////////////////////////////////////////////
	void buffer(int, std::fstream*);

	//////////////////////////////////////////////////
	///\brief
	///overload for std::vector
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
	///default constructor
	//////////////////////////////////////////////////
	StringToFile();

	//////////////////////////////////////////////////
	///\brief
	///constructor overload
	///opens or creates file and writes data inside
	///file path can be like that
	///"C://doc/mydocument.txt" or
	///"mydocument.txt" if document is inside app folder
	///
	///also you need to specify how many lines you want to write
	///by default it's 1 line
	//////////////////////////////////////////////////
	StringToFile(std::string, std::string*, int = 1);

	//////////////////////////////////////////////////
	///\brief
	///constructor overload
	///std::string pointer has been replaced by std::vector
	///
	///note: you don't have to specify lines number
	//////////////////////////////////////////////////
	StringToFile(std::string, std::vector <std::string>*);

	//////////////////////////////////////////////////
	///\brief
	///opens or creates file and writes data inside
	///file path can be like that
	///"C://doc/mydocument.txt" or
	///"mydocument.txt" if document is inside app folder
	///
	///also you need to specify how many lines you want to write
	///by default it's 1 line
	//////////////////////////////////////////////////
	void ToFile(std::string, std::string*, int = 1);

	//////////////////////////////////////////////////
	///\brief
	///function overload
	///std::string pointer has been replaced by std::vector
	///
	///note: you don't have to specify lines number
	//////////////////////////////////////////////////
	void ToFile(std::string, std::vector <std::string>*);
};

