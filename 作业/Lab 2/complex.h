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
	void readfile();//������д��complexObject�� 
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
		void add(double c,double d);//������� ���ļ��� 
		void delete_element(); //ͨ�����Ա�ɾ�����ݺ�д���ļ� 
         void save();//�������еĺ�Ȼ��д���ļ� 
         void compare(complex *list); 
}; 



