#include "iostream"
using namespace std;

class Link
{
public:
    Link *next;
    int  element;
    Link(Link *rnext){next=rnext;}
    Link(int node,Link *rnext){element=node;next=rnext;}
};

class LLink
{
public:
    LLink(int n)
    {
        head=tail=curr=new Link(NULL);
    }
    void append(int node)
    {
        Link *p=new Link(NULL);
        p->element=node;
        tail->next=p;//将节点和尾节点连接在一起
        tail=tail->next;//将尾节点后移指向新插入的节点
    }
     void display()
     {
         Link *p=new Link(NULL);
         p=head->next;//头结点不存储数据，因此指向头结点的第二个节点
         while(p)
         {
             cout<<p->element<<"  ";
             p=p->next;
         }
     }
           //这是find_element和insert_element合起来的功能
        /* void insert_element()
         {
             Link *p=new Link(NULL);
             Link *htemp=head;
             cout<<"请输入插入节点的数据";
             cin>>p->element;
             cout<<endl;
             int node;
             cout<<"请输入要插入的位置的数据：";
             cin>>node;
             while(htemp)
             {
                 if(htemp->element==node)
                 {
                     p->next=htemp->next;//此处的htemp->next相当于节点htemp节点的指针，因此可以和p->next相连
                     htemp->next=p;
                     return ;//找到要插入的位置之后就要返回，以免一直的找下去
                 }
                 else
                 {
                     htemp=htemp->next;
                 }
             }


         }*/

         Link* find_element()
         {
             int node;
             endf:cout<<"请输入要插入或删除的位置的数据：";
             cin>>node;
             Link *htemp=head;
             while(htemp)
             {
                  if(htemp->element==node)
                  {
                       return htemp;//如果找到当前的指针则返回节点指针
                  }
                  else
                  {
                      htemp=htemp->next;//指针节点后移
                  }
             }
             cout<<"你要查找的数据位置不存在，请重新来过"<<endl;
             goto endf;
             }

             void insert_element()
             {
                Link *p=new Link(NULL);
                Link *htemp;
                cout<<"请输入你要插入节点的数据:";
                cin>>p->element;
                htemp=find_element();//返回要插入的节点指针
                p->next=htemp->next;
                htemp->next=p;
            }
            //删除指定的节点
            void delete_element()
            {
                  Link *htemp=head;
                  Link *p;
                  int node;
                  cout<<"请输入你想要删除的数据:";cin>>node;
                  while(htemp)
                  {
                      if(htemp->next->element==node)
                      {
                          p=htemp->next;//将想要删除的节点指向指针p,以便删除
                          htemp->next=htemp->next->next;//将删除节点的后面一个节点与前面一个节点相连
                              delete p;
                              return ;
                      }
                      else
                        htemp=htemp->next;
                  }

            }
           //头插法逆置
            void reverse_element()
            {
                Link *p=head->next;
                //Link *pnext=head->next->next;
                head->next=NULL;
                while(p)
                {     Link *pnext=p->next;//用来记录要插入节点的下一个位置
                      p->next=head->next;
                      head->next=p;
                      p=pnext;//将p指针指向下一个位置
                }
            }


            void destroy()//销毁链表包括头结点，因此还要重新申请
            {
                 Link *curr;
                 while(head!=NULL)
                 {
                     curr=head;
                     head=head->next;
                     delete curr;
                 }

            }


             //先将数据读入数组中然后利用数组进行排序，最后将排好的数据写入；链表
            void sort()
            {
                int a[100];
                Link *p;
                int i;
                int listsize=0;
                for(p=head,i=0;p->next!=NULL;p=p->next,i++)
                {
                    listsize++;
                    a[i]=p->next->element;


                }
                for(int i=0;i<listsize-1;i++)
                {
                   for(int j=i+1;j<listsize;j++)
                   {
                       if(a[i]<a[j])
                       {
                            int c=a[i];
                            a[i]=a[j];
                            a[j]=c;
                       }
                   }
                }



                for(p=head,i=0;p->next!=NULL;i++,p=p->next)

                {
                    p->next->element=a[i];
                }




            }






private:
    Link *head;
    Link *tail;
    Link *curr;


};
int main()
{
    LLink stu(6);

    for(int i=0;i<4;i++)
    {
        int n;
        cout<<"请输入节点的数据:"<<endl;
        cin>>n;
        stu.append(n);

    }


    stu.display();
    cout<<endl;


    //stu.insert_element();

    //stu.display();
    //stu.delete_element();

    //stu.reverse_element();
   // stu.destroy();
    stu.display();

return 0;
}




















