
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
		items = new Elemtype[capacity];//����ջ�ռ�
	}
	~Stack(){}
	void output()//��ӡ���
	{
		for (int i = 0; i < top; i++)
			cout << items[i] << " ";
		cout << endl;
	}
	void push(Elemtype e)
	{
		items[top++] = e;
	}
	Elemtype peek()//ȡջ��Ԫ�أ�������ջ
	{
		int i = top;
		return items[i - 1];
	}
	Elemtype pop()//ջ��Ԫ�س�ջ
	{
		Elemtype e = items[--top];
		return e;
	}

};

//�����
struct ArcNode
{
	int adjvex;
	ArcNode *nextarc;
	int info;//���Դ���Ϣ
	ArcNode(int adj, int w){
		adjvex = adj;
		info = w;
		nextarc = NULL;
	}
	void output(){
		printf("->(adj=%d,w=%d)", adjvex, info);
	}

};

//������
struct VexNode{
	char data;//�����Դ���Ϣ
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
		printf("����%c", data);
		ArcNode *p = firstarc;
		while (p)
		{
			p->output();
			p = p->nextarc;
		}
		printf("\n");
	}
	void addArc(int adj, int w)
	{//�򶥵���ӻ�
		ArcNode *p = new ArcNode(adj, w);
		p->nextarc = firstarc;
		firstarc = p;
	}
};
struct ALGraph{
	VexNode *vertices;
	int vexnum;//��������
	int kind;//ͼ�����࣬0-����ͼ��1-����ͼ
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
		//���������ͷŽ��
		delete[]vertices;

	}

	void output()
	{
		//���ͼ
		for (int i = 0; i < vexnum; i++)
			vertices[i].output();
	}
	void addArc(int tail, int head, int w = 0)
	{
		//��ͼ��ӻ�
		vertices[tail].addArc(head, w);
		if (kind == 0)//����ͼ
			vertices[head].addArc(tail, w);
	}

};

ArcNode *q, *p;
#define MAX_VERTEX_NUM 10

void findInDegree(ALGraph &G, int *in)
{//��ʼ��indegree����

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
int vl[MAX_VERTEX_NUM];//�¼�����ʼ��ʱ��
int ve[MAX_VERTEX_NUM];//�¼����翪ʼ��ʱ��
int indegree[Max_VERTEX_NUM];

void topSort(ALGraph &G, Stack<int> &T) {
	int count = 0;//����
	int i, k = 0;
	//ArcNode *p;
	Stack<int> S;  //0���ջ
	findInDegree(G, indegree);
	for (i = 0; i < G.vexnum; i++) {
		ve[i] = 0;
		if (indegree[i] == 0)
		{
			S.push(i);
		}
		// S.output();
	}

	while (S.top != 0) {//�ж�Ϊ�գ���topָ���Ƿ�Ϊ0��
		int j = S.peek();
		S.pop();
		//cout << j;
		T.push(j);
		count++;

		for (p = G.vertices[j].firstarc; p; p = p->nextarc) {
			k = p->adjvex;
			if (--indegree[k] == 0) {
				S.push(k);//��ȼ�Ϊ0����0��ջ

			}
			if (ve[j] + (p->info) > ve[k]) {
				ve[k] = ve[j] + (p->info);
			}

		}
	}
	//cout << count;
	cout << "������������";
	T.output();
	if (count < G.vexnum) {
		cout << "����,�л�·";
	}
	else{
		cout << "�ɹ�" << endl;
	}
}
void criticalPath(ALGraph &G) {
	Stack<int> T;
	int i, j, k = 0, dut = 0, ee = 0, el = 0;//dutȨֵee����el�����ȥȨ��
	char tag = 0;
	topSort(G, T);
	for (i = 0; i < G.vexnum; i++)//���,��ʼ�������¼���ٷ���ʱ��
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
	ALGraph G("123456", 1);//6����������ͼ
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
