#include "BinarryTree.h"
template<class T>
void BinTree<T>::CreateBinTree()
{
	CreateBinTree(root);
}
template<class T>
void BinTree<T>::PreOrder()
{
	PreOrder(root);
}

template<class T>
void BinTree<T>::CreateBinTree(BinTreeNode<T>*& subTree)
{
	T item;
	cin >> item;
	if (item != -1)
	{
		subTree = new BinTreeNode<T>(item);		//Create Root
		CreateBinTree(subTree->leftChild);	// Create left child tree
		CreateBinTree(subTree->rightChild);	// Create reght child tree
	}
	else
		subTree = NULL;

}

template<class T>
void BinTree<T>::PreOrder(BinTreeNode<T>* subTree)
{
	if (subTree != NULL) {
		cout << subTree->data;
		PreOrder(subTree->leftChild);
		PreOrder(subTree->rightChild);
	}
}
template<class T>
 void BinTree<T>::PreOrder_non_recursion()
{
	SeqStack<BinTreeNode<T>*> s;
	BinTreeNode<T> *p = root;
	while (p != NULL || !s.IsEmpty())
	{
		if (p)   
		{
			cout << p->data<<endl;
			s.Push(p);
			p = p->leftChild;
			}
		else
		{
			s.Pop(p);
			p=p->rightChild;
		}
	}
}

template<class T>
void BinTree<T>::InOrder_non_recursion()
{
	SeqStack<BinTreeNode<T>*> s;
	BinTreeNode<T> *p = root;
	while (p != NULL || !s.IsEmpty())
	{
		if (p)
		{
			s.Push(p);
			p = p->leftChild;
		}
		else
		{
			s.Pop(p);
			cout << p->data << endl;
			p = p->rightChild;
		}
	}
}


template<class T>
void BinTree<T>::countLeaf(BinTreeNode<T> * subTree,int &count)
{
     if(subTree)
	 {
	     if((!subTree->leftChild)&&(!subTree->rightChild))
		   count++;
		   countLeaf(subTree->leftChild,count); 
		   countLeaf(subTree->rightChild,count); 
	 } 
} 


template<class T>
void BinTree<T>::countLeaf() 
{
      int count=0;
      countLeaf(root,count);
	  cout<<"Ҷ�ӣ�"<<count<<endl; 
} 

template<class T>
	void BinTree<T>::countnumber0f1(BinTreeNode<T> * subTree,int &count) 
	{
		if(subTree)
		{
		    if(((!subTree->leftChild)&&(subTree->rightChild))||(subTree->leftChild)&&(!subTree->rightChild)) 
		    //�ж�ֻҪ��һ���ڵ�ֻ��һ�����ӻ���ֻ��һ���Һ��Ӿ��Ƕ���Ϊһ�Ľڵ� 
		    count++; 
		    countnumber0f1(subTree->leftChild,count);
			countnumber0f1(subTree->rightChild,count); 
		    
		} 
		
	
	} 
	template<class T>
	   void BinTree<T>::countnumber0f1()
	   {
	        int count=0;
	        countnumber0f1(root,count);
			cout<<"�ڵ����Ϊ1�Ľڵ������"<<count<<endl; 
	        
	   } 
	   
	   template<class T>
	   	void BinTree<T>::countnumberoffull(BinTreeNode<T> * subTree,int &count)
	   	{
		     if(subTree)
			 {
			    if((subTree->leftChild!=NULL)&&(subTree->rightChild!=NULL))//�������������������ھ��Ƕ���Ϊ2�Ľڵ� 
				 count++;
				 countnumberoffull(subTree->leftChild,count);
				 countnumberoffull(subTree->rightChild,count); 
				 
				 
			 } 
		   
		} 
   
        template<class T>
        void  BinTree<T>::countnumberoffull()
		{
			int count=0;
			countnumberoffull(root,count);
			cout<<"�ڵ����Ϊ2�Ľڵ����Ϊ��"<<count<<endl; 
		
		} 
		
		 template<class T>
		    int  BinTree<T>::countnumber(BinTreeNode<T> * subTree)
			{
			     if(subTree==NULL)
				 {
				    return 0;
				 } 
			     return 1+countnumber(subTree->leftChild)
                         +countnumber(subTree->rightChild);
				 
				 
			}		
			
				 template<class T>
				void BinTree<T>::countnumber() 
				 {
				    int count=countnumber(root); 
				    cout<<"�ڵ������"<<count<<endl; 
				 }			   





