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

		cout << "����:" << Q.dequeue() << endl;
		cout << "����:" << Q.dequeue() << endl;	
		Q.output();

		Q.enqueue('E');
		Q.enqueue('F');
		Q.output();
		Q.enqueue('G');//���Գ���5��Ԫ�أ�����ѭ�������Ƿ���������	
		Q.enqueue('H');
	}
	catch (char *message)
	{
		cout << "�쳣��ϢΪ��" << message << endl;
	}

	findPath(Point(1, 1), Point(8, 8));
	return 0;
}