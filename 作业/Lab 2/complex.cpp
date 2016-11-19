#include "iostream" 
#include "fstream"
#include "complex.h" 
using namespace std;
complex operator+(complex &c1,complex &c2)
{
    complex c3;
    c3.a=c1.a+c2.a;
    c3.b=c1.b+c2.b;
    return c3;
} 
 complex::complex(double c,double d) 
{
    a=c;
    b=d;
} 

void complex::readfile()
{
    ifstream infile;
    ofstream outfile;
    complex result;//计算总和 
    complex small;//存储数据便于计算 
    double a,b;//用于读取数据 
    char c,d;
    outfile.open("complexObj.txt",ios::out);
 	infile.open("complex.txt",ios::in);
	if(outfile.fail()||infile.fail())
	{
	    cout<<"文件打开或者创建失败"<<endl; 
	    exit(0); 
	} 
	
	while(1)
	{
		infile>>a>>c>>b>>d;//读取文件中的数据
		if(infile.eof())//到了文件尾就跳出循环 
		break; 
		outfile<<a<<c<<b<<d<<endl;//存储在complexObj中 
	}
		
	
	
	
	
} 

	ostream& operator<<(ostream &out,complex c)
		{
			if(c.b>=0)
			{
			   out<<c.a<<"+"<<c.b<<"i"<<endl; 
			} 
			else
			{
			   out<<c.a<<c.b<<"i"<<endl; 
			} 
			return out;
		}
		
		LList::LList(int size)
		{
			maxsize=size;
			listArray=new complex[maxsize];
			listsize=0;
			 
		   
		} 
		//先将数据读入线性表然后删除操作最后再重新写入文件 
		void LList::add(double c,double d) 
		{
			
		     ofstream outfile;
		     outfile.open("complexObj.txt",ios::app);//在文件尾追加数据 
		     if(outfile.fail())
			 {
			    cout<<"打开文件失败"<<endl;
				exit(0); 
			 } 
			 if(d>=0)
			 outfile<<c<<"+"<<d<<"i"<<endl;
			 else
			 outfile<<c<<d<<"i"<<endl;
			 outfile.close(); 
		}
		
		void LList::delete_element()
		{
			double a,b;
			char d,c;
			int n;//删除的数据位置 
		   ifstream infile;
		   ofstream outfile;
		   infile.open("complexObj.txt",ios::in); 
		   //outfile.open("complexObj.txt",ios::out);
		if(infile.fail())
	{
	    cout<<"文件打开或者创建失败"<<endl; 
	    exit(0); 
	} 
	
	while(1)//将数据读入线性表中 
	{
		cout<<listsize<<endl;
	   	infile>>a>>c>>b>>d;//读取文件中的数据
	
		listArray[listsize].a=a;
		listArray[listsize].b=b; 
		listsize++;
			if(infile.eof())//到了文件尾就跳出循环 
		break; 
	} 
    cout<<"请输入你想要删除第几个数据：";cin>>n;
	for(int i=n-1;i<listsize-1;i++)
	{
	    listArray[i]=listArray[i+1]; 
	} 
	listsize--;
	outfile.open("complexObj.txt",ios::out);
	 
	for(int i=0;i<listsize-1;i++)
	{
	   if(listArray[i].b>=0)
	       outfile<<listArray[i].a<<"+"<<listArray[i].b<<"i"<<endl; 
	   else
	    outfile<<listArray[i].a<<listArray[i].b<<"i"<<endl; 
	} 
	infile.close();
	outfile.close(); 
	} 
	
	void LList::save()
	{
		ifstream infile;
		ofstream outfile;
			double a,b;
			char d,c;
			complex result;
			infile.open("complexObj.txt",ios::in); 
		while(1)//将数据读入线性表中 
	{
		cout<<listsize<<endl;
	   	infile>>a>>c>>b>>d;//读取文件中的数据
	
		listArray[listsize].a=a;
		listArray[listsize].b=b; 
		listsize++;
			if(infile.eof())//到了文件尾就跳出循环 
		break; 
	}
	
	for(int i=0;i<listsize-1;i++)
	{
		cout<<listArray[i]<<endl; 
	    result=result+listArray[i]; 
	} 
	infile.close(); 
	outfile.open("complexresult.txt",ios::out);
	if(outfile.fail())
	{
	   cout<<"open the txt fail"<<endl;
	   exit(0); 
	} 
	if(result.b>=0) 
	outfile<<"所有数据之和为："<<result.a<<"+"<<result.b<<"i"<<endl; 
	else
	outfile<<"所有数据之和为："<<result.a<<result.b<<"i"<<endl; 
	} 
	
	
	void LList::compare(complex *list)
	{
	    
	} 
	
		
	
	
	
	
	
