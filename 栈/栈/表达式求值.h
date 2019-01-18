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
		if (ch >= '0'  && ch <= '9')//数字，进数字栈
		{
			
				int data ;
				data = ch - 48;	
				a[j++] = data;//若为连续数字
				//values.push(number);
		}
		else
		{
			int exp = 0;
			for (int k = j - 1; k >= 0; k--)
			{				
				a[j] += a[k] * pow(10, exp);//pow求秘
				exp++;
			}
				values.push(a[j]);//连续数字入栈

			for (int k =  0; k<j + 1; k++)
				a[k] = 0;
			   j = 0;
			  
			
			while (operators.top > 0 && compare(ch, operators.peek()) <= 0)
			{//当前运算符优先级不高于栈顶元素优先级，则栈顶元素先运算，并将结结果压栈，直到栈空或者当前运算符优先级低
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