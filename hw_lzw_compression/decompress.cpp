#include <iostream>
#include <fstream>
#include <string>
#include "LinearProbing.h"

using namespace std;

int main(int argc, char* argv[])
{
	string ITEM_NOT_FOUND = "-1";
	HashTable<string> Dictionary(ITEM_NOT_FOUND);

	for (int i = 0; i < 256; i++) {
		Dictionary.insert(std::string(1, ('0' + i)));
	}

	string dec, code, decompressed;

	ifstream readFile(argv[1]);

	if (readFile.is_open()) {
		getline(readFile, code);
		readFile.close();
	}
	else cout << "Unable to open file";

	int count = 0;

	for (int i = 0; i < code.size(); i++) {
		if (code.substr(i, 1) == " ") {
			count++;
		}
	}

	int count2 = 0;
	int *letters = new int[count];

	for (int i = 0; i < code.size(); i++) {
		if (code.substr(i, 1) == " ") {
			if (!dec.empty()) {
				letters[count2] = std::stoi(dec);
				dec.clear();
				count2++;
			}
		}
		else {
			dec += code.substr(i, 1);
		}
	}

	string pW, cW;

	decompressed += Dictionary.get(letters[0]);

	for (int i = 0; i < count; i++) {
		if (i != count - 1) {
			pW = Dictionary.get(letters[i]);
			cW = Dictionary.get(letters[i + 1]);
			if (Dictionary.find(cW) != "-1") {
				decompressed += cW;
			}
			cW = cW.substr(0, 1);
			if (Dictionary.find(pW + cW) == "-1") {
				Dictionary.insert(pW + cW);
			}
		}
	}

	ofstream writeFile(argv[2]);
	if (writeFile.is_open()) {
		writeFile << decompressed;
		writeFile.close();
	}
	else cout << "Unable to write file";

	return 0;
}