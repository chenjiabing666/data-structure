#include "iostream"
using namespace std;
class BST;
class Node
{
private:
	Node *left;
	Node *right;
	int data;
public:
	friend BST;
	Node(int data, Node *l, Node *r);
	Node(Node *l, Node *r);


};

class BST
{
private:
	Node *root;
	void creat(Node *&root, int value);
	void display(Node *root);
	void insert(Node *root, int value);

public:
	void creat();
	void display();
	void insert();
	
};

Node::Node(int data, Node *l, Node *r)
{
	this->data = data;
	left = l;
	right = r;
}
Node::Node(Node *l, Node *r)
{
	left = l;
	right = r;
}
void BST::creat(Node *&root, int value)
{
	if (root == NULL)
		root = new Node(value, NULL, NULL);
	else
	{
		if (root->data > value)
			creat(root->left, value);
		else
			creat(root->right, value);

	}
}


void BST::display(Node *root)//œ»–Ú ‰≥ˆ
{
	if (root == NULL)
		return;
	else
	{
		cout << root->data << endl;
		display(root->left);
		display(root->right);
	}
   
}

void BST::creat()
{
	int value[100];
	for (int i = 0; i < 3; i++)
	{
		cout << "input value:";
		cin >> value[i];
		creat(root, value[i]);
	}
}

void BST::display()
{
	display(root);
}

int main()
{
	BST app;
	app.creat();
	app.display();
	return 0;
}