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
	
	  
    int a=node;//�������� 
    double b=node-a;//С������
    double small[100];//�����洢������С������ 
    int i=0;
    
      if(a==0)
	{
	     cout<<"0"; 
	} 
	
	else
	{ 
	
	while(a!=0) //�õ��������ֵĶ����� 
	{
		double flag=a%2;//���� 
	    push(flag); //��ջ 
	    a=(a-a%2)/2; //�õ�������� 
	}
	 while(top>0)
	{
	   cout<<pop(); //����������������� 
	} 
    }
        
         if(b!=0) //�������С������ 
         { 
	  while(1)//ת��С������ 
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
	    	break;//����ѭ�� 
		    
		} 
		 
		 i++;
	} 
	
     
	cout<<".";//���С���� 
	for(int j=0;j<=i;j++)
	{
	    cout<<small[j]; 
	} 
}
      else//������С������ֱ������ 
      {
	      return;
	  } 

	

	 
} 
