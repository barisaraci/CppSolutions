#include "StackItem.h"

class Stack {
public:
	Stack();
	~Stack();
	bool isEmpty() const;
	void pop();
	void push(const StackItem & x);
	StackItem & top();
private:
	StackItem *head;
};