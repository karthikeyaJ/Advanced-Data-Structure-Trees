#include "Interfaces04.h"
#include "BTreeNode.h"
	
int  BTreeNode::getKey(int index)
{
	return keys.get(index);
}

void BTreeNode::setKey(int index, int key)
{
	this->keys.set(index, key);
	
}

int BTreeNode::getKeySize()
{
	return key_size;         //key_size;

}

void BTreeNode::setKeySize(int size)
{
	this->key_size = size;

}

int BTreeNode::getChildSize()
{
	return child_size;
}

void BTreeNode::setChildSize(int size)
{
	this->child_size = size;
}

IBTreeNode * BTreeNode::getChild(int index)
{
	return child.get(index);       //cvector.get(index);
}

void BTreeNode::setChild(int index, IBTreeNode * child)
{
	this->child.set(index,(BTreeNode*)child);                    //[index] = (BTreeNode*)child;
}

bool BTreeNode::isLeaf()
{
	if (this->child_size == 0)
		return true;
	else
		return false;
}

