#include<iostream>
using namespace std;

/*int skipTable[256];

void fill_skipTable_sunday(char *T){
	int m = strlen(T);
	for (int i = 0; i < 256; i++)//如果一个字符未在模式串中未出现过，则模式串需要移动m+1的长度
		skipTable[i] = m + 1;
	for (int i = 0; i < m; i++)//如果一个字符未在模式串中出现过，则模式串需要移动的距离=串长度—该字符最后出现的位置
		skipTable[T[i]] = m - i;
}
int Index_Sunday(char *S, char *T, int pos)
{
	int n = strlen(S);
	int m = strlen(T);
	int i = 0;
	int n_m = n - m;
	while (i <= n_m)
	{
		if (memcpy(S + i, T, m) == 0)//若匹配，则返回位置i
			return i;
		i = i + skipTable[S[i + m]]
	//	i += skipTable[S[i+m]];
		
	}
	return -1;

}*/
int skipTable[256];
void fill_skipTable_sunday(char *T) {
	int m = strlen(T);
	for (int i = 0; i < 256; i++)//如果一个字符没有在模式串中出现过，则模式串需要移动m+1的长度
		skipTable[i] = m + 1;
	for (int i = 0; i < m; i++)//如果一个字符在模式串中出现过，则模式串需要移动的距离为串长度减去该字符最后出现的位置
		skipTable[T[i]] = m - i;
}
int Index_Sunday(char *S, char *T, int pos) {
	int n = strlen(S);
	int m = strlen(T);
	int i = 0;
	int n_m = n - m;
	while (i <= n_m) {
		if (memcmp(S + i, T, m) == 0)//如果匹配，则返回到位置i
			return i+1;
		i = i + skipTable[S[i + m]];//i+m为主串和模式串对齐后，在模式串右边的第一个字符下标
	}
	return -1;
}
