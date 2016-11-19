#include "SeqStack.h"
#include <iostream>
using namespace std;
template <class T>
class BinTreeNode
{public:
	T data;
	BinTreeNode<T> *leftChild;
	BinTreeNode<T> *rightChild;

	BinTreeNode() :leftChild(NULL), rightChild(NULL) {}
	BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL)
		:leftChild(l), rightChild(r) {
		data = x;
	}


};
template <class T>
class BinTree
{
public:

	BinTree() :root(NULL) {}
	void CreateBinTree();//�ݹ齨��������
	void PreOrder();//ǰ�����
	void PreOrder_non_recursion();
	void InOrder_non_recursion();
		
   void countLeaf(); 
   void countnumber0f1(); 
   void countnumberoffull(); 
   void countnumber();
private:
	BinTreeNode<T> *root;
	void CreateBinTree(BinTreeNode<T> *& subTree);//�ݹ齨��������
	void PreOrder(BinTreeNode<T> *subTree);//ǰ�����
										   //void InOrder(BinTreeNode<T> *subTree,);//�������
										   //void PostOrder(BinTreeNode<T> *subTree);//�������
										   
	void countLeaf(BinTreeNode<T> * subTree,int &count); //count��ʾҶ�ӽڵ���� 
	
	void countnumber0f1(BinTreeNode<T> * subTree,int &count);//�����Ϊ1�Ľڵ���� 
	
	void countnumberoffull(BinTreeNode<T> * subTree,int &count); //�����������Ϊ2�Ľڵ���� ��count��ʾ�ڵ��� 
			
    int  countnumber(BinTreeNode<T> * subTree);	//ͳ�ƽڵ����					   

	


};


