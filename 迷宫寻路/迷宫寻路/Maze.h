#include <iostream>
using namespace std;
#include "����.h"

struct Point{
	int x, y;
	Point(){ x = 0; y = 0; }
	Point(int x1, int y1){ x = x1; y = y1; }
	void output()//ʵ�������ӡ
	{
		cout <<"("<< x<< "," << y<<")";
	}
	Point move(Point vector)
	{
		return Point(x + vector.x, y + vector.y);
	}

};

#define N 10
#define M 4

char map[N][N + 1] = { "**********", 
                       "*  *   * *",
					   "*  *   * *", 
					   "*    **  *", 
					   "* ***    *", 
					   "*   * *  *", 
					   "* *   *  *", 
					   "* *** ** *", 
					   "**       *", 
					   "**********",};
Point direction[M] = { Point{ -1, 0 }, Point{ 1, 0 }, Point{ 0, -1 }, Point{ 0, 1 } };

Point previous[N][N];
void printPath(Point c,Point src)//��c���ˣ�ֱ������A��ֹ����ӡ·������
{
	while (c.y != src.y||c.x != src.x)
	{
		c.output();
		c = previous[c.y][c.x];
	}
	c.output();
	cout << endl;
}

void findPath(Point src, Point dst)
{
	map[src.y][src.x] = 'A';//��ǳ�����
	map[dst.y][dst.x] = 'B';//���Ŀ���
	Queue<Point> Q;
	Q.enqueue(src);
	while (Q.isEmpty() == false)
	{
		Point pt = Q.dequeue();//ȡ�㴦��
		for (int i = 0; i<M; i++)//����M����ͨ����
		{
			Point c = pt.move(direction[i]);
			char ch = map[c.y][c.x];
			if (ch == ' ')
			{
				previous[c.y][c.x] = pt;
				map[c.y][c.x] = '*';
				Q.enqueue(c);
			}
			if (ch == 'B')
			{
				previous[c.y][c.x] = pt;
				cout << "�ҵ���������·���ǣ�"<<endl;
				printPath(c, src);
				return;
			}			
			
		}	
		
	}
	cout << "��A�㵽B�㲻����ͨ��û��·��" << endl;
	
}









