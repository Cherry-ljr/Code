
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

#define Max_VERTEX_NUM 10

template<typename Elemtype>
struct Stack
{
	Elemtype *items;
	int capacity;
	int top;
	Stack(int c = 10)
	{
		top = 0;
		capacity = c;
		items = new Elemtype[capacity];//申请栈空间
	}
	~Stack(){}
	void output()//打印输出
	{
		for (int i = 0; i < top; i++)
			cout << items[i] << " ";
		cout << endl;
	}
	void push(Elemtype e)
	{
		items[top++] = e;
	}
	Elemtype peek()//取栈顶元素，但不出栈
	{
		int i = top;
		return items[i - 1];
	}
	Elemtype pop()//栈顶元素出栈
	{
		Elemtype e = items[--top];
		return e;
	}

};

//弧结点
struct ArcNode
{
	int adjvex;
	ArcNode *nextarc;
	int info;//弧自带信息
	ArcNode(int adj, int w){
		adjvex = adj;
		info = w;
		nextarc = NULL;
	}
	void output(){
		printf("->(adj=%d,w=%d)", adjvex, info);
	}

};

//顶点结点
struct VexNode{
	char data;//顶点自带信息
	ArcNode *firstarc;
	VexNode(){
		firstarc = NULL;
	}
	~VexNode()
	{
		ArcNode *q, *p = firstarc;
		while (p)
		{
			q = p->nextarc;
			delete(p);
			p = q;
		}

	}
	void output()
	{
		printf("顶点%c", data);
		ArcNode *p = firstarc;
		while (p)
		{
			p->output();
			p = p->nextarc;
		}
		printf("\n");
	}
	void addArc(int adj, int w)
	{//向顶点添加弧
		ArcNode *p = new ArcNode(adj, w);
		p->nextarc = firstarc;
		firstarc = p;
	}
};
struct ALGraph{
	VexNode *vertices;
	int vexnum;//顶点数量
	int kind;//图的种类，0-无向图，1-有向图
	ALGraph(char *names, int k = 1)
	{
		kind = k;
		vexnum = strlen(names);
		vertices = new VexNode[vexnum];
		for (int i = 0; i < vexnum; i++)
			vertices[i].data = names[i];

	}
	~ALGraph()
	{
		//析构函数释放结点
		delete[]vertices;

	}

	void output()
	{
		//输出图
		for (int i = 0; i < vexnum; i++)
			vertices[i].output();
	}
	void addArc(int tail, int head, int w = 0)
	{
		//向图添加弧
		vertices[tail].addArc(head, w);
		if (kind == 0)//无向图
			vertices[head].addArc(tail, w);
	}

};

ArcNode *q, *p;
#define MAX_VERTEX_NUM 10

void findInDegree(ALGraph &G, int *in)
{//初始化indegree数组

	for (int i = 0; i < G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;
		while (p)
		{
			in[p->adjvex]++;
			q = p->nextarc;
			p = q;

		}
	}

}
int vl[MAX_VERTEX_NUM];//事件最晚开始的时间
int ve[MAX_VERTEX_NUM];//事件最早开始的时间
int indegree[Max_VERTEX_NUM];

void topSort(ALGraph &G, Stack<int> &T) {
	int count = 0;//计数
	int i, k = 0;
	//ArcNode *p;
	Stack<int> S;  //0入度栈
	findInDegree(G, indegree);
	for (i = 0; i < G.vexnum; i++) {
		ve[i] = 0;
		if (indegree[i] == 0)
		{
			S.push(i);
		}
		// S.output();
	}

	while (S.top != 0) {//判断为空，用top指针是否为0。
		int j = S.peek();
		S.pop();
		//cout << j;
		T.push(j);
		count++;

		for (p = G.vertices[j].firstarc; p; p = p->nextarc) {
			k = p->adjvex;
			if (--indegree[k] == 0) {
				S.push(k);//入度减为0则入0度栈

			}
			if (ve[j] + (p->info) > ve[k]) {
				ve[k] = ve[j] + (p->info);
			}

		}
	}
	//cout << count;
	cout << "拓扑排序结果：";
	T.output();
	if (count < G.vexnum) {
		cout << "错误,有回路";
	}
	else{
		cout << "成功" << endl;
	}
}
void criticalPath(ALGraph &G) {
	Stack<int> T;
	int i, j, k = 0, dut = 0, ee = 0, el = 0;//dut权值ee最早el最晚减去权重
	char tag = 0;
	topSort(G, T);
	for (i = 0; i < G.vexnum; i++)//最迟,初始化顶点事件最迟发生时间
		vl[i] = ve[G.vexnum - 1];
	while (T.top != 0) {
		j = T.pop();
		for (j, p = G.vertices[j].firstarc; p; p = p->nextarc) {
			k = p->adjvex;
			dut = p->info;
			if (vl[k] - dut < vl[j])
				vl[j] = vl[k] - dut;
		}
	}
	for (j = 0; j < G.vexnum; j++)
	for (p = G.vertices[j].firstarc; p; p = p->nextarc) {
		k = p->adjvex;
		dut = p->info;
		ee = ve[j];
		el = vl[k] - dut;
		tag = (ee == el) ? '*' : ' ';
		cout << "<" << j + 1 << "," << k + 1 << ">" << "=" << dut << " " << ee << " " << el << " " << tag << endl;
	}


}

int main()
{
	ALGraph G("123456", 1);//6个结点的无向图
	G.addArc(0, 1, 3);
	G.addArc(0, 2, 2);
	G.addArc(1, 3, 2);
	G.addArc(1, 4, 3);
	G.addArc(2, 3, 4);
	G.addArc(2, 5, 3);
	G.addArc(3, 5, 2);
	G.addArc(4, 5, 1);

	criticalPath(G);
	return 0;
}
