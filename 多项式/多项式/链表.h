#include <iostream>
using namespace std;

template <typename ElemType>
struct Node
{
	ElemType data; //数据元素
	Node *next = NULL;//结点指针
	Node(){}
	Node(ElemType d)
	{data = d;}
	void release()
	{//用递归的方法简单表达释放next所指后继
		if (next)
		{
			next->release();//递归调用
			delete next;
		}
		else delete next;
	}
};
//链表类
template <typename ElemType>

struct LinkList{
	typedef Node<ElemType> Node;
	Node header;
	int length = 0;
	~LinkList(){}
	void insert(ElemType e){//插入元素e到链表头部
		Node *p = new Node();
		p->data = e;
		p->next = header.next;
		header.next = p;
		length++;
	}
	Node &get(int index){//获取index位置的元素
		Node *p = header.next;
		while (p != NULL&&index > 0)
		{
			p = p->next;
			index--;
		}
		return p;
	}
	void set(int index, ElemType value){//修改index位置的元素
		Node *p = header.next;
		while (p != NULL&&index > 0)
		{
			p = p->next;
			index--;
		}
		p->data = value;
	}
	void output()
	{
		Node *p = header.next;
		cout << "header->";
		while (p){
			cout << p->data << "->";
			p = p->next;
		}
		cout << "^"<<endl;
	}
	Node *find(ElemType e)//查找结点
	{
		Node *p = header.next;
		while (p){
			if (p->data == e)break;
			p = p->next;
		}
		return p;
	}
	void deleteAfter(Node *p)//删除P之后的一个结点
	{
		if (p == NULL)return;
		Node *q = p->next;
		if (q == NULL)return;
		p->next = q->next;
		delete q;
		length--;
	}
	void deleteAll(ElemType e)//删除所有值为e的结点
	{
		Node *p = header.next;
		Node *q=new Node();
		while (p){
			if (p->data == e && q == header.next)
			{
				header.next = p->next;
			
			}
			if (p->data == e)
				q->next = p->next;
			p = q;
		    p = p->next;
		}
	}

};

int main()
	{LinkList<int>list;//构造链表
	list.insert(7);
	list.insert(6);
	list.insert(5);
	list.set(1,5);
	list.deleteAll(5);
	list.output();//测试输出

	typedef Node<int>Node;
	Node *p = list.find(6);
	list.deleteAfter(p);
	list.output();
	p = list.find(8);//查找不存在的结点
	list.deleteAfter(p);
	list.output();
	return 0;}















