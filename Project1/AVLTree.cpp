#include "Interfaces04.h"
#include "AVLTree.h"
//#include "AVLTreeNode.h"
#include <iostream>     // std::cout

AVLTree::AVLTree() { }
AVLTree ::~AVLTree() { }
void AVLTree::insert(int key)
{
	IAVLTreeNode* t = new AVLTreeNode();
	t->setKey(key);
	t->setLeft(NULL);
	t->setRight(NULL);
	if (root == NULL)
		root = t;

	else
	{
		root=add(root, key);
	}
}

int AVLTree::balance(IAVLTreeNode* root)
{
	int left_height = calcHeight(root->getLeft());
	int right_height = calcHeight(root->getRight());
	int diff = left_height - right_height;
	return diff;
}


IAVLTreeNode* AVLTree::add(IAVLTreeNode * dup_root, int key)
{
					IAVLTreeNode* curr = dup_root;

					if (curr == NULL)
					{

						curr = new AVLTreeNode();
						curr->setKey(key);
						curr->setLeft(NULL);
						curr->setRight(NULL);
						return curr;
					}

					if (key < dup_root->getKey())
					{
						dup_root->setLeft(add(curr->getLeft(), key));

						IAVLTreeNode* new_root = new AVLTreeNode();
						IAVLTreeNode* parent, *temp;
						new_root = dup_root;


						int left_height = calcHeight(dup_root->getLeft());
						int right_height = calcHeight(dup_root->getRight());
						int diff = left_height - right_height;
						if (diff == -1 || diff==0 || diff==1)
							return dup_root;
						parent = new_root;
						temp = parent;
						while (diff == 2)
						{
							temp = parent;
							parent = new_root;
							new_root = new_root->getLeft();
							diff = balance(new_root);
												if (diff == 1)
												{
													if (dup_root == parent)
													{
														if (root == parent)
														{
															parent = rightRotation(parent);
															root = parent;

														}
														else
															parent = rightRotation(parent);
														return parent;

													}
													else
													{
														parent = rightRotation(parent);
														temp->setLeft(parent);
													}


												}

												else if (diff == -1)
												{
													new_root = leftRotation(new_root);
													parent->setLeft(new_root);
													parent = rightRotation(parent);
													return parent;


												}

						}
					}

					if (key>dup_root->getKey())
					{
						dup_root->setRight(add(curr->getRight(), key));

						/////////////
						IAVLTreeNode* new_root = new AVLTreeNode();
						IAVLTreeNode* parent, *temp;
						new_root = dup_root;


						int left_height = calcHeight(dup_root->getLeft());
						int right_height = calcHeight(dup_root->getRight());
						int diff = left_height - right_height;
						if (diff == -1 || diff==0 || diff==1)
							return dup_root;
						parent = new_root;
						temp = parent;
						while (diff == -2)
						{
							temp = parent;
							parent = new_root;


							new_root = new_root->getRight();
							diff = balance(new_root);

							if (diff == -1)
							{
								//root = leftRotation(parent);

								if (dup_root == parent)
								{
									if (root == parent)
									{
										parent = leftRotation(parent);
										root = parent;

									}
									else
									parent = leftRotation(parent);
									return parent;

								}
								else
								{
									parent = leftRotation(parent);
									temp->setRight(parent);
								}


							}

							else if (diff == 1)
							{
								new_root = rightRotation(new_root);
								parent->setRight(new_root);
								parent = leftRotation(parent);
								return parent;


							}

						}
						////////////



					}
					return dup_root;
}

int AVLTree::calcHeight(IAVLTreeNode * curr)
{
	if (curr == NULL)
	{
		return 0;
	}

	int left_height = calcHeight(curr->getLeft());
	int right_height = calcHeight(curr->getRight());

	if (left_height > right_height)
	{
		return left_height + 1;
	}

	else {
		return right_height + 1;
	}
}

IAVLTreeNode* AVLTree::rightRotation(IAVLTreeNode * Q)
{
	IAVLTreeNode *p = Q->getLeft();
	Q->setLeft(p->getRight());
	p->setRight(Q);

	return p;

}
IAVLTreeNode* AVLTree::leftRotation(IAVLTreeNode * p)
{
	IAVLTreeNode *Q = p->getRight();
	p->setRight(Q->getLeft());
	Q->setLeft(p);

	return Q;

}

void AVLTree::remove(int key)
{

	root=deleted(root, key);

}

