#include "iostream"
using namespace std;
class Link
{
public:
   int element;
   Link *next;
   Link(int node,Link *rnext)
   {
       element=node;
       next=rnext;
   }
   Link(Link* rnext){next=rnext;}
};

class LLink
{
   private:
    Link *head;
    //Link *tail;
    Link *curr;
   public:
    LLink()
    {
        head=new Link(NULL);
        head->next=head;//ѭ��
        curr=head;//ָ��ǰλ��,������β�ڵ��λ��
    }

   /* void append()
    {
         Link *curr=head;
        for(int i=0;i<4;i++)
        {
             int node;
        cout<<"������ڵ�����ݣ�";cin>>node;
        Link *p=new Link(node,NULL);

             p->next=head;//�˴������Ƚ�����ڵ���ͷ��������γ�ѭ��
             curr->next=p;//���½ڵ���ǰ��Ľڵ�����
             curr=curr->next;
        }

      }*/

      void append(int node)
      {
          Link *p=new Link(node,NULL);
          p->next=head;
          curr->next=p;
          curr=curr->next;

      }

      void display()
{
    Link *htemp=head->next;
     while(htemp!=head)//һ������β�ڵ㣬β�ڵ�ĵ�ַ��ָ�����head
     {
         cout<<htemp->element<<endl;
         htemp=htemp->next;
     }
     //cout<<htemp->next->element<<endl;//�˴���֤��ʱѭ������
}


     void insert_element(int node)
     {
         Link *p=new Link(node,NULL);
         Link *htemp=head->next;
         int n;
         cout<<"��������Ҫ����λ�õ�����:";cin>>n;
         while(htemp!=head)
         {
              if(htemp->element==n)
              {
                  p->next=htemp->next;
                  htemp->next=p;
              }
              htemp=htemp->next;
        }

     }

     //ԭ�����������ָ����λ�ã�һ��ָ��ɾ���ڵ��ǰ��һ����һ��ָ��ɾ���ڵ���������ѭ������
      void delete_element()
    {

        Link *htemp=head->next;//����ǲ�����ģ������ж�ѭ������
        Link *item=head;//ָ��ɾ���ڵ��ǰ��һ���ڵ�
        int node;
        cout<<"��������Ҫɾ���Ľڵ�����";cin>>node;
        while(htemp!=head)
        {

            if(htemp->element==node)
            {

                //item->next=item->next->next;
                item->next=htemp->next;
                delete htemp;//ɾ����ǰ�Ľڵ�
            }
            htemp=htemp->next;//ͬʱ������������ǰ��λ�ò���
            item=item->next;

        }

    }

//ͷ�巨����
    void reverse_element()
    {
        Link *p=head->next;
        head->next=head;//�˴�ʱ��ͷ���ѭ�����൱�ڳ�ʼ��,���Ǵ�ʱ��β�ڵ㻹��ָ��ͷ����
        while(p!=head)//�����ж�ѭ�������ǵ�ѭ��������ص�
        {
            Link *pnext=p->next;
            p->next=head->next;
            head->next=p;
            p=pnext;


        }

    }

    void destroy()
    {

    }

};






int main()
{
    LLink app;
    for(int i=0;i<3;i++)
    {
        int node;
        cout<<"������ڵ�����ݣ�";cin>>node;
        app.append(node);
    }
    app.display();

    /*int node;
    cout<<"���������ڵ�����ݣ�";cin>>node;
    app.insert_element(node);*/
    //app.delete_element();
    app.reverse_element();
    app.display();

return 0;
}
