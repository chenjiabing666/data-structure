#include "iostream"
using namespace std;

/*class Link
{
public:
Link *next;
int element;
Link(int node,Link *rnext){
	next=rnext;
	element=node;
	}

	Link(Link *rnext)
	{
		next=rnext;
	}


	
};


class LLink
{
	public:
		LLink(int node)
		{
			head=tail=new Link(NULL);
			
		}
		
		void append(int node)
		{
			Link *p=new Link(node,NULL);
			tail->next=p;
			tail=tail->next;
			
		}
		
		void display()
		{
			Link *htemp=head->next;
			while(htemp)
			{
				cout<<htemp->element<<"  ";
				htemp=htemp->next;
				
			}
			cout<<endl;
			
		}
		
		void insert_element(int node)
		{
		
			Link *p=new Link(node,NULL);
			Link *htemp=head->next;
			cout<<"请输入你想要插入位置的数据：";int n;cin>>n;
			if(p==NULL)
			{
			    cout<<"vfkz"<<endl; 
			} 
			else
			{
				while(htemp)
				{
				  if(htemp->element==n)
				  {
				        p->next=htemp->next;
						htemp->next=p; 
				  } 
			   
			      
				  htemp=htemp->next;
		 
				}
				
			}
			
		}
		
		
		void delete_element()
		{
			int node;
			cout<<"请输入你想要删除的节点的数据：";cin>>node;
			Link *htemp=head;
			while(htemp!=tail)
			{
				     if(htemp->next->element==node) 
			     {
			     	if(tail==htemp->next)
					 {
					 	cout<<"kv"<<endl; 
					     Link *p=htemp->next;
					     tail=htemp;
					     htemp->next=htemp->next->next;
					     delete p;
					 } 
					 else
					 {
					    Link *p=htemp->next;
					    htemp->next=htemp->next->next;
					    delete p;
					 } 
			     	
			     	
				      
				 } 
				 
				 htemp=htemp->next;
			} 
			
				
			 
		    
		} 
		
		
		void reverse_element()
		{
		Link *p=head->next;
		head->next=NULL;
		while(p)
		{
		    Link *pnext=p->next;
		    p->next=head->next;
		    head->next=p;
		    p=pnext;
		
		} 
		} 
		
	private:
		Link *head;
		Link *tail;
		
};


int main()
{
	LLink app(3);
for(int i=0;i<4;i++)
{
	cout<<"请输入数据：";int node;cin>>node;
	app.append(node);
	
}

app.display();

//app.insert_element(99);
//app.display();

//app.delete_element();
app.reverse_element();
app.display();
	
	return 0;
}*/




class Link
{
public:
	Link *next;
	Link *prev;
	int element;
	Link(int node,Link *rprev,Link *rnext)
	{
	    element=node;
	    prev=rprev;
	    next=rnext;
	} 
	
	Link(Link *rprev,Link *rnext) 
	{
	   prev=rprev;
	   rnext=next;
	} 
}; 

class DbLink
{
 public:
 	DbLink(int node)
	 {
	     head=new Link(NULL,NULL);
		 tail=new Link(NULL,NULL);
		 head->next=tail;
		 tail->prev=head; 
	 } 
	 
	 void append(int node)
	 {
	    Link *p=new Link(node,NULL,NULL);
		p->next=tail;
		p->prev=tail->prev;
		tail->prev->next=p;
		tail->prev=p; 
	 } 
	 
	 
	 void display()
	 {
	 	//cout<<head->next->element;
	 	//cout<<endl<<tail->prev->element<<endl;
	    Link *htemp=head->next;
	    while(htemp!=tail)
		{
		    cout<<htemp->element<<"  ";
			htemp=htemp->next; 
		} 
		cout<<endl;
	 } 
	 
	 void swap(int &a,int &b) 
	 {
	 	int c=a;
	 	a=b;
	 	b=c;

	 } 
	 
	 void reverse_element()
	 {
	      Link *end=tail;
	      Link *begin=head;
	      while(begin!=end&&begin->prev!=end)
		  {
		      swap(begin->element,end->element);
			  begin=begin->next;
			  end=end->prev; 
		  } 
	 }
	 
	 
	 void  insert_element(int node)
	 {
	    Link *p=new Link(node,NULL,NULL);
		Link *htemp=head->next;
		
		int n;
		cout<<"请输入你想要插入位置的数据:";cin>>n; 
		while(htemp!=tail)
		{
			if(htemp->element==n)
			{
				p->next=htemp->next;
				p->prev=htemp;
				htemp->next->prev=p;
				htemp->next=p;
			   
			} 
			
			htemp=htemp->next;
		
		} 
	 } 
	 
	 
	 void delete_element()
	 {
	 	cout<<"请输入想要删除的数据"<<endl;
		 int node;
		 cin>>node;
		 Link *htemp=head;
		 while(htemp!=tail)
		 {
		      if(htemp->next->element==node)
			  {
			      Link *p=htemp->next;
			      htemp->next->prev=htemp;
			      htemp->next=htemp->next->next;
			  } 
			  
			  htemp=htemp->next;
		 } 
	     
	 } 
 private:
 	Link *head;
 	Link *tail;
 	
} ;

int main()
{
	DbLink app(4); 
	for(int i=0;i<3;i++)
	{
		int node;
		cout<<"请输入节点的数据：";cin>>node; 
	    app.append(node);
	} 
	app.display();
	
	//app.reverse_element();
	int node;
	//cout<<"输入你想要插入的数据：";cin>>node; 
	//app.insert_element(node);
	app.delete_element();
	
	app.display(); 
	

return 0;} 
















