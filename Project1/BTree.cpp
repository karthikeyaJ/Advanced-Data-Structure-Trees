#include "BTree.h"
#include "Interfaces04.h"
#include "BTreeNode.h"
#include <iostream>

void BTree::insert(int key, int num_keys)
{

	if (node == NULL)
	{
		node = new BTreeNode();
		range = num_keys;

		node->setKey(0, key);
		node->setKeySize(1);

	}
	else
	{
		/*for (int i = 0; i < node->getChildSize(); i++)
		{
			std::cout << "\nchild:" << i;
			for (int j = 0; j < node->getChild(i)->getKeySize(); j++)
			{
				std::cout << "key:" << node->getChild(i)->getKey(j) << ",";
			}
		}*/

		if (node->getKeySize() == num_keys)
		{
			BTreeNode *parent = new BTreeNode();
			parent->setChild(0, node);
			parent->setChildSize(parent->getChildSize() + 1);



			split(parent, 0);
			//int i = 0;

			//if (parent->getKey(i) < key)
			//	i++;

			BTreeNode* temp = new BTreeNode();
			temp = (BTreeNode*)parent->getChild(1);            //C[i]->insertNonFull(k);

			insertInNonFull(parent, key, num_keys);
			// Change root
			node = parent;

			/*for (int p = 0; p < node->getKeySize(); p++)
				std::cout << node->getKey(p), std::cout << "";
				std::cout << std::endl;

				for (int p = 0; p < node->getChild(0)->getKeySize(); p++)
				std::cout << node->getChild(0)->getKey(p), std::cout << "";
				std::cout << std::endl;


				for (int p = 0; p < node->getChild(1)->getKeySize(); p++)
				std::cout << node->getChild(1)->getKey(p), std::cout << "";
				std::cout << std::endl;*/

		}

		else
		{
			insertInNonFull(node, key, num_keys);
		}

	}

}
void BTree::insertInNonFull(BTreeNode* node, int key, int num_keys)
{
	int i = node->getKeySize();

	if (node->isLeaf())
	{
		while (i >= 1 && (key < node->getKey(i - 1)))
		{
			i = i - 1;
			node->setKey(i + 1, node->getKey(i));
		}
		node->setKey(i, key);
		node->setKeySize(node->getKeySize() + 1);
	}
	else
	{

		while (i >= 1 && key<node->getKey(i - 1))
		{
			i = i - 1;
		}

		//i = i + 1;
		if (node->getChild(i)->getKeySize() == num_keys)
		{

			split(node, i);
			if (key > node->getKey(i))
				i = i + 1;
		}


		insertInNonFull((BTreeNode*)node->getChild(i), key, num_keys);

	}
}



void BTree::split(BTreeNode* x, int i)
{
	BTreeNode *y = (BTreeNode*)x->getChild(i);
	BTreeNode *z = new BTreeNode();
	int t = (1 + range) / 2;
	int n = t - 1;

	for (int j = 0; j < t - 1; j++)
	{
		z->setKey(j, y->getKey(j + t));
		//y->setKey(j + t, NULL);
		z->setKeySize(z->getKeySize() + 1);
	}

	if (y->isLeaf() == false)
	{
		y->setChildSize(y->getChildSize() - 3);

		for (int j = 0; j < t; j++)
		{
			z->setChild(j, y->getChild(j + t));
			z->setChildSize(z->getChildSize() + 1);
		}
	}

	y->setKeySize(y->getKeySize() - n);

	for (int j = x->getKeySize(); j >= i + 1; j--)
	{
		x->setChild(j + 1, x->getChild(j));
	}

	x->setChild(i + 1, z);

	for (int j = x->getKeySize() - 1; j >= i; j--)
		x->setKey(j + 1, x->getKey(j));


	x->setKey(i, y->getKey(t - 1));
	x->setKeySize(x->getKeySize() + 1);
	y->setKeySize(y->getKeySize() - 1);
	x->setChildSize(x->getChildSize() + 1);
}

