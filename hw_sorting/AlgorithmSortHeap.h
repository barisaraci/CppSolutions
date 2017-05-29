#include "SelectionAlgorithm.h"

class AlgorithmSortHeap : public SelectionAlgorithm
{
public:
	AlgorithmSortHeap(int k);
	~AlgorithmSortHeap();
	void setNumbers();
	int select();
};

