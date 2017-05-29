#include "SelectionAlgorithm.h"

class TestBed
{
public:
	TestBed();
	~TestBed();
	void setAlgorithm(int algorithmType, int k);
	void execute();
private:
	SelectionAlgorithm *algorithm;
};

