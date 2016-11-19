#include "iostream"
using namespace std;
template <class E>
class List
{
public:
    virtual void insert(E item)=0;
    //virtual void append()=0;
    virtual void input(int n)=0;
    virtual void display()=0;
    virtual int findindex(E item)=0;
};
template <class E>
class AList:public List<E>
{
public:
    AList(int size)
    {
       maxsize=size;
       listsize=0;
       listArray=new E[maxsize];
    }
    void insert(E item)
    {
        cout<<"请输入你想要插入的位置的数：";
        E s;cin>>s;
        int n=findindex(s);
        for(int i=listsize;i>n;i--)
        {
           listArray[i]=listArray[i-1];
        }
        listArray[n]=item;
        listsize++;
    }

    void display()
    {
        for(int i=0;i<listsize;i++)
        {
            cout<<listArray[i]<<"  ";
        }
        cout<<endl;
    }

    void input(int n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<"请输入你想要输入的数据：";
            cin>>listArray[i];
        }
    }

    int findindex(E item)
    {
       for(int i=0;i<listsize;i++)
       {
           if(item==listArray[i])
            return i;
       }
    }

private:
    int maxsize;
    int listsize;
    E* listArray;

};

int main()
{
    AList<int> stu(55);
    stu.input(4);
    stu.display();
    int item;
    cout<<"输入你想要插入的数据：";cin>>item;
    stu.insert(item);
    stu.display();

return 0;
}
