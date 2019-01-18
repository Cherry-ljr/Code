#include<iostream>

#include"CriticalPath.cpp"
//#include"最小生成树.cpp"
using namespace std;

int main()
{
	/*ALGraph g("ABCD");
	g.addArc(0, 2);
	g.addArc(0, 1); 
	g.addArc(2, 3); 
	g.addArc(3, 0);
	g.output();*/

	ALGraph G("123456", 1);//6个结点的无向图
	G.addArc(0, 1, 6);
	G.addArc(0, 2, 1);
	G.addArc(0, 3, 5);
	G.addArc(1, 2, 5);
	G.addArc(1, 4, 3);
	G.addArc(2, 3, 5);
	G.addArc(2, 4, 6);
	G.addArc(2, 5, 4);
	G.addArc(3, 5, 2);
	G.addArc(4, 5, 6);
	//Prim(G);
//	Krusal(G);
	criticalPath(G);
	return 0;
}