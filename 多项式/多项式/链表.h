#include <iostream>
using namespace std;

template <typename ElemType>
struct Node
{
	ElemType data; //����Ԫ��
	Node *next = NULL;//���ָ��
	Node(){}
	Node(ElemType d)
	{data = d;}
	void release()
	{//�õݹ�ķ����򵥱���ͷ�next��ָ���
		if (next)
		{
			next->release();//�ݹ����
			delete next;
		}
		else delete next;
	}
};
//������
template <typename ElemType>

struct LinkList{
	typedef Node<ElemType> Node;
	Node header;
	int length = 0;
	~LinkList(){}
	void insert(ElemType e){//����Ԫ��e������ͷ��
		Node *p = new Node();
		p->data = e;
		p->next = header.next;
		header.next = p;
		length++;
	}
	Node &get(int index){//��ȡindexλ�õ�Ԫ��
		Node *p = header.next;
		while (p != NULL&&index > 0)
		{
			p = p->next;
			index--;
		}
		return p;
	}
	void set(int index, ElemType value){//�޸�indexλ�õ�Ԫ��
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
	Node *find(ElemType e)//���ҽ��
	{
		Node *p = header.next;
		while (p){
			if (p->data == e)break;
			p = p->next;
		}
		return p;
	}
	void deleteAfter(Node *p)//ɾ��P֮���һ�����
	{
		if (p == NULL)return;
		Node *q = p->next;
		if (q == NULL)return;
		p->next = q->next;
		delete q;
		length--;
	}
	void deleteAll(ElemType e)//ɾ������ֵΪe�Ľ��
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
	{LinkList<int>list;//��������
	list.insert(7);
	list.insert(6);
	list.insert(5);
	list.set(1,5);
	list.deleteAll(5);
	list.output();//�������

	typedef Node<int>Node;
	Node *p = list.find(6);
	list.deleteAfter(p);
	list.output();
	p = list.find(8);//���Ҳ����ڵĽ��
	list.deleteAfter(p);
	list.output();
	return 0;}















