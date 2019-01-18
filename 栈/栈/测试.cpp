#include<iostream>
using namespace std;
#include"表达式求值.h"


int main()
{
	Stack<char> stack;
	stack.push('A');
	stack.push('B');
	stack.push('C');

	stack.output();//测试输出
	char t = stack.pop();//测试出栈
    cout << "栈顶元素出栈:" << t << endl;


	char q = stack.peek();//测试取栈顶元素
	cout << "观看栈顶元素:" << q << endl;
	char s = stack.pop();//测试出栈
	cout << "栈顶元素出栈:" << s << endl;
	stack.output();//测试输出

	cout << "表达式求值为："<<endl;
	cout << evaluate("3+4-2#") << endl;
	cout << evaluate("4+4*2-2#") << endl;
	cout << evaluate("8/4-2#") << endl;
	cout << evaluate("4*2+2/2#") << endl;
	cout << evaluate("2^3+2#") << endl;
	cout << evaluate("123*3+1#") << endl;

	return 0;
}
