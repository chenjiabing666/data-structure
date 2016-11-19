#include "iostream"
using namespace std;
template <typename E>
class List
{
public:
    virtual ~List(){}
    List(){}
    virtual void clear()=0;
    virtual void insert(const E& item)=0;//插入
    virtual void append(const E& item)=0;//在末尾插入
    virtual E& getvalue()=0;
};
template <typename E>
class AList:public List<E>
{
private:
    int maxsize;//数组的最大长度
    int listsize;//数组已经存储的长度
    int curr;//标记的当前位置
    E* listArray;//创建的数组
   public:
       AList(int size)//创建列表
       {
            maxsize=size;
            listsize=curr=0;//将当前的位置标记到数组首部
            listArray=new E[maxsize];
       }
       virtual void clear()
       {
           delete [] listArray;
           listsize=curr=0;//此处数组中没有数据所以数组的长度为0
           listArray=new E[maxsize];
       }

       virtual void insert(const E& item)//在当前位置插入数据，并没有查找要插入的位置
       {
           if(listsize>maxsize)
            cout<<"数组已满";
           else
        {
            for(int i=listsize;i>curr;i--)//从后向前依次将数据向后移动直至要插入的位置
            {
                listArray[i]=listArray[i-1];//将数据向后移动
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
