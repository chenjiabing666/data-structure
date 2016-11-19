class Link
{
public:
	Link *next;
	int data;
	Link(int a, Link *n);
	Link(Link *n);

};

class LLink
{
private:
	Link *head;
	Link *tail;
public:
	LLink();
	void display();
	void append(int data);
	void insert(int data);
	void reverse();
	void sort_bin();//箱子排序不能对字符串排序
	void creat(int data);//头插法创建单链表
	void sort();
	void sort1();
	int get_number(int n);


};