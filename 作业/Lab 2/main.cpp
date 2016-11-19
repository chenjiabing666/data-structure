#include <iostream>
#include "complex.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	LList s(100);
	int i;
	cout<<"(1)添加数据"<<endl<<"(2)删除数据"<<endl<<"(3)计算结果"<<endl<<"请输入你想要执行的操作：";
	cin>>i; 
	switch(i)
	{
	case 1: 
	{
		double c,d;
		cout<<"请输入你想要输入的复数实数部分：";
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
