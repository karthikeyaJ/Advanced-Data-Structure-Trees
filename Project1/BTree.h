#pragma once
#include "Interfaces04.h"
#include "BTreeNode.h"
class BTree:public IBTree
{
public:
	BTree() { range = 0; }
	 ~BTree() { }
	void insert(int key, int num_keys);
	void remove(int key, int num_keys);
	int kthMin(int k);
	IBTreeNode * getRoot();
private:
	BTreeNode* node=NULL;// = new BTreeNode();
	int range;
	void insertInNonFull(BTreeNode* node,int key, int num_keys);
	void split(BTreeNode* x, int i);
	int kthMinimum(IBTreeNode* j, int k);
	int numOfKeys(IBTreeNode * node);
	void inorderTraversal(IBTreeNode * curr, std::vector<int>& sorted);
};