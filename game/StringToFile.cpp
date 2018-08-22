#include "StringToFile.h"

StringToFile::StringToFile() 
{

}

StringToFile::StringToFile(std::string filename, std::string * data, int linesNum)
{
	table = data;
	buffer(linesNum, &loadFile(filename));
}

StringToFile::StringToFile(std::string filename, std::vector<std::string>* data)
{
	storage = data;
	buffer(&loadFile(filename));
}

void StringToFile::ToFile(std::string filename, std::string * data, int linesNum) {
	table = data;
	buffer(linesNum,&loadFile(filename));
}

void StringToFile::ToFile(std::string filename, std::vector<std::string>* data)
{
	storage = data;
	buffer(&loadFile(filename));
}

std::fstream StringToFile::loadFile(std::string filename) {
	std::fstream file;
	file.open(filename, std::ios::out);
	if (file.good() == false) {
		std::cout << "File " << filename << " is corrupted" << std::endl;
	}
	return file;
}

void StringToFile::buffer(int linesNum,std::fstream* file) {
	(*file).seekp(0, std::ios_base::end);
	for (int i=1; i <= linesNum; i++) {
		(*file) << table[i] << std::endl;
	}
	(*file).close();
}

void StringToFile::buffer(std::fstream * file)
{
	(*file).seekp(0, std::ios_base::end);
	for (int i = 1; i <= (*storage).size(); i++) {
		(*file) << (*storage)[i-1] << std::endl;
	}
	(*file).close();
}
