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
	void sort_bin();//���������ܶ��ַ�������
	void creat(int data);//ͷ�巨����������
	void sort();
	void sort1();
	int get_number(int n);


};