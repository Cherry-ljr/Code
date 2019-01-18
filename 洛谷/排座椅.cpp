//#include <iostream>
//#include<algorithm>
//using namespace std;
//
//
////int cmp(int xx, int yy){
////
////	return xx > yy;
////}
//
//int main(){ 
//	int M, N, K, L, D;  //M行N列，划分K行L列，有D对小朋友交头接耳
//	int a[2005] = { 0 };//行
//	int b[2005] = { 0 };//列
//	int x, y, p, q;
//	cin >> M >> N >> K >> L >> D;
//	for (int i = 0; i < D; i++)
//	{
//		cin >> x >> y >> p >> q;
//		if (x == p) {
//			if (y>q)  b[q]++;
//			else b[y]++;
//		}
//		else {
//			if (x > p) a[p]++;
//			else a[x]++;
//		}
//		
//	}
//
//	/*sort(a, a + 1000,cmp);
//	sort(b, b + 1000, cmp);*/
//	
//
//	for (int i = 0; i < K; i++)
//	{
//		int max = 0;
//		int index = 0;
//		for (int j = 0; j < 2000; j++)
//		{ 
//			if (max < a[j]){ max = a[j]; index = j; }
//
//		}
//		if (max == 0) break;
//		if (i == 0)  cout << index;
//		else cout << " " << index;
//
//
//		a[index] = 0;
//	}
//	cout << endl;
//
//	for (int i = 0; i < L; i++)
//	{
//		int max = 0;
//		int index = 0;
//		for (int j = 0; j < 2000; j++)
//		{
//			if (max < b[j]){ max = b[j]; index = j; }
//
//		}
//		if (max == 0) break;
//		if (i==0)  cout << index;
//		else cout << " " << index;
//		b[index] = 0;
//	}
//	cout << endl;
//	
//	return 0;
//}