#include "iostream"
using namespace std;//双循环链表与循环链表唯一的不同就是初始化构造函数时不同
class Link
{
   public:
       Link *next;
       Link *prev;
       int element;
       Link(Link *rnext,Link *rprev)
       {
           next=rnext;
           rprev=prev;
       }
        Link(int node,Link *rnext,Link *rprev)
       {
           next=rnext;
           rprev=prev;
           element=node;
       }

};

class DbLink
{
private:
    Link *head;
    Link *tail;
    Link *curr;
public:
    DbLink()
    {
       head=new Link(NULL,NULL);
       tail=new Link(NULL,NULL);
       head->next=tail;
       tail->prev=head;
       tail->next=head;//与头结点相连
       head->prev=tail;
       curr=head;
    }
    void append(int node)
    {
        Link *p=new Link(node,NULL,NULL);
        p->next=tail;
        p->prev=tail->prev;
        tail->prev->next=p;
        tail->prev=p;

    }

    void display()
    {
        Link *htemp=head->next;
        while(htemp!=tail)
        {
               cout<<htemp->element<<" ";
               htemp=htemp->next;
         }


    }

    void  insert_element()
    {
        int node;
        cout<<"请输入节点数据：";cin>>node;
        Link *p=new Link(node,NULL,NULL);
        int n;
        Link *htemp=head->next;
        cout<<"请输入想要插入位置的数据：";
        cin>>n;
        while(htemp!=tail)
        {
            if(htemp->element==n)
            {
                p->next=htemp->next;
                p->prev=htemp;
                htemp->next->prev=p;
                htemp->next=p;
            }
            htemp=htemp->next;
        }

    }

    void delete_element()
    {
       int node;
       cout<<"请输入你想要删除位置节点的数据：";cin>>node;
       Link *htemp=head->next;
       Link *item=head;
       while(htemp!=tail)
       {
          if(htemp->element==node)
          {
              Link *p=item->next;
              item->next->next->prev=item;
              item->next=item->next->next;


          }
          htemp=htemp->next;
          item=item->next;
       }
    }




};
int main()
{
    DbLink app;
    for(int i=0;i<3;i++)
    {
        int node;
        cout<<"请输入节点数据：";cin>>node;
        app.append(node);
    }
    app.display();
    //app.insert_element();
    app.delete_element();
    app.display();

return 0;
}
