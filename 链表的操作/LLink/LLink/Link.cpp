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

/*void LLink::sort()//��������
{
	Link **top, **bottom;//����ָ������
	bottom = new Link*[101];//101�������ݵķ�Χ
	top = new Link *[101];
	for (int i = 0; i <= 100; i++)//��ÿһ�����Ӹ�ֵΪ��
		bottom[i] = NULL;

    Link *firstNode = head;
	for (; firstNode != NULL; firstNode = firstNode->next)
	{
		int thebin = firstNode->data;//��ÿһ���ڵ�����ݲ���ת��Ϊ����
		if (bottom[thebin] == NULL)
			bottom[thebin] = top[thebin] = firstNode;//���ǽ��ڵ㸳ֵ��������ӣ����Ӵ洢���ǽڵ�
		else
		{
			top[thebin]->next = firstNode;//����д���������ͬ��������ô��һ�����洢�ڵײ������ӣ�ʣ��Ĵ洢�ڵײ������ӵ����棬����������
			top[thebin] = firstNode;//�˴��൱����ͬ������ת�����Ϊÿһ�����Ӷ���ÿһ����������ͬ����ķ�ʽ�໥��������

		}
	}

	Link *y =NULL;//�����ָ��������ָ��β�ڵ��
	for (int thebin = 0; thebin <= 100; thebin++)
	{
		if (bottom[thebin] != NULL)
		{
			if (y == NULL)
				firstNode = bottom[thebin];
			else//�˴����ж��Ƿ�����ͬ�������Ѿ��洢�ڵײ�
				y->next = bottom[thebin];

			     y = top[thebin];//�˴��൱��һ������ָ�������β��ָ�룬�������Ӻ���Ľڵ㣬
				                   // ��Ϊ��ͬ�������Ѿ����Ӻ��˲��ҵײ��������Ѿ����µ����������ˣ�����ֻ��Ҫָ��������һ�����ӾͿ��Խ�ָ��ָ��βָ����

		}
	}

	if (y != NULL)//���Ǳ���ģ���βָ��ĵ�ַ����գ������жϴ�ӡ
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
/*void LLink::sort1()//�������򣺻�����������
{
	Link **bottom, **top;
	bottom = new Link*[10];
	top = new Link*[10];
	int i = 1;
	while (i <= 3)//3��ʾ�����ݵ����ֵ��10�ļ��η�
	{
		int a = pow(10, i);//������������ʾÿһλ���������õ���
		Link *firstnode = head;
		for (int i = 0; i <10; i++)
			bottom[i] = NULL;

		for (; firstnode != NULL; firstnode = firstnode->next)
		{
			int thebin = (firstnode->data%a) / pow(10, i-1);//ÿλ�ϵ����ֱ��ʽ��firstnode->data%10^i/10^i-1
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
	int b = 0;//���������������ݣ�Ҳ��������Ľڵ����
	int data[100];
	Link *firstnode = head;
	int max = firstnode->data;
	for (; firstnode != NULL;firstnode = firstnode->next)//����������ݵ����ֵ
	{

		data[b] = firstnode->data;//�������ֵ���������Ա�Ƚ����ֵ
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
	return i;//���ص������������㷨Ҫ���ж��ٲ�
}


void LLink::sort()//��������û����������������������
{
	Link **bottom, **top;
	bottom = new Link*[10];
	top = new Link*[10];
	int i = 1;
	int num = get_number(10);//�õ�����ѭ���Ĳ���
	while (i <= num)//num��ʾ�����ݵ����ֵ��10�ļ��η�
	{
		int a = pow(10, i);//������������ʾÿһλ���������õ���
		Link *firstnode = head;
		for (int i = 0; i <10; i++)
			bottom[i] = NULL;

		for (; firstnode != NULL; firstnode = firstnode->next)
		{
			int thebin = (firstnode->data%a) / pow(10, i - 1);//ÿλ�ϵ����ֱ��ʽ��firstnode->data%10^i/10^i-1
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











