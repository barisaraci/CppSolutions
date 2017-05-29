#include "AlgorithmSortK.h"
#include <iostream>

using namespace std;

AlgorithmSortK::AlgorithmSortK(int k) : SelectionAlgorithm(k) {
	this->k = k;
}


AlgorithmSortK::~AlgorithmSortK() {
	delete kNums;
	pNums = 0;
}

void AlgorithmSortK::setNumbers() {
	cin >> n;

	pNums = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> pNums[i];
	}
}

int AlgorithmSortK::select() {
	kNums = new int[k];

	for (int i = 0; i < k; i++) {
		kNums[i] = pNums[i];
	}

	sortFirstKNumbers();

	for (int i = k; i < n; i++) {
		if (pNums[i] > kNums[k - 1]) {
			for (int j = 0; j < k; j++) {
				if (pNums[i] > kNums[j]) {
					for (int x = k - 1; x >= j; x--) {
						if (x != k - 1) 
							kNums[x + 1] = kNums[x];
					}
					kNums[j] = pNums[i];
					break;
				}
			}
		}
	}

	return kNums[k - 1];
}

void AlgorithmSortK::sortFirstKNumbers() {
	for (int i = 1; i < k; i++) {
		int temp = kNums[i];
		for (int j = i - 1; j >= 0; j--) {
			if (temp < kNums[j])
				break;

			kNums[j + 1] = kNums[j];
			kNums[j] = temp;
		}
	}
}
