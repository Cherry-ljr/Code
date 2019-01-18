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
			throw"队已满，无法再入队";

		else {
			items[tail] = e;
			tail = (tail + 1) % capacity;
			length++;

		}
	}
	ElemType dequeue()
	{
		if (length == 0)
			throw"队已空，无法再出队";
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
		cout << "队列当前的元素有：";
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

