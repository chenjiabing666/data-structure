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


      void append(int node)//�����������ӽڵ�,Ҳ���������������������
      {
          Link* p=new Link();
          p->element=node;
          tail->next=p;//���½��Ľڵ���β�ڵ�����
          tail=tail->next;//��β�ڵ�����ƶ�
      }

      void display()
      {
         Link* p=head->next;
         while(p!=NULL)
         {
     //        cout<<"ccc"<<endl;
             cout<<p->element<<"  ";//ͷ��㲻�洢���ݣ����Խ�ָ��ָ����������;
             p=p->next;//��ָ�����


         }
      }

       void insert(int node)
      {
          Link *p=head;
          Link* item=new Link();
          if(p==NULL)
            cout<<"�¼ӱ�"<<endl;
          cout<<"��������Ҫ����ڵ�����ݣ�";cin>>item->element;
          item->next=NULL;
          while(p)
          {

              //cout<<"fvjld"<<endl;
             if(p->element==node)//���ҹؼ��ڵ�
             {
                 item->next=p->next;
                 p->next=item;

              }
              else{
             p=p->next;//���ڵ�����ƶ�
          }
          }

      }


      //ͷ�巨��ԭ������Ȳ��������󣬺�������ǰ�棬������head���һ���ڵ�֮�����ڵ㣬����ǿձ��൱��������ͷ��ӽڵ�
      void reverse_element()
      {
          if(head==NULL)
             return ;
                Link *p=head->next;//��ָ��ָ���һ���ڵ㣬�����һ���ڵ�ĵ�ַ
                Link *pnext=NULL;
                head->next=NULL;//�������ͷ��������Ľڵ�Ͽ����γɵ�һ��ͷ���
                while(p!=NULL)
                {
                    pnext=p->next;//��ָ��ָ�������Ľڵ�ĺ���һ���ڵ�
                    p->next=head->next ;//���ڵ���뵽ͷ�����棬����ǵ�һ���ڵ��൱��head->next=NULL
                    head->next=p;
                    p=pnext;//ָ��pָ������һ���ڵ㷴������
                }
                return ;

      }


      void Merger(LList &a,LList &b)

      {
          LList c(3);//�´�����һ������
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

//�ϲ���������
 LList Merger(LList &a,LList &b)

      {
          LList c(3);//�´�����һ������
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
       cout<<"�������һ����������ݣ�";
       int node;
       cin>>node;
       app1.append(node);
  }
   for(int i=0;i<3;i++)
  {
       cout<<"�������2����������ݣ�";
       int node;
       cin>>node;
       app2.append(node);
  }
  LList app3= Merger(app1,app2);
  display_item(app3);


return 0;
}