//IAVLTreeNode* AVLTree::doubleLeftRotation(IAVLTreeNode* k3){
//	k3->setLeft(rightRotation(k3->getLeft()));
//	return leftRotation(k3);
//}
//IAVLTreeNode* AVLTree::doubleRightRotation(IAVLTreeNode* k1){
//	k1->setRight(leftRotation(k1->getRight()));
//	return rightRotation(k1);
//}
//
//IAVLTreeNode* AVLTree::findMaximum(IAVLTreeNode* dup_root)
//{
//	if (dup_root == NULL)
//		return dup_root;
//	while (dup_root->getRight() != NULL)
//		dup_root = dup_root->getRight();
//	return dup_root;
//}

//IAVLTreeNode* AVLTree::deleted(IAVLTreeNode* dup_root, int key)
//{
//
//		if (key == NULL) 
//		{
//			return NULL;
//		}
//
//		if ( key< dup_root->getKey())
//		{
//			dup_root->setLeft(deleted(dup_root->getLeft(),key));
//			
//			int l = dup_root->getLeft() != NULL ? calcHeight(dup_root->getLeft()) : 0;
//			if ((dup_root->getRight() != NULL) && (calcHeight(dup_root->getRight()) - l >= 2))
//			{
//				int right_height = dup_root->getRight()->getRight() != NULL ? calcHeight(dup_root->getRight()->getRight()) : 0;
//				int left_height = dup_root->getRight()->getLeft() != NULL ? calcHeight(dup_root->getRight()->getLeft()) : 0;
//
//				if (right_height >= left_height)
//					dup_root = leftRotation(dup_root);
//				else
//					dup_root = doubleRightRotation(dup_root);
//			}
//		}
//		else if (key> dup_root->getKey())
//		{
//			dup_root->setRight(deleted(dup_root->getRight(), key));
//
//			int r = dup_root->getRight() != NULL ? calcHeight(dup_root->getRight()) : 0;
//
//			if ((dup_root->getLeft() != NULL) && (calcHeight(dup_root->getLeft()) - r >= 2))
//			{
//				int left_height = dup_root->getLeft()->getLeft() != NULL ? calcHeight(dup_root->getLeft()->getLeft()) : 0;
//				int right_height = dup_root->getLeft()->getRight() != NULL ? calcHeight(dup_root->getLeft()->getRight()) : 0;
//
//				if (left_height >= right_height)
//					dup_root = rightRotation(dup_root);
//				else
//					dup_root = doubleLeftRotation(dup_root);
//			}
//		}
//		
//		else if (dup_root->getLeft() != NULL)
//		{
//			dup_root->setKey((findMaximum(dup_root->getLeft())->getKey()));
//
//			deleted(dup_root->getLeft(),dup_root->getKey());
//
//			if ((dup_root->getRight() != NULL) && (calcHeight(dup_root->getRight()) - calcHeight(dup_root->getLeft())>= 2))
//			{
//				int rightHeight =dup_root->getRight()->getRight()!= NULL ? calcHeight(dup_root->getRight()->getRight()): 0;
//				int leftHeight = dup_root->getRight()->getLeft() != NULL ?calcHeight(dup_root->getRight()->getLeft()): 0;
//
//				if (rightHeight >= leftHeight)
//					dup_root = leftRotation(dup_root);
//				else
//					dup_root = doubleRightRotation(dup_root);
//			}
//		}
//
//		else
//			dup_root = (dup_root->getLeft() != NULL) ? dup_root->getLeft():dup_root->getRight();
//
//		if (dup_root != NULL)
//		{
//			int leftHeight =dup_root->getLeft()!= NULL ? calcHeight(dup_root->getLeft()) : 0;
//			int rightHeight = dup_root->getRight() != NULL ? calcHeight(dup_root->getRight()) : 0;
//		}
//		return dup_root;
//	} 
//
//
//

int AVLTree::numOfNodes(IAVLTreeNode * node)
{
	if (node == NULL)
		return 0;
	else
		return(1+numOfNodes(node->getLeft())+numOfNodes(node->getRight()));
}


int AVLTree::kthMin(int k)
{
	IAVLTreeNode *root = getRoot();
	IAVLTreeNode *curr = root;
	
	int value = kthMinimum(curr, k);
	return value;
	
}


int AVLTree::kthMinimum(IAVLTreeNode *curr, int k)
{
	int count_left = numOfNodes(curr->getLeft());
	int count_right = numOfNodes(curr->getRight());

	if (k < count_left)
	{
		int result = kthMinimum(curr->getLeft(),k);
		return result;
	}
	if (k>count_left)
	{
		int result = kthMinimum(curr->getRight(),k-count_left-1);
		return result;
	}
	if (k == count_left)
	{
		return curr->getKey();
	}
	
}

IAVLTreeNode *AVLTree::getRoot()
{
	return root;

}














