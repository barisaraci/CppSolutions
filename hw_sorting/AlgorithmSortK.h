#include "SelectionAlgorithm.h"

class AlgorithmSortK : public SelectionAlgorithm
{
public:
	AlgorithmSortK(int k);
	~AlgorithmSortK();
	void setNumbers();
	int select();
private:
	int *kNums = 0;
	void sortFirstKNumbers();
};

