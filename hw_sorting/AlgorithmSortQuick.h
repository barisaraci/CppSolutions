#include "SelectionAlgorithm.h"

class AlgorithmSortQuick : public SelectionAlgorithm
{
public:
	AlgorithmSortQuick(int k);
	~AlgorithmSortQuick();
	void setNumbers();
	int select();
private:
	int quickSelect(int numbers[], int first, int last, int k);
	int partition(int numbers[], int leftIndex, int rightIndex);
	void insertionSort(int numbers[]);
};

