#include "iostream"
using namespace std;
class Link
{
public:
    Link(Link *rnext){next=rnext;}
    Link(int node,Link *rnext){element=node,next=rnext;}
    Link *next;
    int element;
};

class LLink
{
public:
     LLink(int node)
 {
     head=tail=new Link(NULL);

 }

 void append(int node)
 {
   Link *htemp=new Link(node,NULL);
   tail->next=htemp;
   tail=tail->next;
 }

 void display()
 {
     Link *p=head->next;
     while(p)
     {
         cout<<p->element<<"  ";
         p=p->next;
     }
     cout<<endl;
 }

 void insert(int node)
 {
     int n;
     cout<<"����������Ҫ�����λ�õ����ݣ�";cin>>n;
     Link *htemp=new Link(node,NULL);
     Link *p=head;
     cout<<tail->element<<endl;
     while(p)
     {
         //cout<<"jfkdjf"<<endl;
        if(p->element==n)
        {
            htemp->next=p->next;
            p->next=htemp;

        }

           p=p->next;

     }
 }

private:
    Link *head;
    Link *tail;
};
int main()
{
    LLink stu(9);
    for(int i=0;i<4;i++)
    {
        cout<<"������ڵ����ݣ�";
        int node;
        cin>>node;
       stu.append(node);
    }
    stu.display();
    stu.insert(99);
    stu.display();
return 0;
}
