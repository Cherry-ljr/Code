#include<iostream>
using namespace std;

/*int skipTable[256];

void fill_skipTable_sunday(char *T){
	int m = strlen(T);
	for (int i = 0; i < 256; i++)//���һ���ַ�δ��ģʽ����δ���ֹ�����ģʽ����Ҫ�ƶ�m+1�ĳ���
		skipTable[i] = m + 1;
	for (int i = 0; i < m; i++)//���һ���ַ�δ��ģʽ���г��ֹ�����ģʽ����Ҫ�ƶ��ľ���=�����ȡ����ַ������ֵ�λ��
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
		if (memcpy(S + i, T, m) == 0)//��ƥ�䣬�򷵻�λ��i
			return i;
		i = i + skipTable[S[i + m]]
	//	i += skipTable[S[i+m]];
		
	}
	return -1;

}*/
int skipTable[256];
void fill_skipTable_sunday(char *T) {
	int m = strlen(T);
	for (int i = 0; i < 256; i++)//���һ���ַ�û����ģʽ���г��ֹ�����ģʽ����Ҫ�ƶ�m+1�ĳ���
		skipTable[i] = m + 1;
	for (int i = 0; i < m; i++)//���һ���ַ���ģʽ���г��ֹ�����ģʽ����Ҫ�ƶ��ľ���Ϊ�����ȼ�ȥ���ַ������ֵ�λ��
		skipTable[T[i]] = m - i;
}
int Index_Sunday(char *S, char *T, int pos) {
	int n = strlen(S);
	int m = strlen(T);
	int i = 0;
	int n_m = n - m;
	while (i <= n_m) {
		if (memcmp(S + i, T, m) == 0)//���ƥ�䣬�򷵻ص�λ��i
			return i+1;
		i = i + skipTable[S[i + m]];//i+mΪ������ģʽ���������ģʽ���ұߵĵ�һ���ַ��±�
	}
	return -1;
}
