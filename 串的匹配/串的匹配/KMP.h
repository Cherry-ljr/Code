#include<iostream>
using namespace std;
//#include<time.h>
#include<windows.h>


int Next[20];//Next[j]表示T[j]前的最长前后缀相等的长度

int Index(char *S, char *T, int pos){
	//从pos开始查找T，返回T最早出现的位置，若不存在，返回-1
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

int Index_KMP(char *s, char *t, int pos)//实现KMP算法
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
void get_next(char *T, int next[]){//获得next数组
	int i = 0; next[i] = -1;
	int j = -1;
	int m = strlen(T);
	while (i < m)
	{
		if (j == -1 || T[i] == T[j]) { j++; i++; next[i] = j; }
		else j = next[j];
	}
}























