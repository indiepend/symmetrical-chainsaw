#include "StringToFile.h"

StringToFile::StringToFile() {

}

void StringToFile::ToFile(string filename, int numberOfLines) {
	buffer(numberOfLines);
	loadFile(filename);
}

void StringToFile::ToFile(string filename, string * FileString, int numberOfLines) {
	table = FileString;
	loadFile(filename);
	buffer(numberOfLines);
}

void StringToFile::setString(string * FileString) {
	table = FileString;
}

////////////////////////////////////////////////////
void StringToFile::loadFile(string file) {

	plik.open(file, ios::out);
	if (plik.good() == false) {
		cout << "Leeeeeeeeeeeeeroy";
		//exit(0);
	}
}
////////////////////////////////////////////////////
void StringToFile::buffer(int numberOfLines) {
	plik.seekp(0, ios_base::end);
	for (int i=1; i < numberOfLines; i++) {
		plik << table[i] << endl;
	}
	plik << table[numberOfLines];
	plik.close();
}