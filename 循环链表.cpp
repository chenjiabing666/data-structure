#include "iostream"
using namespace std;
class Link
{
public:
   int element;
   Link *next;
   Link(int node,Link *rnext)
   {
       element=node;
       next=rnext;
   }
   Link(Link* rnext){next=rnext;}
};

class LLink
{
   private:
    Link *head;
    //Link *tail;
    Link *curr;
   public:
    LLink()
    {
        head=new Link(NULL);
        head->next=head;//循环
        curr=head;//指向当前位置,用与标记尾节点的位置
    }

   /* void append()
    {
         Link *curr=head;
        for(int i=0;i<4;i++)
        {
             int node;
        cout<<"请输入节点的数据：";cin>>node;
        Link *p=new Link(node,NULL);

             p->next=head;//此处必须先将插入节点与头结点相连形成循环
             curr->next=p;//将新节点与前面的节点相连
             curr=curr->next;
        }

      }*/

      void append(int node)
      {
          Link *p=new Link(node,NULL);
          p->next=head;
          curr->next=p;
          curr=curr->next;

      }

      void display()
{
    Link *htemp=head->next;
     while(htemp!=head)//一旦到了尾节点，尾节点的地址域指向的是head
     {
         cout<<htemp->element<<endl;
         htemp=htemp->next;
     }
     //cout<<htemp->next->element<<endl;//此处可证明时循环链表
}


     void insert_element(int node)
     {
         Link *p=new Link(node,NULL);
         Link *htemp=head->next;
         int n;
         cout<<"请输入想要插入位置的数据:";cin>>n;
         while(htemp!=head)
         {
              if(htemp->element==n)
              {
                  p->next=htemp->next;
                  htemp->next=p;
              }
              htemp=htemp->next;
        }

     }

     //原理就是用两个指针标记位置，一个指向删除节点的前面一个，一个指向删除节点用来参与循环搜索
      void delete_element()
    {

        Link *htemp=head->next;//这个是不不变的，便于判断循环条件
        Link *item=head;//指向删除节点的前面一个节点
        int node;
        cout<<"请输入想要删除的节点数据";cin>>node;
        while(htemp!=head)
        {

            if(htemp->element==node)
            {

                //item->next=item->next->next;
                item->next=htemp->next;
                delete htemp;//删除当前的节点
            }
            htemp=htemp->next;//同时后移用来保持前后位置不变
            item=item->next;

        }

    }

//头插法逆置
    void reverse_element()
    {
        Link *p=head->next;
        head->next=head;//此处时将头结点循环，相当于初始化,但是此时的尾节点还是指向头结点的
        while(p!=head)//用来判断循环，这是单循环链表的重点
        {
            Link *pnext=p->next;
            p->next=head->next;
            head->next=p;
            p=pnext;


        }

    }

    void destroy()
    {

    }

};






int main()
{
    LLink app;
    for(int i=0;i<3;i++)
    {
        int node;
        cout<<"请输入节点的数据：";cin>>node;
        app.append(node);
    }
    app.display();

    /*int node;
    cout<<"请输入插入节点的数据：";cin>>node;
    app.insert_element(node);*/
    //app.delete_element();
    app.reverse_element();
    app.display();

return 0;
}