void BTree::remove(int key, int num_keys)
{
	IBTreeNode* roots = getRoot();


	/*for (int i = 0; i < roots->getChildSize(); i++)
	{
	std::cout << "\nchild:" << i;
	for (int j = 0; j < roots->getChild(i)->getKeySize(); j++)
	{
	std::cout << "key:" << roots->getChild(i)->getKey(j) << ",";
	}
	}*/
	std::vector<int> cvector;


	inorderTraversal(node, cvector);


	for (int j = 0; j < cvector.size(); j++)
	{
		if (cvector[j] == key)
		{

			cvector.erase(cvector.begin() + j);
			break;
		}
	}

	node = NULL;
	//roots = NULL;
	//	if (cvector.size() == 0)
	//	roots->setKeySize(0);
	//roots->setKey(0,NULL);
	for (int i = 0; i < cvector.size(); i++)
		insert(cvector[i], num_keys);

}

void BTree::inorderTraversal(IBTreeNode * curr, std::vector<int>& sorted)
{

	//std::cout << curr->getKeySize() << std::endl;
	if (curr->getChildSize() == 0)
	{
		for (int i = 0; i < curr->getKeySize(); i++)
		{
			sorted.push_back(curr->getKey(i));
		}
	}
	else
	{
		for (int i = 0; i < curr->getChildSize(); i++)
		{

			inorderTraversal(curr->getChild(i), sorted);

			sorted.push_back(curr->getKey(i));
		}

	}


	/*for (int i = 0; i < sorted.size(); i++)
		std::cout << curr->getKey(i) << std::endl;*/




	//inorderTraversal(curr->getLeft(), sorted);
	//sorted.push_back(curr->getKey());
	//inorderTraversal(curr->getRight(), sorted);
}

int BTree::kthMin(int k)
{

	IBTreeNode* root = getRoot();
	IBTreeNode *curr = root;

	if (root->getChildSize() != 0)
	{
		int value = kthMinimum(curr, k);
		return value;
	}
	else
	{
		int i = 0;
		while (i < root->getKeySize())
		{
			if (i == k)
			{
				return root->getKey(i);
			}
			else
			{
				i++;
			}
		}


	}

}

int BTree::kthMinimum(IBTreeNode* curr, int k)
{
	for (int i = 0; i < curr->getChildSize(); i++)
	{
		std::cout << "\nchild:" << i;
		for (int j = 0; j < curr->getChild(i)->getKeySize(); j++)
		{
			std::cout << "key:" << curr->getChild(i)->getKey(j) << ",";
		}
	}

	if (curr->getChildSize() != 0)
	{

		for (int i = 0; i < node->getChildSize(); i = i + 2)
		{

			int count_left = numOfKeys(curr->getChild(i));
			int count_right = numOfKeys(curr->getChild(i + 1));
			int count = count_left + count_right + 1;

			if (k>count)
			{
				int result = kthMinimum(curr->getChild(i + 2), k - count - 1);
				return result;
			}

			if (k == count)
			{
				return curr->getKey(i + 1);
			}

			if (k < count_left)
			{
				int result = kthMinimum(curr->getChild(i), k);
				return result;
			}
			if (k>count_left)
			{
				int result = kthMinimum(curr->getChild(i + 1), k - count_left - 1);
				return result;
			}
			if (k == count_left)
			{
				return curr->getKey(i);
			}
		}
	}
	else
	{
		int i = 0;
		while (i < curr->getKeySize())
		{
			if (i == k)
			{
				return curr->getKey(i);
			}
			else
			{
				i++;
			}
		}
	}
}

int BTree::numOfKeys(IBTreeNode * node)
{
	if (node->getChildSize() == 0)
		return node->getKeySize();

	for (int i = 0; i < node->getChildSize(); i = i + 2)
	{
		return(1 + numOfKeys(node->getChild(i)) + numOfKeys(node->getChild(i + 1)));
	}
}




IBTreeNode *BTree::getRoot()
{
	return node;
}

