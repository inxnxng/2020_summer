#pragma once
#include<iostream>
using namespace std;


class BinaryNode {
protected:
	char data;
	BinaryNode* left;
	BinaryNode* right;
public:
	BinaryNode(char val, BinaryNode* l = NULL, BinaryNode* r = NULL)
		:data(val), left(l), right(r) {}
	void setData(char val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }
	char getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
	bool isLeaf() { return (left == NULL) && (right == NULL); }
};