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
    complex result;//�����ܺ� 
    complex small;//�洢���ݱ��ڼ��� 
    double a,b;//���ڶ�ȡ���� 
    char c,d;
    outfile.open("complexObj.txt",ios::out);
 	infile.open("complex.txt",ios::in);
	if(outfile.fail()||infile.fail())
	{
	    cout<<"�ļ��򿪻��ߴ���ʧ��"<<endl; 
	    exit(0); 
	} 
	
	while(1)
	{
		infile>>a>>c>>b>>d;//��ȡ�ļ��е�����
		if(infile.eof())//�����ļ�β������ѭ�� 
		break; 
		outfile<<a<<c<<b<<d<<endl;//�洢��complexObj�� 
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
		//�Ƚ����ݶ������Ա�Ȼ��ɾ���������������д���ļ� 
		void LList::add(double c,double d) 
		{
			
		     ofstream outfile;
		     outfile.open("complexObj.txt",ios::app);//���ļ�β׷������ 
		     if(outfile.fail())
			 {
			    cout<<"���ļ�ʧ��"<<endl;
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
			int n;//ɾ��������λ�� 
		   ifstream infile;
		   ofstream outfile;
		   infile.open("complexObj.txt",ios::in); 
		   //outfile.open("complexObj.txt",ios::out);
		if(infile.fail())
	{
	    cout<<"�ļ��򿪻��ߴ���ʧ��"<<endl; 
	    exit(0); 
	} 
	
	while(1)//�����ݶ������Ա��� 
	{
		cout<<listsize<<endl;
	   	infile>>a>>c>>b>>d;//��ȡ�ļ��е�����
	
		listArray[listsize].a=a;
		listArray[listsize].b=b; 
		listsize++;
			if(infile.eof())//�����ļ�β������ѭ�� 
		break; 
	} 
    cout<<"����������Ҫɾ���ڼ������ݣ�";cin>>n;
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
		while(1)//�����ݶ������Ա��� 
	{
		cout<<listsize<<endl;
	   	infile>>a>>c>>b>>d;//��ȡ�ļ��е�����
	
		listArray[listsize].a=a;
		listArray[listsize].b=b; 
		listsize++;
			if(infile.eof())//�����ļ�β������ѭ�� 
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
	outfile<<"��������֮��Ϊ��"<<result.a<<"+"<<result.b<<"i"<<endl; 
	else
	outfile<<"��������֮��Ϊ��"<<result.a<<result.b<<"i"<<endl; 
	} 
	
	
	void LList::compare(complex *list)
	{
	    
	} 
	
		
	
	
	
	
	
