#include <iostream>
#include "TestBed.h"
#include "AlgorithmSortQuick.h"
#include "AlgorithmSortAll.h"
#include "AlgorithmSortK.h"
#include "AlgorithmSortHeap.h"
#include <ctime>

using namespace std;

TestBed::TestBed() {
}


TestBed::~TestBed() {
	delete algorithm;
}

void TestBed::setAlgorithm(int algorithmType, int k) {
	if (algorithmType == 1) {
		algorithm = new AlgorithmSortAll(k);
	}
	else if (algorithmType == 2) {
		algorithm = new AlgorithmSortK(k);
	}
	else if (algorithmType == 3) {
		algorithm = new AlgorithmSortHeap(k);
	}
	else if (algorithmType == 4) {
		algorithm = new AlgorithmSortQuick(k);
	}
}

void TestBed::execute() {
	algorithm->setNumbers();

	clock_t start = clock();

	int number = algorithm->select();

	clock_t end = clock();

	double cpu_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	cout << "The number " << number << " is found in " << cpu_time << " seconds.";
}
