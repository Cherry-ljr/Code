#include <iostream>
using namespace std;

#include"Maze.h"

int main()
{
	try{
		Queue<char> Q(5);
		Q.enqueue('A');
		Q.enqueue('B');
		Q.enqueue('C');
		Q.enqueue('D');
		Q.output();

		cout << "出队:" << Q.dequeue() << endl;
		cout << "出队:" << Q.dequeue() << endl;	
		Q.output();

		Q.enqueue('E');
		Q.enqueue('F');
		Q.output();
		Q.enqueue('G');//测试超过5个元素，测试循环功能是否正常工作	
		Q.enqueue('H');
	}
	catch (char *message)
	{
		cout << "异常信息为：" << message << endl;
	}

	findPath(Point(1, 1), Point(8, 8));
	return 0;
}