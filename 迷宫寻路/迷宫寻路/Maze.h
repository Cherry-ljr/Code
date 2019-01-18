#include <iostream>
using namespace std;
#include "队列.h"

struct Point{
	int x, y;
	Point(){ x = 0; y = 0; }
	Point(int x1, int y1){ x = x1; y = y1; }
	void output()//实现坐标打印
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
void printPath(Point c,Point src)//从c回退，直到碰到A终止，打印路径坐标
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
	map[src.y][src.x] = 'A';//标记出发点
	map[dst.y][dst.x] = 'B';//标记目标点
	Queue<Point> Q;
	Q.enqueue(src);
	while (Q.isEmpty() == false)
	{
		Point pt = Q.dequeue();//取点处理
		for (int i = 0; i<M; i++)//遍历M个联通方向
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
				cout << "找到出口啦，路径是："<<endl;
				printPath(c, src);
				return;
			}			
			
		}	
		
	}
	cout << "从A点到B点不能联通，没有路径" << endl;
	
}









