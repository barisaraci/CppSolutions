#include "SelectionAlgorithm.h"

class AlgorithmSortAll : public SelectionAlgorithm
{
public:
	AlgorithmSortAll(int k);
	~AlgorithmSortAll();
	void setNumbers();
	int select();
};

