#include<iostream>
using namespace std;
#include"���ʽ��ֵ.h"


int main()
{
	Stack<char> stack;
	stack.push('A');
	stack.push('B');
	stack.push('C');

	stack.output();//�������
	char t = stack.pop();//���Գ�ջ
    cout << "ջ��Ԫ�س�ջ:" << t << endl;


	char q = stack.peek();//����ȡջ��Ԫ��
	cout << "�ۿ�ջ��Ԫ��:" << q << endl;
	char s = stack.pop();//���Գ�ջ
	cout << "ջ��Ԫ�س�ջ:" << s << endl;
	stack.output();//�������

	cout << "���ʽ��ֵΪ��"<<endl;
	cout << evaluate("3+4-2#") << endl;
	cout << evaluate("4+4*2-2#") << endl;
	cout << evaluate("8/4-2#") << endl;
	cout << evaluate("4*2+2/2#") << endl;
	cout << evaluate("2^3+2#") << endl;
	cout << evaluate("123*3+1#") << endl;

	return 0;
}
