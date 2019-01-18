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
	cout << "Sunday算法子串的第一次搜索结果是：" << index << endl;
	cout << "耗时为：" << c << "ms" << endl;
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
	cout << "Sunday算法子串的第一次搜索结果是：" << pos << endl;
	cout << "耗时为：" << cs << "ms" << endl;
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
	cout << "KMP算法子串的搜索结果是：" << p << endl;
	cout << "耗时为：" << cost << "ms" << endl;
	cout << endl;


	

	return 0;

}