#include "iostream"
#include "stack.h"
using namespace std;
stack::stack(int size)
{
   maxsize=size;
   top=0;
   listArray=new double[maxsize]; 
} 

void stack::push(double node)
{
	if(top==maxsize)
	cout<<"stack is full"<<endl;
	else
	{
	    listArray[top]=node;
		top++; 
	} 

} 




double stack::pop()
{
    if(top==0)
	cout<<"stack is empty"<<endl;
	else
	{
	    return listArray[--top]; 
	} 
} 


void stack::Convert(double node)
{
	
	  
    int a=node;//整数部分 
    double b=node-a;//小数部分
    double small[100];//用来存储二进制小数部分 
    int i=0;
    
      if(a==0)
	{
	     cout<<"0"; 
	} 
	
	else
	{ 
	
	while(a!=0) //得到整数部分的二进制 
	{
		double flag=a%2;//余数 
	    push(flag); //入栈 
	    a=(a-a%2)/2; //得到后面的数 
	}
	 while(top>0)
	{
	   cout<<pop(); //输出二进制整数部分 
	} 
    }
        
         if(b!=0) //如果存在小数部分 
         { 
	  while(1)//转换小数部分 
	{
	
	    double left=b*2;
	    if(left<1)
	    { 
	    b=left;
		small[i]=0; 
	    }
		else if(left>1)
		{ 
		b=left-1;
		small[i]=1;
	    }
	    else//left==1
	    {
	       small[i]=1; 
	    	b=left;
	    	break;//跳出循环 
		    
		} 
		 
		 i++;
	} 
	
     
	cout<<".";//输出小数点 
	for(int j=0;j<=i;j++)
	{
	    cout<<small[j]; 
	} 
}
      else//不存在小数部分直接跳出 
      {
	      return;
	  } 

	

	 
} 
