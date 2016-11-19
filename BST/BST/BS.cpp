#include "stdafx.h"
#include "iostream"
#include "BS.h"
using namespace std;
BST::BST()
{
	root = NULL;
}

void BST::insert(Node *&subTree,int value)
{
	if (subTree == NULL)
		subTree = new Node(value, NULL, NULL);
	else
	{
		if (subTree->element > value)
			insert(subTree->leftchild, value);
		else if (subTree->element < value)
			insert(subTree->rightchild, value);
		else
			return;
	  
	}
	}

void BST::creat(Node *&root)
{
	int value[100];
	for (int i = 0; i < 4; i++)
	{
		cout << "input value:";
		cin >> value[i];
		insert(root, value[i]);
	}
	
}

void BST::insert()
{
	int value;
	cout << "input value:";
	cin >> value;
	insert(root, value);
}

void BST::creat()
{
	creat(root);
}

void BST::preorder(Node *root)
{
	if (root == NULL)
		return;
	else
	{
		cout << root->element << " ";
		preorder(root->leftchild);
		preorder(root->rightchild);
	
	}
}

void BST::preorder()
{
	preorder(root);
}

int BST::count(Node *root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + count(root->leftchild)
		+ count(root->rightchild);
}

void BST::count()
{
	
	cout << "节点个数：" << count(root) << endl;
}

void BST::search(Node *root, int key)
{
	if (root == NULL)
		cout << "tree is empty" << endl;
	else
	{
		if (root->element > key)
			search(root->leftchild, key);
		else if (root->element < key)
			search(root->rightchild, key);
		else
			cout << "this number exist" << endl;
	
	}
}

void BST::search()
{
	int value;
	cout << "input value,which you searched:" << endl;
	cin >> value;
	search(root, value);
	search(root, value);
}


void BST::creat2(Node *&root, int value)
{
	if (root == NULL)
		root = new Node(value, NULL, NULL);
	else
	{
		if (value > root->element)
			creat2(root->rightchild, value);
		else if (value < root->element)
			creat2(root->leftchild, value);
		else
		{
			cout << "this number alreday exist" << endl;
			return;
		}
	}
	
}

void BST::creat2()
{
	int value[10];
	for (int i = 0; i < 4; i++)
	{
		cout << "input value:";
		cin >> value[i];
		creat2(root, value[i]);
	}
}

void BST::deletemin(Node *&root)
{
	if (root->leftchild == NULL)
	{

		delete root;
		return;
	}
	deletemin(root->leftchild);
}

void BST::deletemin()
{
	deletemin(root);
}


