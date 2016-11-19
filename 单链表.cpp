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
        tail->next=p;//���ڵ��β�ڵ�������һ��
        tail=tail->next;//��β�ڵ����ָ���²���Ľڵ�
    }
     void display()
     {
         Link *p=new Link(NULL);
         p=head->next;//ͷ��㲻�洢���ݣ����ָ��ͷ���ĵڶ����ڵ�
         while(p)
         {
             cout<<p->element<<"  ";
             p=p->next;
         }
     }
           //����find_element��insert_element�������Ĺ���
        /* void insert_element()
         {
             Link *p=new Link(NULL);
             Link *htemp=head;
             cout<<"���������ڵ������";
             cin>>p->element;
             cout<<endl;
             int node;
             cout<<"������Ҫ�����λ�õ����ݣ�";
             cin>>node;
             while(htemp)
             {
                 if(htemp->element==node)
                 {
                     p->next=htemp->next;//�˴���htemp->next�൱�ڽڵ�htemp�ڵ��ָ�룬��˿��Ժ�p->next����
                     htemp->next=p;
                     return ;//�ҵ�Ҫ�����λ��֮���Ҫ���أ�����һֱ������ȥ
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
             endf:cout<<"������Ҫ�����ɾ����λ�õ����ݣ�";
             cin>>node;
             Link *htemp=head;
             while(htemp)
             {
                  if(htemp->element==node)
                  {
                       return htemp;//����ҵ���ǰ��ָ���򷵻ؽڵ�ָ��
                  }
                  else
                  {
                      htemp=htemp->next;//ָ��ڵ����
                  }
             }
             cout<<"��Ҫ���ҵ�����λ�ò����ڣ�����������"<<endl;
             goto endf;
             }

             void insert_element()
             {
                Link *p=new Link(NULL);
                Link *htemp;
                cout<<"��������Ҫ����ڵ������:";
                cin>>p->element;
                htemp=find_element();//����Ҫ����Ľڵ�ָ��
                p->next=htemp->next;
                htemp->next=p;
            }
            //ɾ��ָ���Ľڵ�
            void delete_element()
            {
                  Link *htemp=head;
                  Link *p;
                  int node;
                  cout<<"����������Ҫɾ��������:";cin>>node;
                  while(htemp)
                  {
                      if(htemp->next->element==node)
                      {
                          p=htemp->next;//����Ҫɾ���Ľڵ�ָ��ָ��p,�Ա�ɾ��
                          htemp->next=htemp->next->next;//��ɾ���ڵ�ĺ���һ���ڵ���ǰ��һ���ڵ�����
                              delete p;
                              return ;
                      }
                      else
                        htemp=htemp->next;
                  }

            }
           //ͷ�巨����
            void reverse_element()
            {
                Link *p=head->next;
                //Link *pnext=head->next->next;
                head->next=NULL;
                while(p)
                {     Link *pnext=p->next;//������¼Ҫ����ڵ����һ��λ��
                      p->next=head->next;
                      head->next=p;
                      p=pnext;//��pָ��ָ����һ��λ��
                }
            }


            void destroy()//�����������ͷ��㣬��˻�Ҫ��������
            {
                 Link *curr;
                 while(head!=NULL)
                 {
                     curr=head;
                     head=head->next;
                     delete curr;
                 }

            }


             //�Ƚ����ݶ���������Ȼ���������������������źõ�����д�룻����
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
        cout<<"������ڵ������:"<<endl;
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




















