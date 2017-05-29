#include "AlgorithmSortHeap.h"
#include "BinaryHeap.h"
#include <iostream>

using namespace std;

AlgorithmSortHeap::AlgorithmSortHeap(int k) : SelectionAlgorithm(k) {
	this->k = k;
}


AlgorithmSortHeap::~AlgorithmSortHeap() {
	delete[] pNums;
	pNums = 0;
}

void AlgorithmSortHeap::setNumbers() {
	cin >> n;

	pNums = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> pNums[i];
	}
}

int AlgorithmSortHeap::select() {
	BinaryHeap heap(k);

	for (int i = 0; i < k; i++) {
		heap.insert(pNums[i]);
	}

	for (int i = k; i < n; i++) {
		if (pNums[i] >= heap.getMin()) {
			heap.deleteMin();
			heap.insert(pNums[i]);
		}
	}

	return heap.getMin();
}