#include "iostream"//�������Ĵ��麯������ȫ����������ʵ�ֲ��ܱ���ɹ�
using namespace std;
class List
{
  public:
      List(){}
      virtual void insert(double item)=0;
      virtual void append(double item)=0;
      //virtual void clear()=0;
      virtual void input(int n)=0;
       virtual void print()=0;
      //virtual void and();

};
class AList:public List
{
private:
    int curr;
    int listsize;
    int maxsize;
    double* listArray;
public:
    AList(){}
    AList(int size)
    {
        maxsize=size;
        listsize=curr=0;
        listArray=new double[maxsize];
    }


     void insert(double item)
    {
        if(listsize>maxsize)
            cout<<"��������"<<endl;
        else{

            for(int i=listsize;i>curr;i--)
            {
                listArray[i]=listArray[i-1];
            }
            listArray[curr]=item;
            listsize++;
        }
    }


   void append(double item)//ֱ���������ĩβ�������
    {
         if(listsize>maxsize)
        cout<<"��������"<<endl;
        else
        {
             listArray[listsize]=item;
             listsize++;
        }
    }

    void input(int n)
       {
           for(int i=0;i<n;i++)
           {
                cout<<"����������Ҫ���������:";
                cin>>listArray[i];
                curr++;
                listsize++;
           }
       }
       void print()
       {
             for(int i=0;i<listsize;i++)
             {
                 cout<<listArray[i]<<"  ";
             }
       }



};
int main()
{
AList stu(44);
stu.input(4);
stu.print();
cout<<endl;
stu.append(99);
stu.print();



return 0;
}
