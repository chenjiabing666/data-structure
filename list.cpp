#include "iostream"
using namespace std;
template <typename E>
class List
{
public:
    virtual ~List(){}
    List(){}
    virtual void clear()=0;
    virtual void insert(const E& item)=0;//����
    virtual void append(const E& item)=0;//��ĩβ����
    virtual E& getvalue()=0;
};
template <typename E>
class AList:public List<E>
{
private:
    int maxsize;//�������󳤶�
    int listsize;//�����Ѿ��洢�ĳ���
    int curr;//��ǵĵ�ǰλ��
    E* listArray;//����������
   public:
       AList(int size)//�����б�
       {
            maxsize=size;
            listsize=curr=0;//����ǰ��λ�ñ�ǵ������ײ�
            listArray=new E[maxsize];
       }
       virtual void clear()
       {
           delete [] listArray;
           listsize=curr=0;//�˴�������û��������������ĳ���Ϊ0
           listArray=new E[maxsize];
       }

       virtual void insert(const E& item)//�ڵ�ǰλ�ò������ݣ���û�в���Ҫ�����λ��
       {
           if(listsize>maxsize)
            cout<<"��������";
           else
        {
            for(int i=listsize;i>curr;i--)//�Ӻ���ǰ���ν���������ƶ�ֱ��Ҫ�����λ��
            {
                listArray[i]=listArray[i-1];//����������ƶ�
            }
            listArray[curr]=item;
            listsize++;
        }


       }
       virtual void append(const E& item);
       virtual E& getvalue();




};

int main()
{



return 0;
}
