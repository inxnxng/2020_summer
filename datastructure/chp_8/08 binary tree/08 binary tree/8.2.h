#pragma once
#include"8.1.h"

template <typename T>
class BinaryTree {
	BinaryNode* root;
public:
	BinaryTree() :root(NULL) {}
	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	void inorder() {}

};