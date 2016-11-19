#include "stdafx.h"
#include "iostream"
#include "Node.h"
using namespace std;
Node::Node(int data, Node *l, Node *r)
{
	element = data;
	leftchild = l;
	rightchild = r;
}



