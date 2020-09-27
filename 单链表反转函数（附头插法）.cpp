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
		cout << "�������ݣ�" << endl;
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
	//�������� ����ͷ�巨
	/*
	LinkList p;
	head->link = NULL;
	for (int i = 0;i < n;i++)
	{
		p= (LinkList)malloc(sizeof(LNode));
		cout << "�������ݣ�"<<endl;
		cin >> p->date;
		p->link = head->link;
		head->link = p;
	}*/
}

// ʵ�ֵ�����ת����
void reverse(LinkList &head)
{
	//�жϵ�����head�Ƿ�Ϊ�ջ��ߵ�������ֻ��һ��Ԫ�� ���������ֱ�ӽ���
	if (head->link == NULL || head->link->link == NULL)
	{
		return;
	}
	LinkList date = NULL;
	LinkList p = head->link;
	LinkList q = head->link->link;

	//���з�ת���� 
	while (q != NULL)
	{
		date = q->link;
		q->link = p;
		p = q;
		q = date;
	}
	//����ͷ�ڵ�
	head->link->link = NULL;//��������β 
	head->link = p;//��������ͷ 
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
	cout<<"ƽ������"<<((double)sum/i)*1.0<<endl;
}

int main() {
	LinkList head;
	head = (LinkList)malloc(sizeof(LNode));
	int n;
	cout << "����n:";
	cin >> n;
	headlist(head, n);
	cout<<"ԭ���ݣ�"<<endl;
	show(head);

	cout<<"���ã�"<<endl;
	reverse(head);
	show(head);

	cout<<"ƽ��ֵ��"<<endl;
	average(head);
	return 0;
}