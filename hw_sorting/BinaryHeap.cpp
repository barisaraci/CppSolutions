//============================================================================
// Name        : BinaryHeap.cpp
// Author      : Hasan Sozer
// Version     : 1.2
// Copyright   : (c) 2013 Ozyegin University
// Description : Includes the (incomplete) implementation file of the  
//               BinaryHeap class that will be used as part of the program    
//               to be submitted as Homework 4, which is assigned in the   
//				 context of the course CS201, Data Structures and Algorithms.
//               
//				 THE IMPLEMENTATION MUST BE COMPLETED TO MAKE ALL THE TESTS
//				 IN THE MAIN METHOD PASS.
//
//				 After completing the heap implementation, "BinaryHeap.h" and
//				 "BinaryHeap.cpp" files will be used for extending homework 1,
//				 and the extended program will be submitted as Homework 4.
//============================================================================

#include "BinaryHeap.h"

BinaryHeap::BinaryHeap(int capacity) {
	this->capacity = capacity;

	// The element at index 0 is not used!
	// The root element will be placed at index 1
	heap = new int[capacity + 1];
	size = 0;
}

BinaryHeap::~BinaryHeap() {
	delete[] heap;
}

int BinaryHeap::getMin() {
	return size == 0 ? -1 : heap[0];
}

void BinaryHeap::insert(int x) {
	if (size == capacity)
		return;

	heap[size++] = x;
	percolateUp(size - 1);
}

void BinaryHeap::percolateUp(int x) {
	if (x == 0)
		return;

	int parent = (x - 1) / 2;
	if (heap[parent] > heap[x]) {
		swap(parent, x);
		percolateUp(parent);
	}
}

void BinaryHeap::deleteMin() {
	if (size == 0)
		return;

	heap[0] = heap[size - 1];
	size--;
	if (size > 0) {
		percolateDown(0);
	}
}

void BinaryHeap::percolateDown(int x) {
	int left, right, min;
	left = 2 * x + 1;
	right = 2 * x + 2;

	if (left >= size && right >= size) {
		return;
	}
	else if (right >= size && left < size) {
		min = left;
	}
	else if (right < size && heap[left] <= heap[right]) {
		min = left;
	}
	else if (right < size && heap[left] > heap[right]) {
		min = right;
	}

	if (heap[min] < heap[x]) {
		swap(min, x);
		percolateDown(min);
	}
}

void BinaryHeap::swap(int i, int j) {
	int t = heap[i];
	heap[i] = heap[j];
	heap[j] = t;
}
