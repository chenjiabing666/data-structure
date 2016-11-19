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
              
             p=p->next;//���ڵ�����ƶ�
         
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
  private:
    Link* head;
    Link* curr;
    Link* tail;
};


int main()
{

   LList app(44);
   //app.insert();
   for(int i=0;i<4;i++)
   {
       cout<<"������ڵ�����ݣ�";
       int node;
       cin>>node;
          app.append(node);

   }
   app.display();
  app.insert(78);
 // app.reverse_element();
  app.display();

return 0;
}
