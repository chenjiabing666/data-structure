#include <iostream>
#include "complex.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	LList s(100);
	int i;
	cout<<"(1)�������"<<endl<<"(2)ɾ������"<<endl<<"(3)������"<<endl<<"����������Ҫִ�еĲ�����";
	cin>>i; 
	switch(i)
	{
	case 1: 
	{
		double c,d;
		cout<<"����������Ҫ����ĸ���ʵ�����֣�";
		cin>>c>>d; 
	   s.add(c,d);
	   break;
	} 
	case 2:
		{
		    s.delete_element();
		    break;
		} 
		
		case 3:
			{
			   s.save();
			} 
	} 



	
	
	
	return 0;
}
