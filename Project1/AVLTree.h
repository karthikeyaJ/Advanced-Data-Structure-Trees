#pragma once
#include "Interfaces04.h"
#include "AVLTreeNode.h"


class AVLTree:public IAVLTree
{
public:
	AVLTree();
	~AVLTree();
	void insert(int key);
	void remove(int key);
	int kthMin(int k);
	IAVLTreeNode * getRoot();
private:
	IAVLTreeNode* root=NULL;
	IAVLTreeNode* add(IAVLTreeNode * root,int key);
	IAVLTreeNode* rightRotation(IAVLTreeNode * Q);
	IAVLTreeNode* leftRotation(IAVLTreeNode * P);
	//void updateHeight();
	int calcHeight(IAVLTreeNode * curr);
      int balance(IAVLTreeNode* root);
	  IAVLTreeNode* deleted(IAVLTreeNode* dup_root, int key);
	  IAVLTreeNode* doubleLeftRotation(IAVLTreeNode* k3);
	  IAVLTreeNode* doubleRightRotation(IAVLTreeNode* k1);
	  IAVLTreeNode* findMaximum(IAVLTreeNode* dup_root);
	  int numOfNodes(IAVLTreeNode * node);
	  int kthMinimum(IAVLTreeNode *root, int k);
};
