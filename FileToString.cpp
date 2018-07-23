#include "FileToString.h"



FileToString::FileToString()
{
}

void FileToString::loadUp(string filename) {
	buffer(&loadFile(filename));
}

string * FileToString::getString() {
	return table;
}

int FileToString::getNumber() {
	return lines-1;
}

//////////////////////////////////////////
fstream FileToString::loadFile(string file) {
	fstream plik;
	plik.open(file, ios::in);
	if (plik.good() == false) {
		cout << "Leeeeeeeeeeeeeroy" << file << endl;
	//	exit(0);
	}
	return plik;
}
////////////////////////////////////////////////////
void FileToString::buffer(fstream * file) {
	int w = 1;
	string tekst;
	lines = (int)count(istreambuf_iterator<char>(*file), istreambuf_iterator<char>(), '\n') + 2;
	table = new string[lines];
	(*file).seekg(0);
	while (getline((*file), tekst)) {
		table[w] = tekst;
		w++;
	}
	(*file).close();
}