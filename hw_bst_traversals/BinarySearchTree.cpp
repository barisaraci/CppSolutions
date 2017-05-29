#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {

}

BinarySearchTree::~BinarySearchTree() {
	deleteNodes(root);
}

void BinarySearchTree::printPreorder() {
	cout << "preorder: ";
	if (root != NULL) {
		cout << root->element << " ";
		traversePreorder(root->left);
		traversePreorder(root->right);
	}
	cout << endl;
}

void BinarySearchTree::traversePreorder(BinaryTreeNode * n) {
	if (n != NULL) {
		cout << n->element << " ";
		traversePreorder(n->left);
		traversePreorder(n->right);
	}
}

void BinarySearchTree::printInorder() {
	cout << "inorder: ";
	if (root != NULL) {
		traverseInorder(root->left);
		cout << root->element << " ";
		traverseInorder(root->right);
	}
	cout << endl;
}

void BinarySearchTree::traverseInorder(BinaryTreeNode * n) {
	if (n != NULL) {
		traverseInorder(n->left);
		cout << n->element << " ";
		traverseInorder(n->right);
	}
}

void BinarySearchTree::printPostOrder() {
	cout << "postorder: ";
	if (root != NULL) {
		traversePostorder(root->left);
		traversePostorder(root->right);
		cout << root->element << " ";
	}
	cout << endl;
}

void BinarySearchTree::traversePostorder(BinaryTreeNode * n) {
	if (n != NULL) {
		traversePostorder(n->left);
		traversePostorder(n->right);
		cout << n->element << " ";
	}
}

void BinarySearchTree::insert(int x) {
	if (root == NULL) {
		root = new BinaryTreeNode(x);
	} else {
		if (x > root->element) {
			if (root->right != NULL) {
				insert(x, root->right);
			} else {
				root->right = new BinaryTreeNode(x);
			}
		} else {
			if (root->left != NULL) {
				insert(x, root->left);
			}
			else {
				root->left = new BinaryTreeNode(x);
			}
		}
	}
}

void BinarySearchTree::insert(int x, BinaryTreeNode * & n) {
	if (n == NULL) {
		n = new BinaryTreeNode(x);
	} else if (x < n->element) {
		insert(x, n->left);
	} else if (n->element < x) {
		insert(x, n->right);
	}
}

void BinarySearchTree::deleteNodes(BinaryTreeNode * & n) {
	if (n != NULL) {
		deleteNodes(n->left);
		deleteNodes(n->right);
		delete n;
	}
}