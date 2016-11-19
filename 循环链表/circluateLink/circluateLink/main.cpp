#include "iostream"
using namespace std;
class LLink;
class Link
{
private :
	int data;
	Link *next;
	Link *prev;
public:
	friend LLink;
	Link(int a, Link *r,Link *p);
	Link(Link *r,Link *p);

};


class LLink
{
private:
	Link *head;
	Link *tail;
public:
	LLink();
	void append();
	void display();
	void insert();
	void reverse();
	void swap(int &a, int &b);

};

Link::Link(int a, Link *r,Link *p)
{
	data = a;
	next = r;
	prev = p;
}
Link::Link(Link *r,Link *p)
{
	next = r;
	prev = p;
}

 LLink::LLink()
{
	head = new Link(NULL,NULL);
	tail = new Link(NULL,NULL);
	head->next = tail;
	tail->prev = head;
	tail->next = head;
	head->prev = tail;

}

 void LLink::append()
 {
	 int data;
	 cout << "input data:";
	 cin >> data;
	 Link *p = new Link(data, NULL, NULL);
	 p->next = tail;
	 p->prev = tail->prev;
	 tail->prev->next = p;//先后顺序是很重要的
	 tail->prev = p;
	 
 }


 void LLink::display()
 {
	 Link *p = head->next;
	
	 while (p != tail)
	 {
		
		 cout << p->data << "  ";
		 p = p->next;
	 }
	 cout << endl;
	 
 }

 void LLink::insert()
 {
	 int f;
	 cout << "input a data:";
	 cin >> f;
	 int n;
	 cout << "input this number where you want to insert:";
	 cin >> n;
	 Link *p = new Link(f, NULL, NULL);
	 Link *htemp = head->next;
	 while (htemp!=tail)
	 {
		 if (htemp->data == n)
		 {
			 p->next = htemp->next;
			 p->prev = htemp;
			 htemp->next->prev = p;
			 htemp->next = p;
		     
		 }
		 htemp = htemp->next;

	     
	 }
 }


 void LLink::reverse()
 {
	 Link *begin = head->next;
	 Link *end = tail->prev;
	 while (begin != end&&begin->prev != end)//当链表有偶数个节点时用begin->prev!=end来判断，当链表有奇数个节点时用begin!=end来判断
	 {
		 swap(begin->data, end->data);//交换前后对应节点的数据，不交换前后节点的指针
		 begin = begin->next;//节点后移
			 end = end->prev;//节点前移
	 }
 }
 void LLink::swap(int &a, int &b)
 {
	 int c = a;
	 a = b;
	 b = c;
 }

int main()
{
	LLink app;
	for (int i = 0; i < 3; i++)
	{
		app.append();
	}
	app.display();
	//app.insert();
	//app.display();
	app.reverse();
	app.display();
	return 0;
}