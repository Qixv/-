#include<iostream>
#include<cstdlib>
using namespace std;

typedef int ElemType;
typedef struct LNode 
{
	ElemType date;
    LNode * link;
}LNode, *LinkList;

void headlist(LinkList &head, int &n)
{
	LinkList p,r=NULL;
	head->link = NULL;
	for (int i = 0;i < n;i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		cout << "输入数据：" << endl;
		cin >> p->date;
		p->link=NULL;
		if (head->link == NULL)
		{
			head->link = p;
		}
		else
		{
			r->link = p;
		}
		r = p;
	}
	//以上正常 以下头插法
	/*
	LinkList p;
	head->link = NULL;
	for (int i = 0;i < n;i++)
	{
		p= (LinkList)malloc(sizeof(LNode));
		cout << "输入数据："<<endl;
		cin >> p->date;
		p->link = head->link;
		head->link = p;
	}*/
}

// 实现单链表反转函数
void reverse(LinkList &head)
{
	//判断单链表head是否为空或者单链表中只有一个元素 ，如果是则直接结束
	if (head->link == NULL || head->link->link == NULL)
	{
		return;
	}
	LinkList date = NULL;
	LinkList p = head->link;
	LinkList q = head->link->link;

	//进行反转操作 
	while (q != NULL)
	{
		date = q->link;
		q->link = p;
		p = q;
		q = date;
	}
	//调整头节点
	head->link->link = NULL;//设置链表尾 
	head->link = p;//设置链表头 
}

void show(LinkList head)
{
	LinkList p;
	p = head->link;
	while (p != NULL)
	{
		cout << "date:" << p->date << endl;
		p = p->link;
	}
	cout<<' '<<endl;
}

void average(LinkList &head)
{
	LinkList p;
	p = head->link;
	int sum=0;
	int i = 0;
	while (p != NULL)
	{
		sum = sum + p->date;
		p = p->link;
		i++;
	}
	cout<<"平均数："<<((double)sum/i)*1.0<<endl;
}

int main() {
	LinkList head;
	head = (LinkList)malloc(sizeof(LNode));
	int n;
	cout << "输入n:";
	cin >> n;
	headlist(head, n);
	cout<<"原数据："<<endl;
	show(head);

	cout<<"逆置："<<endl;
	reverse(head);
	show(head);

	cout<<"平均值："<<endl;
	average(head);
	return 0;
}