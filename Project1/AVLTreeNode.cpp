#include "Interfaces04.h"
#include "AVLTreeNode.h"


void AVLTreeNode::setLeft(IAVLTreeNode * left)
{
	left_ = left;

}

void AVLTreeNode::setRight(IAVLTreeNode * right)
{
	right_ = right;
}

void AVLTreeNode::setKey(int key)
{
	this->key_ = key;

}

IAVLTreeNode *AVLTreeNode::getLeft()
{
	return left_;
}

//int AVLTreeNode::getHeight()
//{
//	return height;
//}

//void AVLTreeNode::updateHeight(IAVLTreeNode * root)
//{
//	root->height = max(root->getLeft()-> //, root->getRight()->getHeight()) + 1);
//	
//}

IAVLTreeNode *AVLTreeNode::getRight()
{
	return right_;

}

int AVLTreeNode::getKey()
{
	return this->key_;
}