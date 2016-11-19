#include "iostream"
using namespace std;
class Link
{
 public:
     int element;
     Link* next;
};

class LList
{
  public:
      LList(int size=0)
      {
          curr=tail=head=new Link();
      }


      void append(int node)//在链表后面添加节点,也可以用来输入链表的数据
      {
          Link* p=new Link();
          p->element=node;
          tail->next=p;//将新建的节点与尾节点连接
          tail=tail->next;//将尾节点向后移动
      }

      void display()
      {
         Link* p=head->next;
         while(p!=NULL)
         {
     //        cout<<"ccc"<<endl;
             cout<<p->element<<"  ";//头结点不存储数据，所以将指针指向后面的数据;
             p=p->next;//将指针后移


         }
      }

       void insert(int node)
      {
          Link *p=head;
          Link* item=new Link();
          if(p==NULL)
            cout<<"陈加兵"<<endl;
          cout<<"请输入想要插入节点的数据：";cin>>item->element;
          item->next=NULL;
          while(p)
          {

              //cout<<"fvjld"<<endl;
             if(p->element==node)//查找关键节点
             {
                 item->next=p->next;
                 p->next=item;

              }
              else{
             p=p->next;//将节点向后移动
          }
          }

      }


      //头插法的原理就是先插入的在最后，后插入的在前面，就是在head与第一个节点之间插入节点，如果是空表相当于在链表头添加节点
      void reverse_element()
      {
          if(head==NULL)
             return ;
                Link *p=head->next;//将指针指向第一个节点，保存第一个节点的地址
                Link *pnext=NULL;
                head->next=NULL;//将链表的头结点与后面的节点断开，形成单一的头结点
                while(p!=NULL)
                {
                    pnext=p->next;//将指针指向待插入的节点的后面一个节点
                    p->next=head->next ;//将节点插入到头结点后面，如果是第一个节点相当于head->next=NULL
                    head->next=p;
                    p=pnext;//指针p指向后面的一个节点反复操作
                }
                return ;

      }


      void Merger(LList &a,LList &b)

      {
          LList c(3);//新创建的一个链表
          Link *a_htemp=a.head->next;
          Link *b_htemp=b.head->next;
          while(b_htemp!=NULL&&a_htemp!=NULL)
          {
              if(a_htemp->element<=b_htemp->element)
              {
                  c.tail->next=a_htemp;
                  c.tail=c.tail->next;


              }
          }


      }

    Link* head;
    Link* curr;
    Link* tail;
};

//合并两个链表
 LList Merger(LList &a,LList &b)

      {
          LList c(3);//新创建的一个链表
          Link *a_htemp=a.head->next;
          Link *b_htemp=b.head->next;
          while(b_htemp!=NULL&&a_htemp!=NULL)
          {
              if(a_htemp->element<=b_htemp->element)
              {
                  c.tail->next=a_htemp;
                  c.tail=c.tail->next;
                  a_htemp=a_htemp->next;

              }
              else
              {
                 c.tail->next=b_htemp;
                  c.tail=c.tail->next;
                      b_htemp=b_htemp->next;
              }



          }
          if(a_htemp!=NULL)
            c.tail->next=a_htemp;
          else
            c.tail->next=b_htemp;
          return c;


      }
void display_item(LList &a)
{
    Link *htemp=a.head->next;
    while(htemp)
    {
        cout<<htemp->element<<"  ";
        htemp=htemp->next;
    }
}


int main()
{

   LList app1(44);
    LList app2(33);
  for(int i=0;i<3;i++)
  {
       cout<<"请输入第一个链表的数据：";
       int node;
       cin>>node;
       app1.append(node);
  }
   for(int i=0;i<3;i++)
  {
       cout<<"请输入第2个链表的数据：";
       int node;
       cin>>node;
       app2.append(node);
  }
  LList app3= Merger(app1,app2);
  display_item(app3);


return 0;
}
