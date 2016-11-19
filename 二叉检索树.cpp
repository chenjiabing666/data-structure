#include "iostream"
using namespace std;

class Node
{
   public:
   Node *leftchild;
   Node *rightchild;
   int element;
   Node(int data,Node *l,Node *r)
   {
        element=data;
        leftchild=l;
        rightchild=r;
   }

};

class BST
{
private:
    Node *root;
    //这里的引用也是必须的，因为能够反映根节点的变化情况
      void BSTinsert(Node *&subTree,int &value)//value表示要插入的值，判断如果大于节点数据就在右子树找，如果小于节点数据就在左子树找，递归直至找到合适的位置
    {
        if(subTree==NULL)//如果给出的根节点为空，就是还没有生成二叉树，就将这个节点变成跟机根节点
            subTree=new Node(value,NULL,NULL);
            else
            {
                if(subTree->element==value)//不能有重复的数据，如果插入的数据存在只能退出，不能插入
                    return;
                else if(subTree->element>value)
                    BSTinsert(subTree->leftchild,value);
                else
                  BSTinsert(subTree->rightchild,value);
            }
    }
    //创建一棵树采用插入的方式
    void create(Node *&root)
    {
        int value[100];
        for(int i=0;i<4;i++)
        {
            cout<<"input value:";
            cin>>value[i];
            BSTinsert(root,value[i]);
        }

    }
    void preorder(Node *root)//先序遍历
    {
        if(root==NULL)
            return ;
        cout<<root->element<<"  ";
        preorder(root->leftchild);
        preorder(root->rightchild);

    }
     int Search(Node *subTree,int key)
     {
          if(subTree==NULL)//tree is empty
            return NULL;
          else
          {
              if(key>subTree->element)
                return Search(subTree->rightchild,key);
              else if(key<subTree->element)
                return Search(subTree->leftchild,key);
              else
                return subTree->element;
          }
     }


public:
    BST()
    {
        root=NULL;
    }

    void BSTinsert()
    {
        int value;
        cout<<"input value:";
        cin>>value;
         BSTinsert(root,value);
    }

    void create()
    {
         create(root);
    }

    void preorder()
    {
        preorder(root);
    }

    void Search()
    {
        int key;
        cout<<"请输入key:";
        cin>>key;
        int data=Search(root,key);
        if(data==NULL)
        cout<<"数据不存在"<<endl;
        else
            cout<<"data:"<<data<<endl;

    }


};
int main()
{
    BST app;
    app.create();
    app.preorder();
   // app.BSTinsert();
    //app.preorder();
    app.Search();




return 0;
}
