#pragma once
class SelectionAlgorithm
{
public:
	SelectionAlgorithm(int k);
	~SelectionAlgorithm();
	virtual int select() = 0;
	virtual void setNumbers() = 0;
protected:
	int n, k;
	int *pNums = 0;
};

