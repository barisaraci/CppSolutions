#include "SelectionAlgorithm.h"



SelectionAlgorithm::SelectionAlgorithm(int k) {
	this->k = k;
}


SelectionAlgorithm::~SelectionAlgorithm() {
	delete pNums;
}
