#include<iostream>
using namespace std;
#include"stack.h"
#include"math.h"

int getPriority(char opt)
{
	switch(opt)
	{
	case '#':return 0; break;
	case '+':return 1; break;
	case '-':return 1; break;
	case '*':return 2; break;
	case '/':return 2; break;
	case '^':return 3; break;
	default:break;
	}

}
int compare(char optA, char optB)
{
	return getPriority(optA) - getPriority(optB);
}
double Squ(double v1,int v2)

{
	int sum = 1;
	for (int i = 0; i < v2; i++)
	  sum = sum*v1;
    return sum;
}
double caculate(double v1, double v2, char opt)
{
	
	switch (opt)
	{
	case '+':return v1+v2; break;
	case '-':return v1-v2; break;
	case '*':return v1*v2; break;
	case '/':return v1/v2; break;
	case '^':return Squ(v1, v2); break;	
	default: break;
	}
	
}
double evaluate(char *expression)
{
	Stack<double>values;
	Stack<char>operators;
	int i = 0;
	int j = 0;
	int a[5] = {0};
	char ch;
	while ((ch = expression[i]) != '\0')
	{
		i++;
		if (ch >= '0'  && ch <= '9')//���֣�������ջ
		{
			
				int data ;
				data = ch - 48;	
				a[j++] = data;//��Ϊ��������
				//values.push(number);
		}
		else
		{
			int exp = 0;
			for (int k = j - 1; k >= 0; k--)
			{				
				a[j] += a[k] * pow(10, exp);//pow����
				exp++;
			}
				values.push(a[j]);//����������ջ

			for (int k =  0; k<j + 1; k++)
				a[k] = 0;
			   j = 0;
			  
			
			while (operators.top > 0 && compare(ch, operators.peek()) <= 0)
			{//��ǰ��������ȼ�������ջ��Ԫ�����ȼ�����ջ��Ԫ�������㣬��������ѹջ��ֱ��ջ�ջ��ߵ�ǰ��������ȼ���
				double v1 = values.pop();
				double v2 = values.pop();
				char opt = operators.pop();
				double v3 = caculate(v2, v1, opt);
				values.push(v3);
			}			
			operators.push(ch);

		}
	} 
	return values.pop();

}