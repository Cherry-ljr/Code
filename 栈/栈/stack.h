
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
		items = new Elemtype[capacity];//申请栈空间
	}
	~Stack(){}
	void output()//打印输出
	{
		for (int i = 0; i < top; i++)
			cout << items[i] << " ";
		cout << endl;
	}
	void push(Elemtype e)
	{
		items[top++] = e;
	}
	Elemtype peek()//取栈顶元素，但不出栈
	{
		int i = top;
		return items[i-1];
	}
	Elemtype pop()//栈顶元素出栈
	{
		Elemtype e = items[--top];		
		return e;
	}

};


