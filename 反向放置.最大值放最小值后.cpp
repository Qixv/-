/*#include<iostream>
using namespace std;

void change(int* p, int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		int date = p[i];
		p[i] = p[n - i - 1];
		p[n - i - 1] = date;
	}
}

void maxormin(int* p, int n)
{
	int max = 0;
	int min = 0;
	for (int i = 0; i < n; i++)
	{
		if (p[i] > p[max])
			max = i;
		if (p[i] < p[min])
			min = i;
	}//ȷ��λ��

	if (max > min)
	{
		int date = p[max];
		for (int i = min + 1;i < max;i++)
		{
			p[i + 1] = p[i];//�߼��������� ʵ��û����...
		}//��С�����֮��������������һλ
		p[min + 1] = date;
	}
	if (max < min)
	{

		int date = p[max];
		for (int i = max;i < min;i++)
		{
			p[i] = p[i + 1];
		}//������С����С�����֮�����������ǰ��һλ
		p[min] = date;
	}
}


int main()
{
	int a[9] = { 1,2,3,4,5,6,7,8,9 };
	int alength = sizeof(a) / sizeof(int);
	change(a, alength);
	for (int i = 0; i < 9; i++)
	{
		cout << a[i] << " ";
	}

	cout << ' ' << endl;

	int b[9] = { 4,6,5,1,6,4,15,7,14 };
	int blength = sizeof(b) / sizeof(int);
	maxormin(b, blength);
	for (int i = 0; i < 9; i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}*/