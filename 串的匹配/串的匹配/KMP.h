#include<iostream>
using namespace std;
//#include<time.h>
#include<windows.h>


int Next[20];//Next[j]��ʾT[j]ǰ���ǰ��׺��ȵĳ���

int Index(char *S, char *T, int pos){
	//��pos��ʼ����T������T������ֵ�λ�ã��������ڣ�����-1
	int n = strlen(S), m = strlen(T);
	int i = pos, j = 0;
	while (i < n &&j < m)
	{
		if (S[i] == T[j]){ i++; j++; }
		else { i = i - j + 1; j = 0; }
	}
	if (j == m) return i - m + 1;
	return -1;
}

int Index_KMP(char *s, char *t, int pos)//ʵ��KMP�㷨
{
	int i = pos, j = 0;
	int n = strlen(s);
	int m = strlen(t);
	while (i <= n&&j <= m){
		if (j == 0 || s[i] == t[j]){ i++; j++; }
		else j = Next[j];
	}
	if (j > m) return i - m;
	else return 0;
}
void get_next(char *T, int next[]){//���next����
	int i = 0; next[i] = -1;
	int j = -1;
	int m = strlen(T);
	while (i < m)
	{
		if (j == -1 || T[i] == T[j]) { j++; i++; next[i] = j; }
		else j = next[j];
	}
}























