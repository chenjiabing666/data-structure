#include "iostream"
using namespace std;

class Node//�ڵ�
{
public:

   int element;
   Node *left;
   Node *right;
   Node(int node,Node *a,Node *b)
   {
       element=node;
       left=a;
       right=b;
   }
   Node(Node *a,Node *b)
   {
       left=a;
       right=b;
   }
};

class BinTree
{
private:
    Node *root;

        //�����subTree����Ҫ���������ͣ���ΪҪ��root�ı仯��¼����
    void creatTree(Node *&subTree)//ʹ��ǰ��������������
    {
       int value;
       cout<<"������ֵ��";
       cin>>value;
       if(value==-1)
            subTree=NULL;
       else
       {
            subTree=new Node(value,NULL,NULL);
            creatTree(subTree->left);
            creatTree(subTree->right);
       }
    }

    void preorder(Node *root)//�������:root,left,right
    {
        if(root==NULL)
            return;
            cout<<root->element<<" ";
            preorder(root->left);
            preorder(root->right);

    }

    void inorder(Node *root)//���������left,root,right
    {
        if(root==NULL)
            return ;
        inorder(root->left);
        cout<<root->element<<"  ";
        inorder(root->right);
    }

    void perorder(Node *root)//���������left,right,root
    {
         if(root==NULL)
            return;
         perorder(root->left);
         perorder(root->right);
         cout<<root->element<<" ";
    }
     //�Ӹ��ڵ㿪ʼ�ж�������������������������ھ���Ҷ�ӽڵ�
      void countLeaf(Node *root,int &count)
    {
        if(root)//������ǿ���
        {
            if(root->left==NULL&&root->right==NULL)
                count++;
            countLeaf(root->left,count);
            countLeaf(root->right,count);
        }
    }


     //����ڵ����Ϊ2�Ľڵ�������Ӹ��ڵ㿪ʼ�����������������Ϊ�վ��ǽڵ����Ϊ2
    void countFull(Node *root,int &count)
    {
        if(root->left!=NULL&&root->right!=NULL)
            count++;
        countFull(root->left,count);
        countFull(root->right,count);
    }



    //����������Ľڵ�������������Ľڵ�����������Ľڵ����
    int count(Node* subTree)
    {
        if(subTree==NULL)
            return 0;
            return 1+count(subTree->left)
            +count(subTree->right);
    }

    //����������ĸ߶ȣ��ȼ����������ĸ߶Ⱥ��������ĸ߶ȣ�Ȼ��Ƚϣ�ȡ���нϴ�������Ƕ������ĸ߶�
    int height(Node *subTree)
    {
        if(subTree==NULL)
            return 0;
        int hl=height(subTree->left);
        int hr=height(subTree->right);
        if(hl>hr)
        return ++hl;
        else
            return ++hr;
    }

    void  count1(Node *root,int &count)
    {
        if(root)
        {
            if((root->left!=NULL&&root->right==NULL)||(root->left==NULL&&root->right!=NULL))
                count++;
            count1(root->left);
            count1(root->right);
        }
    }


public:
    void creatTree()
    {
        creatTree(root);
    }
    void preorder()
    {
        preorder(root);
        cout<<endl;
    }

     void count()
     {
         int n=count(root);
         cout<<"�������Ľڵ���Ϊ��"<<n<<endl;
     }

     void height()
     {
        int n=height(root);
        cout<<"�������ĸ߶�Ϊ��"<<n<<endl;
     }

     void inorder()
     {
         inorder(root);
         cout<<endl;
     }

     void perorder()
     {
         perorder(root);
         cout<<endl;
     }

     void countLeaf()
     {
         int count=0;
         countLeaf(root,count);
         cout<<"Ҷ�ӽڵ������"<<count<<endl;
     }

     void countFull()
     {
         int count=0;
         countFull(root,count);
         cout<<"�ڵ����Ϊ2 �Ľڵ������"<<count<<endl;
     }

     void count1()
        {
             int count=0;
             count1(root,count);
             cout<<"����Ϊ1�Ľڵ������"<<count<<endl;
        }



};
int main()
{
    BinTree app;
    app.creatTree();
    app.preorder();
    app.inorder();
    app.count();
    app.height();
    app.countLeaf();

return 0;
}
