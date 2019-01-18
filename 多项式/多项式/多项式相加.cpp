#include <iostream>
using namespace std;
#include "链表.h"
struct Monomial             //构造单项式 
{
	double coef;
	int exp;
	Monomial(){}
	Monomial(double c, int e)
	{
		coef = c; exp = e;
	}
	void output()//打印单项式
	{
		if (coef < 0 ) cout << "(" << coef << ")";
		else
			cout << coef;		 
		   if (exp) cout << "^" << exp;		
	}
};
struct Polynomial :public LinkList<Monomial>
{
	void output()//输出多项式
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
	Polynomial operator+(Polynomial &other)//重载实现多项式加法
	{
		Polynomial *result = new Polynomial();
		Node *p = header.next;
		Node *q = other.header.next;
		Node *t = &result->header;
		while (p&&q)//A与B都有项未处理时
		{
			if (p->data.exp < q->data.exp)//p的指数小
			{
				Node *x = new Node();
				t->next = x;
				x->data = p->data;
				p = p->next;
				t = t->next;
			}
			else if (p->data.exp > q->data.exp)//q的指数小
			{
				Node *x = new Node();
				t->next = x;
				x->data = q->data;
				q = q->next;
				t = t->next;
			}
			else{ //p,q指数相等
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
	Polynomial operator-(Polynomial &other)//重载实现多项式减法
	
	{
		Polynomial *result = new Polynomial();
		Node *p = header.next;
		Node *q = other.header.next;
		Node *t = &result->header;
		while (p&&q)//A与B都有项未处理时
		{
			if (p->data.exp < q->data.exp)//p的指数小
			{
				Node *x = new Node();
				t->next = x;
				x->data= p->data;
				p = p->next;
				t = t->next;
			}
			else if (p->data.exp > q->data.exp)//q的指数小
			{
				Node *x = new Node();
				t->next = x;
				x->data.coef = -(q->data.coef);
				x->data.exp = q->data.exp;
				q = q->next;
				t = t->next;
			}
			else{ //p,q指数相等
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
