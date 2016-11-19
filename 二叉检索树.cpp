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
    //���������Ҳ�Ǳ���ģ���Ϊ�ܹ���ӳ���ڵ�ı仯���
      void BSTinsert(Node *&subTree,int &value)//value��ʾҪ�����ֵ���ж�������ڽڵ����ݾ����������ң����С�ڽڵ����ݾ����������ң��ݹ�ֱ���ҵ����ʵ�λ��
    {
        if(subTree==NULL)//��������ĸ��ڵ�Ϊ�գ����ǻ�û�����ɶ��������ͽ�����ڵ��ɸ������ڵ�
            subTree=new Node(value,NULL,NULL);
            else
            {
                if(subTree->element==value)//�������ظ������ݣ������������ݴ���ֻ���˳������ܲ���
                    return;
                else if(subTree->element>value)
                    BSTinsert(subTree->leftchild,value);
                else
                  BSTinsert(subTree->rightchild,value);
            }
    }
    //����һ�������ò���ķ�ʽ
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
    void preorder(Node *root)//�������
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
        cout<<"������key:";
        cin>>key;
        int data=Search(root,key);
        if(data==NULL)
        cout<<"���ݲ�����"<<endl;
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
