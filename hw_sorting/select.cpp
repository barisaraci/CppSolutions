#include <iostream>
#include "TestBed.h"

using namespace std;

int main() {
	int algorithmType = 0, k = 0;

	TestBed *testBed = new TestBed();

	while (!(algorithmType == 1 || algorithmType == 2 || algorithmType == 3 || algorithmType == 4)) {
		cin >> algorithmType;
	}

	cin >> k;

	testBed->setAlgorithm(algorithmType, k);
	testBed->execute();

	delete testBed;

	return 0;
}