#include "iostream"
using namespace std;//˫ѭ��������ѭ������Ψһ�Ĳ�ͬ���ǳ�ʼ�����캯��ʱ��ͬ
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
       tail->next=head;//��ͷ�������
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
        cout<<"������ڵ����ݣ�";cin>>node;
        Link *p=new Link(node,NULL,NULL);
        int n;
        Link *htemp=head->next;
        cout<<"��������Ҫ����λ�õ����ݣ�";
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
       cout<<"����������Ҫɾ��λ�ýڵ�����ݣ�";cin>>node;
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
        cout<<"������ڵ����ݣ�";cin>>node;
        app.append(node);
    }
    app.display();
    //app.insert_element();
    app.delete_element();
    app.display();

return 0;
}
