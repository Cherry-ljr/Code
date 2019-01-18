#include<iostream>
using namespace std;

template <typename ElemType>
struct Queue
{
	ElemType *items;
	int capacity;
	int head, tail;
	int length;
	Queue(int c = 10)
	{
		head = tail = 0;
		length = 0;
		capacity = c;
		items = new ElemType[capacity];
	}
	~Queue()
	{
		delete[] items;
	}

	void enqueue(ElemType e)
	{

		if (length == capacity)
			throw"���������޷������";

		else {
			items[tail] = e;
			tail = (tail + 1) % capacity;
			length++;

		}
	}
	ElemType dequeue()
	{
		if (length == 0)
			throw"���ѿգ��޷��ٳ���";
		else{
			ElemType e = items[head];
			head = (head + 1) % capacity;
			length--;
			return e;
		}
	}
	void output()
	{
		int i;
		cout << "���е�ǰ��Ԫ���У�";
		for (i = head; tail != i; i = (i + 1) % capacity)
		{
			cout << items[i];
		}
		cout << endl;
	}
	bool isEmpty()
	{
		if (length == 0)	return  true;
		else return false;
	}
};

