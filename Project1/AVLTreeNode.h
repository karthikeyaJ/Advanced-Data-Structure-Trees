#pragma once
#include "Interfaces04.h"

class AVLTreeNode:public IAVLTreeNode
{
public:
	AVLTreeNode() { left_ = NULL, right_ = NULL; key_ = 0;  }
	~AVLTreeNode() { }
	void setLeft(IAVLTreeNode * left);
	void setRight(IAVLTreeNode * right);
	void setKey(int key);
	IAVLTreeNode *getLeft();
	IAVLTreeNode *getRight();
	//int getHeight();

	int getKey();
private:
	IAVLTreeNode *left_;
	IAVLTreeNode *right_;
	int key_;
	//int height;
	//int add(int key);
	//void updateHeight(IAVLTreeNode* root);
};