IAVLTreeNode* AVLTree::deleted(IAVLTreeNode* dup_root, int key)
{
		
	if (key == dup_root->getKey())
	{
		int left_height = calcHeight(dup_root->getLeft());
		int right_height = calcHeight(dup_root->getRight());

		if (left_height == 0 && right_height == 0)
		{
			return NULL;
		}

		else if ((left_height == 0 && right_height != 0) )
		{
			return dup_root->getRight();

		
		}
		
		else if ((left_height != 0 && right_height == 0))
		{
			return dup_root->getLeft();

		}
		else if (left_height != 0 && right_height != 0)
		{
			/*IAVLTreeNode *parent = dup_root;
			while (dup_root->getRight() != NULL)
			{
				dup_root = dup_root->getRight();
			}
			parent->setKey(dup_root->getLeft()->getKey());
			dup_root->setLeft(NULL);
			return parent;*/
//----------------------------------------------
			/*IAVLTreeNode *parent = dup_root;
			dup_root = dup_root->getRight();
			if (dup_root->getLeft() != NULL){
				parent->setKey(dup_root->getLeft()->getKey());
				dup_root->setLeft(NULL);
				return parent;
			}
			else if (dup_root->getLeft() == NULL)
			{
				parent->setKey(dup_root->getKey());
				parent->setRight(NULL);
				return parent;
			
			}*/

			//-----------------------------------------------
			

			IAVLTreeNode *tmp = dup_root->getLeft();
			IAVLTreeNode *previous = dup_root;
			while (tmp->getRight() != 0)
			{
				previous = tmp;
				tmp = tmp->getRight();
			}
			dup_root->setKey(tmp->getKey());
			if (previous == dup_root)
				previous->setLeft(tmp->getLeft());
			else
				previous->setRight(tmp->getLeft());
			return dup_root;

			//else {
			//	tmp = node−>left; // ha s b o th c h i l d r e n
			//	previous = node; // 1 .
			//	while (tmp−>right != 0) { // 2 .
			//		previous = tmp;
			//		tmp = tmp−>right;
			//	}
			//	node−>key = tmp−>key; // 3 .
			//	if (previous == node)
			//		previous−>left = tmp−>left;
			//	else previous−>right = tmp−>left; // 4 .
			//}
			//delete tmp




		}



	}

	if (key<dup_root->getKey())
	{
		
		dup_root->setLeft(deleted(dup_root->getLeft(), key));

		////////////////////////////////////////////////////////
		IAVLTreeNode* new_root = new AVLTreeNode();
		IAVLTreeNode* parent, *temp;
		new_root = dup_root;


		int left_height = calcHeight(dup_root->getLeft());
		int right_height = calcHeight(dup_root->getRight());
		int diff = left_height - right_height;
		if (diff == -1 || diff == 0 || diff == 1)
			return dup_root;
		parent = new_root;
		temp = parent;
		while (diff == 2)
		{
			temp = parent;
			parent = new_root;
			new_root = new_root->getLeft();
			diff = balance(new_root);
			if (diff == 1)
			{
				if (dup_root == parent)
				{
					if (root == parent)
					{
						parent = rightRotation(parent);
						root = parent;

					}
					else
						parent = rightRotation(parent);
					return parent;

				}
				else
				{
					parent = rightRotation(parent);
					temp->setLeft(parent);
				}


			}

			else if (diff == -1)
			{
				new_root = leftRotation(new_root);
				parent->setLeft(new_root);
				parent = rightRotation(parent);
				return parent;


			}

		}
		///////////////////////////////////////////////////////




	}
	if (key > dup_root->getKey())
	{
		
		dup_root->setRight(deleted(dup_root->getRight(), key));


		///////////////////////////////////////////////////////////////////////

		/////////////
		IAVLTreeNode* new_root = new AVLTreeNode();
		IAVLTreeNode* parent, *temp;
		new_root = dup_root;


		int left_height = calcHeight(dup_root->getLeft());
		int right_height = calcHeight(dup_root->getRight());
		int diff = left_height - right_height;
		if (diff == -1 || diff == 0 || diff == 1)
			return dup_root;
		parent = new_root;
		temp = parent;
		while (diff == -2)
		{
			temp = parent;
			parent = new_root;


			new_root = new_root->getRight();
			diff = balance(new_root);

			if (diff == -1)
			{
				//root = leftRotation(parent);

				if (dup_root == parent)
				{
					if (root == parent)
					{
						parent = leftRotation(parent);
						root = parent;

					}
					else
						parent = leftRotation(parent);
					return parent;

				}
				else
				{
					parent = leftRotation(parent);
					temp->setRight(parent);
				}


			}

			else if (diff == 1)
			{
				new_root = rightRotation(new_root);
				parent->setRight(new_root);
				parent = leftRotation(parent);
				return parent;


			}

		}
		////////////



	}
	return dup_root;
		//////////////////////////////////////////////////////////////////////
	
}
