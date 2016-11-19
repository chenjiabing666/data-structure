#include "iostream"
using namespace std; 
class LList; 
class complex
{
	private:
		double a;
  	    double b;
    public:
    	friend LList;
	
	complex(double c=0,double d=0); 
	void readfile();//将数据写入complexObject中 
	friend complex operator+(complex &c1,complex &c2); 
	friend ostream & operator<<(ostream &out,complex c); 
	   
  	
};

class LList
{
private:
	int listsize;
	int maxsize;
	complex *listArray;
	public:
		LList(int size=0); 
		void add(double c,double d);//添加数据 到文件中 
		void delete_element(); //通过线性表删除数据后写入文件 
         void save();//计算其中的和然后写入文件 
         void compare(complex *list); 
}; 



