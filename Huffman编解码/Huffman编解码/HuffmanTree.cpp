#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

const int maxn = 105;


struct HuffmanNode {
	char data;				//�ַ�
	float weight;			//Ȩ��
	//char *code;				//����
	char code[10];
	int ncode;
	int lchild, rchild;
	int parent;				//����㣬Ϊ0��ʾ�����

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
	bool isLeaf(){			//�ж��Ƿ�ΪҶ�ӽ��

		if (lchild == 0 && rchild == 0) return true;
		else return false;
	}
};

//Huffman��
struct HuffmanTree {
	int n;					  //��������
	HuffmanNode *nodes;
	char table[256];		//ASCII������
	HuffmanTree(int n){
		this->n = n;
		nodes = new HuffmanNode[(n << 1) ];	//����
	}
	void create(char *charset, int weight[])
	{
		//��¼�ַ�ASCII�뵽������±��ӳ���ϵ
		for (int i = 0; i < n; i++)
			table[charset[i]] = i + 1;

		//ͨ�������ɽ�����nodes���±�1��ʼ
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

		//ͨ����������ɱ����
		char code[10] = { 0 };
		fillCode(2 * n - 1, code, 0);

	}
	void fillCode(int i, char *code, int len)
	{//���õݹ��������ͬʱ��������
		HuffmanNode &node = nodes[i];

		if (node.isLeaf()) {           
			strcpy(nodes[i].code, code);//�����ַ���char����
			int w = 0;					//ʮ���Ʊ�������
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

	void findMinimal(int x, int &idx1, int &idx2) //��x���֮ǰ���ҵ�Ȩֵ��С�����������
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
		printf("���\tȨ��\t����\t�ҽ��\t�����\t�ַ�\t����\tʮ���Ʊ���\t\n");
		for (int i = 1; i <= 2 * n - 1; i++)		//�Ӹ�������
		{
			printf("%d\t", i);
			nodes[i].output();
		}
	}
	void encode(char *src, char *dst)
	{
		//��src���ַ������뵽dst���У���01�ַ������档
		int cnt = 0;
		for (int i = 0; i < strlen(src); i++){
			char ch = src[i];
			int j = table[ch];		//��ѯ���õ����
			int l = strlen(nodes[j].code);
			for (int k = 0; k < l; k++) {
				dst[cnt++] = nodes[j].code[k];
			}
		}
	}

	void decode(char *src, char *dst)
	{
		//��src��01�����뵽dst�У����ñ�����¼��ǰ��������ʲôλ��

		char *ch = src;
		int i;
		int cnt = 0;
		while (*ch != '\0'){
			//����һ�����ÿ�ζ�������m��ʼ  
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
		fp1 = fopen("F:\\text.txt", "r");	//��ǰĿ¼�´��ļ���
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
		printf("���ļ��ж�ȡ���ַ���Ϊ��%s\n", text);

		// ����ȡ���ַ������벢���浽encode.huffman�ļ���
		char hcode[100] = { 0 };
		encode(text, hcode);
		printf("������Ϊ��%s\n", hcode);

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
		printf("��ȡ���ַ���Ϊ��%s\n", text);
		// ����ȡ���ַ������벢���浽decode.txt�ļ���
		char hcode[100] = { 0 };
		decode(text, hcode);
		printf("����Ľ��Ϊ��%s\n", hcode);
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

