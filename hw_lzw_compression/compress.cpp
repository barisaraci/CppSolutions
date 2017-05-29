#include <iostream>
#include <fstream>
#include <string>
#include "LinearProbing.h"

using namespace std;

int main(int argc, char* argv[])
{
	string ITEM_NOT_FOUND = "-1";
	HashTable<string> Dictionary(ITEM_NOT_FOUND);

	string text, word, compressed;
	int letter;

	ifstream readFile(argv[1]);

	if (readFile.is_open()) {
		getline(readFile, text);
		readFile.close();
	} else cout << "Unable to open file";

	for (int i = 0; i < 256; i++) {
		Dictionary.insert(std::string(1, ('0' + i)));
	}
	
	int i = 0, j = 1;
	while (i < text.size()) {
		if (i + 1 >= text.size()) {
			compressed += std::to_string(Dictionary.findPos(text.substr(i, 1))) + " ";
			break;
		}

		word = text.substr(i, j);

		if (Dictionary.find(word) == "-1") {
			Dictionary.insert(word);
			compressed += std::to_string(letter) + " ";
			i += word.size() - 1;
			j = 1;
		} else {
			letter = Dictionary.findPos(word);
			j++;
			if (i + word.size() >= text.size()) { compressed += std::to_string(letter) + " "; break; }
		}
	}

	ofstream writeFile(argv[2]);
	if (writeFile.is_open()) {
		writeFile << compressed;
		writeFile.close();
	} else cout << "Unable to write file";

	return 0;
}
