#include "Stack.h"

Stack::Stack() {
	head = new StackItem("-1");
}

Stack::~Stack() {

}

bool Stack::isEmpty() const {
	return head->next == NULL;
}

void Stack::push(const StackItem & x) {
	StackItem *item;
	item = new StackItem(x);
	item->next = head;
	head = item;
}

StackItem & Stack::top() {
	if (!isEmpty())
		return *head;
}

void Stack::pop() {
	if (!isEmpty()) {
		StackItem *tempItem = head;
		head = head->next;
		delete tempItem;
	}
}