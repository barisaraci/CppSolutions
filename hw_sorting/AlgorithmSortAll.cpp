#include "AlgorithmSortAll.h"
#include <iostream>

using namespace std;

AlgorithmSortAll::AlgorithmSortAll(int k) : SelectionAlgorithm(k) {
	this->k = k;
}


AlgorithmSortAll::~AlgorithmSortAll() {
	delete[] pNums;
	pNums = 0;
}

void AlgorithmSortAll::setNumbers() {
	cin >> n;

	pNums = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> pNums[i];
	}
}

int AlgorithmSortAll::select() {
	for (int i = 1; i < n; i++) {
		int temp = pNums[i];
		for (int j = i - 1; j >= 0; j--) {
			if (temp < pNums[j])
				break;

			pNums[j + 1] = pNums[j];
			pNums[j] = temp;
		}
	}

	return pNums[k - 1];
}
