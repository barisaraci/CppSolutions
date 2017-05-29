#include "Calculator.h"

Calculator::Calculator(string s) {
	infixExpression = s;
	string temp;

	stack = new Stack();

	for (int i = 0; i < infixExpression.length(); i++) {
		if (infixExpression[i] != ' ') {
			temp += s[i];
		} else {
			if (isOperator(temp[0])) {
				while (!stack->isEmpty() && stack->top().toString().c_str()[0] != '(' && isHigherPrecedence(stack->top().toString().c_str()[0], temp[0])) {
					StackItem item = stack->top();
					postfixExpression += item.toString() + " ";
					stack->pop();
				}
				StackItem *item = new StackItem(temp);
				stack->push(*item);
			} else if (isOperand(temp[0])) {
				postfixExpression += temp + " ";
			} else if (temp[0] == '(') {
				StackItem *item = new StackItem(temp);
				stack->push(*item);
			} else if (temp[0] == ')') {
				while (!stack->isEmpty() && stack->top().toString().c_str()[0] != '(') {
					StackItem item = stack->top();
					postfixExpression += item.toString() + " ";
					stack->pop();
				}
				stack->pop();
			}
			temp = "";
		}
	}

	while (!stack->isEmpty()) {
		StackItem item = stack->top();
		postfixExpression += item.toString() + " ";
		stack->pop();
	}

	postfixExpression += ";";
}

Calculator::~Calculator() {
	delete stack;
}

string Calculator::getPostfix() {
	return postfixExpression;
}

int Calculator::calculate() {
	int result = 0;
	string temp;
	int n1, n2;

	for (int i = 0; i < postfixExpression.length(); i++) {
		if (postfixExpression[i] != ' ' && postfixExpression[i] != ';') {
			temp += postfixExpression[i];
		} else {
			if (isOperator(temp[0])) {
				n1 = atoi(stack->top().toString().c_str());
				stack->pop();
				n2 = atoi(stack->top().toString().c_str());
				stack->pop();
				StackItem *item = new StackItem(to_string(operate(n1, n2, temp[0])));
				stack->push(*item);
			}
			else if (isOperand(temp[0])) {
				StackItem *item = new StackItem(temp);
				stack->push(*item);
			}
			temp = "";
		}
	}

	result = atoi(stack->top().toString().c_str());

	return result;
}

int Calculator::operate (int n1, int n2, char op) {
	int result;

	switch (op) {
	case '+':
		result = n2 + n1;
		break;
	case '-':
		result = n2 - n1;
		break;
	case '*':
		result = n2 * n1;
		break;
	case '/':
		result = n2 / n1;
		break;
	}

	return result;
}

bool Calculator::isOperand(char c) {
	if (c >= '0' && c <= '9') 
		return true;

	return false;
}

bool Calculator::isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;

	return false;
}

bool Calculator::isHigherPrecedence(char op1, char op2) {
	int op1Weight = getOperatorWeight(op1);
	int op2Weight = getOperatorWeight(op2);

	if (op1Weight == op2Weight)
		return true;

	return op1Weight > op2Weight;
}

int Calculator::getOperatorWeight(char op) {
	int weight = 0;
	if (op == '+' || op == '-') {
		weight = 1;
	} else if (op == '*' || op == '/') {
		weight = 2;
	}
	return weight;
}

