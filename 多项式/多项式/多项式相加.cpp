#include <iostream>
using namespace std;
#include "����.h"
struct Monomial             //���쵥��ʽ 
{
	double coef;
	int exp;
	Monomial(){}
	Monomial(double c, int e)
	{
		coef = c; exp = e;
	}
	void output()//��ӡ����ʽ
	{
		if (coef < 0 ) cout << "(" << coef << ")";
		else
			cout << coef;		 
		   if (exp) cout << "^" << exp;		
	}
};
struct Polynomial :public LinkList<Monomial>
{
	void output()//�������ʽ
	{
		Node *p = header.next;
		while (p)
		{			
			p->data.output();			
			p = p->next;			
			if(p) cout << "->";
		}
		cout << endl;
		cout << endl;
		
	}
	Polynomial operator+(Polynomial &other)//����ʵ�ֶ���ʽ�ӷ�
	{
		Polynomial *result = new Polynomial();
		Node *p = header.next;
		Node *q = other.header.next;
		Node *t = &result->header;
		while (p&&q)//A��B������δ����ʱ
		{
			if (p->data.exp < q->data.exp)//p��ָ��С
			{
				Node *x = new Node();
				t->next = x;
				x->data = p->data;
				p = p->next;
				t = t->next;
			}
			else if (p->data.exp > q->data.exp)//q��ָ��С
			{
				Node *x = new Node();
				t->next = x;
				x->data = q->data;
				q = q->next;
				t = t->next;
			}
			else{ //p,qָ�����
				if ((p->data.coef + q->data.coef) == 0)
				{
					p = p->next; q = q->next;
				}
				else 
				{
					Node *x = new Node();
					t->next = x;
					x->data.coef = p->data.coef + q->data.coef;
					x->data.exp = p->data.exp;
					p = p->next;
					q = q->next;
					t = t->next;
				}
			}
		}
		while (p){ t->next = p; p=p->next;t= t->next; }
		while (q){ t->next = q; q=q->next;t= t->next; }

		return *result;
	}
	Polynomial operator-(Polynomial &other)//����ʵ�ֶ���ʽ����
	
	{
		Polynomial *result = new Polynomial();
		Node *p = header.next;
		Node *q = other.header.next;
		Node *t = &result->header;
		while (p&&q)//A��B������δ����ʱ
		{
			if (p->data.exp < q->data.exp)//p��ָ��С
			{
				Node *x = new Node();
				t->next = x;
				x->data= p->data;
				p = p->next;
				t = t->next;
			}
			else if (p->data.exp > q->data.exp)//q��ָ��С
			{
				Node *x = new Node();
				t->next = x;
				x->data.coef = -(q->data.coef);
				x->data.exp = q->data.exp;
				q = q->next;
				t = t->next;
			}
			else{ //p,qָ�����
				if ((p->data.coef - q->data.coef) == 0)
				{
					p = p->next; q = q->next;
				}
				else
				{
					Node *x = new Node();
					t->next = x;
					x->data.coef = p->data.coef - q->data.coef;
					x->data.exp = p->data.exp;
					p = p->next;
					q = q->next;
					t = t->next;
				}
			}
		}
		while (p){ t->next = p; p = p->next; t = t->next; }
		while (q){ t->next = q; q = q->next; t = t->next; }

		return *result;
	}
};
