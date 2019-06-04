#include "FileToString.h"

void FileToString::loadUp(std::string filename) {
	buffer(&loadFile(filename));
}

std::string* FileToString::getString() {
	return storage.data();
}

int FileToString::getNumber() {
	return storage.size()-1;
}

std::vector<std::string>* FileToString::getVector()
{
	return &storage;
}

std::fstream FileToString::loadFile(std::string filename) {
	std::fstream file;
	file.open(filename, std::ios::in);
	if (file.good() == false) {
		std::cout << "File " << filename <<  " is corrupted" << std::endl;
	}
	return file;
}

void FileToString::buffer(std::fstream * file) {
	storage.clear();
	storage.push_back(std::string());
	std::string tekst;
	(*file).seekg(0);
	while (getline((*file), tekst)) {
		storage.push_back(tekst);
	}
	(*file).close();
}