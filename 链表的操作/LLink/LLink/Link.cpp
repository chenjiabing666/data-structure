#include "iostream"
#include "Link.h"
using namespace std;
Link::Link(int a, Link *n)
{
	data = a;
	next = n;
}
Link::Link(Link *n)
{
	next = n;
}

void LLink::append(int data)
{
	Link *p = new Link(data, NULL);
	tail->next = p;
	tail = p;
}

void LLink::display()
{
	Link *p = head->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	
	}
	cout << endl;
}

LLink::LLink()
{
	tail = head = new Link(NULL);
}

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

void LLink::reverse()
{
	Link *p = head->next; 
	head->next = NULL;
	while (p)
	{
		Link *pnext = p->next;
		p->next = head->next;
		head->next = p;
		p = pnext;
	}
}

void LLink::creat(int data)
{
	Link *p = new Link(data, NULL);
	p->next = head->next;
	head->next = p;
	tail = p;

}

/*void LLink::sort()//箱子排序
{
	Link **top, **bottom;//创建指针数组
	bottom = new Link*[101];//101这是数据的范围
	top = new Link *[101];
	for (int i = 0; i <= 100; i++)//将每一个箱子赋值为空
		bottom[i] = NULL;

    Link *firstNode = head;
	for (; firstNode != NULL; firstNode = firstNode->next)
	{
		int thebin = firstNode->data;//将每一个节点的数据部分转换为整数
		if (bottom[thebin] == NULL)
			bottom[thebin] = top[thebin] = firstNode;//这是将节点赋值给这个箱子，箱子存储的是节点
		else
		{
			top[thebin]->next = firstNode;//如果有大于两个相同的数，那么第一个数存储在底部的箱子，剩余的存储在底部的箱子的上面，用链表相连
			top[thebin] = firstNode;//此处相当于相同的数据转换后成为每一个箱子而这每一个箱子有如同链表的方式相互链接起来

		}
	}

	Link *y =NULL;//这里的指针是用来指向尾节点的
	for (int thebin = 0; thebin <= 100; thebin++)
	{
		if (bottom[thebin] != NULL)
		{
			if (y == NULL)
				firstNode = bottom[thebin];
			else//此处是判断是否有相同的箱子已经存储在底部
				y->next = bottom[thebin];

			     y = top[thebin];//此处相当于一个总是指向链表结尾的指针，用来链接后面的节点，
				                   // 因为相同的箱子已经链接好了并且底部的箱子已经与新的链表链接了，所以只需要指向最上面一层箱子就可以将指针指向尾指针了

		}
	}

	if (y != NULL)//这是必须的，将尾指针的地址域清空，用来判断打印
		y->next = NULL;
	delete[] bottom;
	delete[] top;

}*/

void LLink::sort_bin()
{
	Link **top, **bottom;
	top = new Link*[1010];
	bottom = new Link*[1010];
		for (int i = 0; i <= 10;i++)
			bottom[i] = NULL;
	    
		Link *firstnode = head;
		for (; firstnode != NULL; firstnode = firstnode->next)
		{
			int thebin = firstnode->data;
			if (bottom[thebin] == NULL)
				bottom[thebin] = top[thebin] = firstnode;
			else
			{
				top[thebin]->next = firstnode;
				top[thebin] = firstnode;

			}
		
		}

		Link *y = NULL;
		for (int thebin = 0; thebin <= 10; thebin++)
		{
			if (bottom[thebin] != NULL)
			{
				if (y == NULL)
					firstnode = bottom[thebin];
				else
					y->next = bottom[thebin];
				    y = top[thebin];
			}
		
		}

		if (y != NULL)
			y->next = NULL;
		delete[] bottom;
		delete[] top;


		
}
/*void LLink::sort1()//基数排序：基于箱子排序
{
	Link **bottom, **top;
	bottom = new Link*[10];
	top = new Link*[10];
	int i = 1;
	while (i <= 3)//3表示用数据的最大值是10的几次方
	{
		int a = pow(10, i);//这里是用来表示每一位的数字所用到得
		Link *firstnode = head;
		for (int i = 0; i <10; i++)
			bottom[i] = NULL;

		for (; firstnode != NULL; firstnode = firstnode->next)
		{
			int thebin = (firstnode->data%a) / pow(10, i-1);//每位上的数字表达式：firstnode->data%10^i/10^i-1
			if (bottom[thebin] == NULL)
				bottom[thebin] = top[thebin] = firstnode;
			else
			{
				top[thebin]->next = firstnode;
				top[thebin] = firstnode;
			}


		}

		Link *y = NULL;
		for (int thebin = 0; thebin <10; thebin++)
		{
			if (bottom[thebin] != NULL)
			{
				if (y == NULL)
					firstnode = bottom[thebin];
				else
					y->next = bottom[thebin];
				y = top[thebin];

			}
		}
		if (y != NULL)
		{
			y->next = NULL;
		}
		i++;
	}

	delete[] bottom;
	delete[] top;
}*/

int LLink::get_number(int n)
{
	int i = 0;
	int a = 1;
	int b = 0;//用来标记数组的数据，也就是链表的节点个数
	int data[100];
	Link *firstnode = head;
	int max = firstnode->data;
	for (; firstnode != NULL;firstnode = firstnode->next)//求出链表数据的最大值
	{

		data[b] = firstnode->data;//将链表的值读入数组以便比较最大值
		b++;
	}
	for (int i = 0; i <= b; i++)
	{
		if (max < data[i])
		{
			int a = max;
			max = data[i];
			data[i] = a;
		}
	}
	while (1)
	{
		if ((max / pow(n, a)>1))
			i++;
		else
			break;
		a++;
	}
	return i;//返回的是箱子排序算法要进行多少步
}


void LLink::sort()//完整版的用基数排序来对链表进行排序
{
	Link **bottom, **top;
	bottom = new Link*[10];
	top = new Link*[10];
	int i = 1;
	int num = get_number(10);//得到的是循环的步数
	while (i <= num)//num表示用数据的最大值是10的几次方
	{
		int a = pow(10, i);//这里是用来表示每一位的数字所用到得
		Link *firstnode = head;
		for (int i = 0; i <10; i++)
			bottom[i] = NULL;

		for (; firstnode != NULL; firstnode = firstnode->next)
		{
			int thebin = (firstnode->data%a) / pow(10, i - 1);//每位上的数字表达式：firstnode->data%10^i/10^i-1
			if (bottom[thebin] == NULL)
				bottom[thebin] = top[thebin] = firstnode;
			else
			{
				top[thebin]->next = firstnode;
				top[thebin] = firstnode;
			}


		}

		Link *y = NULL;
		for (int thebin = 0; thebin <10; thebin++)
		{
			if (bottom[thebin] != NULL)
			{
				if (y == NULL)
					firstnode = bottom[thebin];
				else
					y->next = bottom[thebin];
				y = top[thebin];

			}
		}
		if (y != NULL)
		{
			y->next = NULL;
		}
		i++;
	}

	delete[] bottom;
	delete[] top;
	}











