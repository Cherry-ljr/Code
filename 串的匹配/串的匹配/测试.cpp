#include<iostream>
using namespace std;
#include"KMP.h"
#include"Sunday.h"

int main(){
	char S[] = "000000000000000000000000000000000000001";
	char T[] = "0000000000001";
	get_next(T, Next);
	int repeats = 1000000;

	int index;
	fill_skipTable_sunday(T);

	DWORD tstart, tEnd;

	tstart = GetTickCount();
	for (int i = 0; i < repeats; i++)
		index = Index_Sunday(S, T, 0);
	tEnd = GetTickCount();
	float c = tEnd - tstart;
	cout << "Sunday�㷨�Ӵ��ĵ�һ����������ǣ�" << index << endl;
	cout << "��ʱΪ��" << c << "ms" << endl;
	cout << endl;


	int pos;
	
	//time_t tBegin, tend;
	DWORD tBegin, tend;
	//time(&tBegin);
	tBegin = GetTickCount();
	for (int i = 0; i < repeats; i++)
		pos = Index_Sunday(S, T, 0);
	//time(&tend);
	tend = GetTickCount();
	float cs = tend - tBegin;
	cout << "Sunday�㷨�Ӵ��ĵ�һ����������ǣ�" << pos << endl;
	cout << "��ʱΪ��" << cs << "ms" << endl;
	cout << endl;

	int p;
	DWORD tBegin1, tend1;
	//time(&tBegin);
	tBegin1 = GetTickCount();
	for (int i = 0; i < repeats; i++)
		p = Index_KMP(S, T, 0);
	//time(&tend);
	tend1 = GetTickCount();
	float cost = tend1 - tBegin1;
	cout << "KMP�㷨�Ӵ�����������ǣ�" << p << endl;
	cout << "��ʱΪ��" << cost << "ms" << endl;
	cout << endl;


	

	return 0;

}