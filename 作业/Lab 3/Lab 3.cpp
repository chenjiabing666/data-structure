#include "iostream"
#include "stdlib.h"
using namespace std;
class Link;
class LLink;

class stock
{
public:
    friend Link;
    friend LLink;
private:
    string symbol;
    int shares;
    double costs;
};

class Link
{
public:
    Link *next;
    stock element;
    Link(string a,int b,double c,Link *rnext)
    {
        element.symbol=a;
        element.shares=b;
        element.costs=c;
        next=rnext;
    }
    Link(Link *rnext)
    {
       next=rnext;
    }

};

class LLink
{
 private:
     Link *head;
     Link *tail;
     int Linksize;//计数
 public:
    LLink()
    {
        head=tail=new Link(NULL);
        Linksize=0;//头结点标号为0


    }

    void append(string a,int b,double c)
    {
        Link *p=new Link(a,b,c,NULL);
        tail->next=p;
        tail=tail->next;
        Linksize++;//计数表示链表元素的个数

    }

    void display()
    {

       Link *htemp=head->next;
        while(htemp)
        {
            cout<<htemp->element.symbol<<" ";
            cout<<htemp->element.shares<<" ";
            cout<<htemp->element.costs<<" ";
            htemp=htemp->next;
        }
        cout<<endl;

    }

    void returnMiddleList()
    {
        int middle = Linksize/2;
        int i=0;
        Link *htemp=head->next;
        while(htemp)
        {
            if(middle==i)
            {
                cout<<"symbol:"<<htemp->element.symbol<<" shares:"<<htemp->element.shares<<" costs:"<<htemp->element.costs<<endl;
                cout<<"位置是："<<middle<<endl;
                return ;
            }
            htemp=htemp->next;
            i++;

        }


    }
};
int main()
{
   string a="a";
   int b=a;
   cout<<b<<endl;


return 0;
}
