#pragma once
#include "Interfaces04.h"
#include "vector.h"


class BTreeNode :public IBTreeNode
{
public:
	BTreeNode() {
		key_size = 0; child_size = 0;
	}
	~BTreeNode() {}
	int getKey(int index);
	void setKey(int index, int key);
	int getKeySize();
	void setKeySize(int size);
	int getChildSize();
	void setChildSize(int size);
	IBTreeNode * getChild(int index);
	void setChild(int index, IBTreeNode * child);
	bool isLeaf();

private:
	vector<int> keys;
	int key_size;
	int child_size;
	vector<BTreeNode*> child;


};