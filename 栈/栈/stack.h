
#include<iostream>
using namespace std;

template<typename Elemtype>
struct Stack
{
	Elemtype *items;
	int capacity;
	int top;
	Stack(int c = 10)
	{
		top = 0;
		capacity = c;
		items = new Elemtype[capacity];//����ջ�ռ�
	}
	~Stack(){}
	void output()//��ӡ���
	{
		for (int i = 0; i < top; i++)
			cout << items[i] << " ";
		cout << endl;
	}
	void push(Elemtype e)
	{
		items[top++] = e;
	}
	Elemtype peek()//ȡջ��Ԫ�أ�������ջ
	{
		int i = top;
		return items[i-1];
	}
	Elemtype pop()//ջ��Ԫ�س�ջ
	{
		Elemtype e = items[--top];		
		return e;
	}

};


