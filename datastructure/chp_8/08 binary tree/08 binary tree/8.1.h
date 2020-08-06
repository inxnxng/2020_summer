#pragma once
#include<iostream>

template <typename T>
class BinaryNode {
protected:
	T data;
	BinaryNode* left;
	BinaryNode* right;
public:
	BinaryNode(T val = 0; BinaryNode* l = NULL; BinaryNode* r = NULL)
		:data(val), left(l), right(r) {}
	void setData(T val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }
	T getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
	bool isLeaf() { return left == NULL & right == NULL; }
};