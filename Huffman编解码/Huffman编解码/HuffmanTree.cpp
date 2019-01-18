#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

const int maxn = 105;


struct HuffmanNode {
	char data;				//字符
	float weight;			//权重
	//char *code;				//编码
	char code[10];
	int ncode;
	int lchild, rchild;
	int parent;				//父结点，为0表示根结点

	HuffmanNode(){
		lchild = rchild = parent = 0;
		//code = NULL;
		memset(code, 0, sizeof(code));
		data = ' ';
		ncode = 0;
	}
	~HuffmanNode(){
		if (code)
			delete[]code;	
	}
	void output(){
		printf("%.f\t%d\t%d\t%d\t", weight, lchild, rchild, parent);
		if (data != ' ')
			printf("%c\t%s\t%d", data, code, ncode);
		printf("\n");
	}
	bool isLeaf(){			//判断是否为叶子结点

		if (lchild == 0 && rchild == 0) return true;
		else return false;
	}
};

//Huffman树
struct HuffmanTree {
	int n;					  //编码数量
	HuffmanNode *nodes;
	char table[256];		//ASCII索引表
	HuffmanTree(int n){
		this->n = n;
		nodes = new HuffmanNode[(n << 1) ];	//左移
	}
	void create(char *charset, int weight[])
	{
		//记录字符ASCII码到编码表下表的映射关系
		for (int i = 0; i < n; i++)
			table[charset[i]] = i + 1;

		//通过填表完成建树，nodes从下标1开始
		for (int i = 1; i <= n; i++)
		{
			nodes[i].weight = weight[i - 1];
			nodes[i].lchild = 0;
			nodes[i].rchild = 0;
			nodes[i].parent = 0;
			nodes[i].data = charset[i - 1];
			//printf("%c\n", charset[i - 1]);
		}
		for (int i = n + 1; i < 2 * n; i++)
		{
			int s1, s2;
			findMinimal(i - 1, s1, s2);
			nodes[i].weight = nodes[s1].weight + nodes[s2].weight;
			nodes[i].lchild = s1;
			nodes[i].rchild = s2;
			nodes[s1].parent = nodes[s2].parent = i;

		}

		//通过遍历树完成编码表
		char code[10] = { 0 };
		fillCode(2 * n - 1, code, 0);

	}
	void fillCode(int i, char *code, int len)
	{//利用递归遍历树，同时产生编码
		HuffmanNode &node = nodes[i];

		if (node.isLeaf()) {           
			strcpy(nodes[i].code, code);//复制字符串char类型
			int w = 0;					//十进制编码整型
			int ans = 0;
			while (w < len) {
				ans *= 2;
				ans += code[w] - '0';
				w++;
			}
			nodes[i].ncode = ans;
			return;
		}

		if (node.lchild != 0)
		{
			code[len] = '0';
			len++;
			fillCode(nodes[i].lchild, code, len); //dfs
			len--;
		}

		if (node.rchild != 0)
		{
			code[len] = '1';
			len++;
			fillCode(nodes[i].rchild, code, len);
			len--;
		}
		//strcpy(&(*nodes[i].code), code);
	}

	void findMinimal(int x, int &idx1, int &idx2) //在x结点之前，找到权值最小的两个根结点
	{
		int minx = 100000;
		int vis[maxn] = { 0 };
		int pos1 = 1, pos2 = 1;
		for (int i = 1; i <= x; i++) {
		if (minx > nodes[i].weight && !nodes[i].parent) {
		minx = nodes[i].weight;
		pos1 = i;
		}
		}
		vis[pos1] = 1;
		minx = 100000;
		for (int i = 1; i <= x; i++) {
		if (minx > nodes[i].weight && !vis[i] && !nodes[i].parent) {
		minx = nodes[i].weight;
		pos2 = i;
		}
		}
		vis[pos2] = 1;

		idx1 = pos1;
		idx2 = pos2;
	
		/*	int w1, w2;
		w1 = w2 = 100000;
		for (int j = 1; j <= x; j++)
		{
			if (nodes[j].parent == 0)
			{
				if (nodes[j].weight < w1)
				{
					w2 = w1;
					idx2 = idx1;
					w1 = nodes[j].weight;
					idx1 = j;
				}

				else if (nodes[j].weight < w2)
				{
					w2 = nodes[j].weight;
					idx2 = j;
				}
			}

		}*/
	}
	void output()
	{
		printf("序号\t权重\t左结点\t右结点\t父结点\t字符\t编码\t十进制编码\t\n");
		for (int i = 1; i <= 2 * n - 1; i++)		//从根结点输出
		{
			printf("%d\t", i);
			nodes[i].output();
		}
	}
	void encode(char *src, char *dst)
	{
		//将src的字符串编码到dst当中，用01字符串保存。
		int cnt = 0;
		for (int i = 0; i < strlen(src); i++){
			char ch = src[i];
			int j = table[ch];		//查询表，得到序号
			int l = strlen(nodes[j].code);
			for (int k = 0; k < l; k++) {
				dst[cnt++] = nodes[j].code[k];
			}
		}
	}

	void decode(char *src, char *dst)
	{
		//将src的01串解码到dst中，采用变量记录当前处于树的什么位置

		char *ch = src;
		int i;
		int cnt = 0;
		while (*ch != '\0'){
			//解码一个结点每次都从树根m开始  
			i = 2 * n - 1;
			while (1) {
				if (nodes[i].isLeaf()) {
					dst[cnt++] = nodes[i].data;
					break;
				}
				if (*ch == '0')
					i = nodes[i].lchild;
				else if (*ch == '1')
					i = nodes[i].rchild;
				++ch;
			}
		}
	}
	void loadFromFile(){
		FILE *fp1;
		char text[4096] = { 0 };
		int cnt = 0;
		fp1 = fopen("F:\\text.txt", "r");	//当前目录下打开文件读
		if (fp1 == NULL) printf("No File!\n");
		else {
			char c = 0;
			while (c != EOF) {//end of file
				c = getc(fp1);
				text[cnt++] = c;
			}
		}
		fclose(fp1);
		text[cnt - 1] = '\0';
		printf("从文件中读取的字符串为：%s\n", text);

		// 将读取的字符串编码并保存到encode.huffman文件中
		char hcode[100] = { 0 };
		encode(text, hcode);
		printf("编码结果为：%s\n", hcode);

		FILE *fp2;
		fp2 = fopen("F:\\encode.huffman", "w");  
		if (fp2 == NULL) printf("No File!\n");
		else {
			for (int i = 0; i < strlen(hcode); i++)
			putc(hcode[i], fp2);
		}
		fclose(fp2);
	}


	void saveToFile(){
		FILE *fp1;
		char text[4096] = { 0 };
		int cnt = 0;
		fp1 = fopen("F:\\encode.huffman", "r");
		if (fp1 == NULL) printf("No File!\n");
		else {
			char c = 0;
			while (c != EOF) {
				c = getc(fp1);
				text[cnt++] = c;
			}
		}
		fclose(fp1);
		text[cnt - 1] = '\0';
		printf("读取的字符串为：%s\n", text);
		// 将读取的字符串解码并保存到decode.txt文件中
		char hcode[100] = { 0 };
		decode(text, hcode);
		printf("解码的结果为：%s\n", hcode);
		FILE *fp2;
		fp2 = fopen("F:\\decode.txt", "w");
		if (fp2 == NULL) printf("No File!\n");
		else {
			for (int i = 0; i < strlen(hcode); i++)
				putc(hcode[i], fp2);
		}
		fclose(fp2);
	}

};

