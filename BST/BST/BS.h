#include "Node.h"
class BST
{
private:
	Node *root;
	void insert(Node *&subTree,int value);
	void creat(Node *&root);//��һ�ִ�������
	void preorder(Node *root);
	void inorder(Node *root);
	 int count(Node *root);
	 void search(Node *root, int key);
	 void creat2(Node *&root, int value);//�ڶ��ִ����ķ���
	 //friend BST copy(BST c);
	 //void getvalue(Node *root,int value[100]);
	 friend void equal(BST c1, BST c2);
	 void deletemin(Node *&root);
public:
	BST();
	void insert();
	void creat();
	void preorder();
	void count();
	void search();
	void creat2();
	void deletemin();


};