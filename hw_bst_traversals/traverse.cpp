#include <iostream>
#include "BinarySearchTree.h"
#include "BinaryTreeNode.h"

using namespace std;

int main() {
	
	cout << "Enter a set of numbers (-1 to stop): \n";
	int number;
	BinarySearchTree *tree = new BinarySearchTree();

	while (true) {
		cin >> number;
		if (number == -1) 
			break;
		else {
			tree->insert(number);
		}
	}

	tree->printPreorder();
	tree->printInorder();
	tree->printPostOrder();

	return 0;
}