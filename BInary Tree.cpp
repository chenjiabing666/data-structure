#include "iostream"
using namespace std;

class Node//节点
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

        //这里的subTree必须要用引用类型，因为要将root的变化记录下来
    void creatTree(Node *&subTree)//使用前序遍历创造二叉树
    {
       int value;
       cout<<"请输入值：";
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

    void preorder(Node *root)//先序遍历:root,left,right
    {
        if(root==NULL)
            return;
            cout<<root->element<<" ";
            preorder(root->left);
            preorder(root->right);

    }

    void inorder(Node *root)//中序遍历，left,root,right
    {
        if(root==NULL)
            return ;
        inorder(root->left);
        cout<<root->element<<"  ";
        inorder(root->right);
    }

    void perorder(Node *root)//后序遍历：left,right,root
    {
         if(root==NULL)
            return;
         perorder(root->left);
         perorder(root->right);
         cout<<root->element<<" ";
    }
     //从根节点开始判断如果左子树和右子树都不存在就是叶子节点
      void countLeaf(Node *root,int &count)
    {
        if(root)//如果不是空树
        {
            if(root->left==NULL&&root->right==NULL)
                count++;
            countLeaf(root->left,count);
            countLeaf(root->right,count);
        }
    }


     //计算节点度数为2的节点个数，从根节点开始，如果左右子树都不为空就是节点度数为2
    void countFull(Node *root,int &count)
    {
        if(root->left!=NULL&&root->right!=NULL)
            count++;
        countFull(root->left,count);
        countFull(root->right,count);
    }



    //计算二叉树的节点个数，左子树的节点加上右子树的节点个数
    int count(Node* subTree)
    {
        if(subTree==NULL)
            return 0;
            return 1+count(subTree->left)
            +count(subTree->right);
    }

    //计算二叉树的高度，先计算左子树的高度和右子树的高度，然后比较，取其中较大的数就是二叉树的高度
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
         cout<<"二叉树的节点数为："<<n<<endl;
     }

     void height()
     {
        int n=height(root);
        cout<<"二叉树的高度为："<<n<<endl;
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
         cout<<"叶子节点个数："<<count<<endl;
     }

     void countFull()
     {
         int count=0;
         countFull(root,count);
         cout<<"节点度数为2 的节点个数："<<count<<endl;
     }

     void count1()
        {
             int count=0;
             count1(root,count);
             cout<<"度数为1的节点个数："<<count<<endl;
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
