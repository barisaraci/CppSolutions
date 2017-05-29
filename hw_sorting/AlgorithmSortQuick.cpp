#include "AlgorithmSortQuick.h"
#include <iostream>

using namespace std;

AlgorithmSortQuick::AlgorithmSortQuick(int k) : SelectionAlgorithm(k) {
	this->k = k;
}


AlgorithmSortQuick::~AlgorithmSortQuick() {
	delete[] pNums;
	pNums = 0;
}

void AlgorithmSortQuick::setNumbers() {
	cin >> n;

	pNums = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> pNums[i];
	}
}

int AlgorithmSortQuick::select() {
	if (n <= 10) {
		insertionSort(pNums);
		return pNums[k - 1];
	} else {
		return quickSelect(pNums, 0, n - 1, k);
	}
}

int AlgorithmSortQuick::quickSelect(int numbers[], int first, int last, int k) {
	if (first == last) return numbers[first];
	int part = partition(numbers, first, last);
	int length = part - first + 1;
	if (length == k) {
		return numbers[part];
	} else if (k < length) {
		return quickSelect(numbers, first, part - 1, k);
	} else {
		return quickSelect(numbers, part + 1, last, k - length);
	}
}

int AlgorithmSortQuick::partition(int numbers[], int left, int right) {
	int pivot = numbers[right];

	while (left < right) {
		while (numbers[left] < pivot)
			left++;
		while (numbers[right] > pivot)
			right--;
		if (numbers[left] == numbers[right]) {
			left++;
		} else if (left < right) {
			int temp = numbers[left];
			numbers[left] = numbers[right];
			numbers[right] = temp;
		}
	}

	return right;
}

void AlgorithmSortQuick::insertionSort(int numbers[]) {
	int j;
	for (int p = 1; p < n; p++) {
		int temp = numbers[p];
		for (j = p; j > 0 && temp < numbers[j - 1]; j--) {
			numbers[j] = numbers[j - 1];
		}
		numbers[j] = temp;
	}
}
