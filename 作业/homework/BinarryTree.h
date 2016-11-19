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
	void CreateBinTree();//递归建立二叉树
	void PreOrder();//前序遍历
	void PreOrder_non_recursion();
	void InOrder_non_recursion();
		
   void countLeaf(); 
   void countnumber0f1(); 
   void countnumberoffull(); 
   void countnumber();
private:
	BinTreeNode<T> *root;
	void CreateBinTree(BinTreeNode<T> *& subTree);//递归建立二叉树
	void PreOrder(BinTreeNode<T> *subTree);//前序遍历
										   //void InOrder(BinTreeNode<T> *subTree,);//中序遍历
										   //void PostOrder(BinTreeNode<T> *subTree);//后序遍历
										   
	void countLeaf(BinTreeNode<T> * subTree,int &count); //count表示叶子节点个数 
	
	void countnumber0f1(BinTreeNode<T> * subTree,int &count);//求度数为1的节点个数 
	
	void countnumberoffull(BinTreeNode<T> * subTree,int &count); //求二叉树度数为2的节点个数 ，count表示节点数 
			
    int  countnumber(BinTreeNode<T> * subTree);	//统计节点个数					   

	


};


