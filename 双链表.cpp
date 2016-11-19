#include "iostream"
using namespace std;
class Link
{
 public:
     Link *next;//ָ������һ���ڵ�
     Link *prev;//ǰ��ָ��ǰ��һ���ڵ�
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


class DbLink//˫�����ͷ����β�ڵ㶼����������
{
   private:
       Link *head;
       Link *tail;
   public:
    DbLink(int n)
{
    head=new Link(NULL,NULL);
    tail=new Link(NULL,NULL);

    head->next=tail;//ǰ��ڵ㶼�ǲ��洢���ݵģ�������������ɵ�ʱ�����ͬʱ����ͷβ�ڵ㣬������������
    tail->prev=head;
}
void append(int node)//��β�ڵ����ӽڵ㣬��β�ڵ��ǰ��Ľڵ�֮������µĽڵ㣬��Ϊβ�ڵ㲻��������
{
    Link *htemp=new Link(node,NULL,NULL);//����һ���½ڵ㲢�ҽ���ַ��ֵΪ��
    htemp->next=tail;
    htemp->prev=tail->prev;//tail->prev��ʾǰ��Ľڵ㣬�˾佫�½ڵ���ǰ��Ľڵ�����
    tail->prev->next=htemp;//�����Ƚ�htemp��ǰ��Ľڵ����ӣ������Ⱥ�tail���ӵĻ����޷�ͨ��tail�ҵ�ǰ��Ľڵ�
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
    cout<<"����������Ҫ����λ�õ����ݣ�";
    cin>>finditem;

    while(p!=tail)
    {
        //  cout<<"�¼Ұ���"<<endl;
       if(p->element==finditem)
       {
           htemp->next=p->next;
           htemp->prev=p;
           p->next->prev=htemp;//������Ҫִ����һ������ִ����һ���������޷�ͨ��p�ҵ���һ���ڵ�
           p->next=htemp;
       }
       p=p->next;
    }

}

//Ҫ�ҵ���Ҫɾ���ڵ��ǰһ���ڵ�
void delete_element(int node)//node��ʾҪɾ��������
{
    Link *htemp=head;
    while(htemp!=tail)
    {

        if(htemp->next->element==node)//�����ʽ������ôhtemp���Ǳ�ɾ�ڵ��ǰһ���ڵ�
        {
            Link *p=htemp->next;//��ɾ��֮ǰ����Ҫ��һ��ָ�뱣��ڵ㣬�Ա����ִ��ɾ������

            htemp->next->next->prev=htemp;//��htemp�뱻ɾ�ڵ����һ���ڵ�������
            htemp->next=htemp->next->next;//����ɾ�ڵ����һ���ڵ�ĺ��������
            delete p;
        }

            htemp=htemp->next;
    }
}


//���ǽ����ڵ������������
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
    while(begin!=end&&begin->prev!=end)//��������ż�����ڵ�ʱ��begin->prev!=end���жϣ����������������ڵ�ʱ��begin!=end���ж�
    {
         swap(begin->element,end->element);//����ǰ���Ӧ�ڵ�����ݣ�������ǰ��ڵ��ָ��
         begin=begin->next;//�ڵ����
         end=end->prev;//�ڵ�ǰ��
    }

}


/*void reverse_element()
{
    Link *curr=head;
    Link *p=head;//����
    head=tail;

    tail=p;
    while(curr)
    {

      Link *htemp=curr->next;
      curr->next=curr->prev;
      curr->prev=htemp;//����
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
      cout<<"��������ӽڵ������:";cin>>node;
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














