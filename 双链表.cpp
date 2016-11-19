#include "iostream"
using namespace std;
class Link
{
 public:
     Link *next;//指向后面的一个节点
     Link *prev;//前驱指向前面一个节点
     int element;
     Link(Link *rnext,Link *rprev)
     {
         next=rnext;
         rprev=prev;
     }
     Link(int item,Link *rnext,Link *rprev)
     {
         next=rnext;
         rprev=prev;
         element=item;
     }
};


class DbLink//双链表的头结点和尾节点都不储存数据
{
   private:
       Link *head;
       Link *tail;
   public:
    DbLink(int n)
{
    head=new Link(NULL,NULL);
    tail=new Link(NULL,NULL);

    head->next=tail;//前后节点都是不存储数据的，因此在链表生成的时候必须同时生成头尾节点，并且连接起来
    tail->prev=head;
}
void append(int node)//在尾节点后添加节点，在尾节点和前面的节点之间插入新的节点，因为尾节点不储存数据
{
    Link *htemp=new Link(node,NULL,NULL);//创建一个新节点并且将地址赋值为空
    htemp->next=tail;
    htemp->prev=tail->prev;//tail->prev表示前面的节点，此句将新节点与前面的节点连接
    tail->prev->next=htemp;//必须先将htemp与前面的节点连接，否则先和tail连接的话就无法通过tail找到前面的节点
    tail->prev=htemp;
}

void display()
{
    Link *htemp=head->next;

    while(htemp!=tail)
    {
       cout<<htemp->element<<"  ";
       htemp=htemp->next;

           }
}
void insert_element(int node)
{
    Link *htemp=new Link(node,NULL,NULL);
    int finditem;
    Link *p=head->next;
    cout<<"请输入你想要插入位置的数据：";
    cin>>finditem;

    while(p!=tail)
    {
        //  cout<<"陈家爱情"<<endl;
       if(p->element==finditem)
       {
           htemp->next=p->next;
           htemp->prev=p;
           p->next->prev=htemp;//必须先要执行这一步才能执行下一步，否则将无法通过p找到下一个节点
           p->next=htemp;
       }
       p=p->next;
    }

}

//要找到想要删除节点的前一个节点
void delete_element(int node)//node表示要删除的数据
{
    Link *htemp=head;
    while(htemp!=tail)
    {

        if(htemp->next->element==node)//如果等式成立那么htemp就是被删节点的前一个节点
        {
            Link *p=htemp->next;//在删除之前必须要用一个指针保存节点，以便后面执行删除操作

            htemp->next->next->prev=htemp;//将htemp与被删节点的下一个节点相连接
            htemp->next=htemp->next->next;//将被删节点的下一个节点的后继相连接
            delete p;
        }

            htemp=htemp->next;
    }
}


//这是交换节点数据完成逆置
void swap(int &a,int &b)
{
   int t;
   t=a;
   a=b;
   b=t;
}
//
void reverse_element()
{
    Link *begin=head->next;
    Link *end=tail->prev;
    while(begin!=end&&begin->prev!=end)//当链表有偶数个节点时用begin->prev!=end来判断，当链表有奇数个节点时用begin!=end来判断
    {
         swap(begin->element,end->element);//交换前后对应节点的数据，不交换前后节点的指针
         begin=begin->next;//节点后移
         end=end->prev;//节点前移
    }

}


/*void reverse_element()
{
    Link *curr=head;
    Link *p=head;//交换
    head=tail;

    tail=p;
    while(curr)
    {

      Link *htemp=curr->next;
      curr->next=curr->prev;
      curr->prev=htemp;//交换
       curr=curr->prev;
    }
}*/

void display_element()
{
   //cout<<tail->prev->element<<endl;
   //cout<<tail->prev->prev->element<<endl;
   cout<<head->element<<endl;
}


};
int main()
{

    DbLink stu(5);
   // stu.insert_element(67);
   for(int i=0;i<3;i++)
   {
       int node;
      cout<<"请输入添加节点的数据:";cin>>node;
      stu.append(node);

   }

   stu.display();
   //stu.insert_element(99);
   //stu.display();
   cout<<endl;
   //stu.delete_element(44);
   //stu.display_element();
   stu.reverse_element();
   stu.display();

return 0;
}














