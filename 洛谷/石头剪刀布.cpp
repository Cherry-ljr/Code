//#include<iostream>
//using namespace std;
//
//int main(){
//	int N, NA, NB;// N 次猜拳,NA小A出拳的周期长度，NB 小B 出拳的周期长度。
//	int a[205] = { 0 };
//	int b[205] = { 0 };
//	int ans1 = 0;
//	int ans2 = 0;
//	int m[5][5] = { {0,-1,1,1,-1}, {0,0,-1,1,-1}, {0,0,0,-1,1}, {0,0,0,0,1}, {0,0,0,0,0} };
//
//	cin >> N >> NA >> NB;
//	for (int i = 0; i < NA; i++)
//		cin >> a[i];
//	for (int i = 0; i < NB; i++)
//		cin >> b[i];
//
//	for (int i = 0; i < N; i++)
//	{
//		if (m[a[i%NA]][b[i%NB]] > 0) ans1++;
//		else if (m[a[i%NA]][b[i%NB]] < 0) ans2++;
//		else {
//			if (m[b[i%NB]][a[i%NA]] < 0) ans1++;
//			if (m[b[i%NB]][a[i%NA]] > 0) ans2++;
//		}
//	
//	}
//	cout << ans1 << " " << ans2 << endl;
//
//
//	return 0;
//}