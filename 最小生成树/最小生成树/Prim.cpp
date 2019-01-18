#include <iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

/*
int main() {
	int n;
	int mpt[105][105];
	while (scanf("%d", &n) != EOF && n){

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (i == j) mpt[i][j] = 0;
				else mpt[i][j] = 999;
			}
		}
		for (int i = 0; i<n*(n - 1) / 2; i++){
			int a, b, c;
			//cin>>a[i].v1>>a[i].v2>>a[i].d;
			scanf("%d%d%d", &a, &b, &c);
			mpt[a][b] = c;
			mpt[b][a] = c;
		}
		int d[105];
		for (int i = 1; i <= n; i++) d[i] = 999999;
		int f[105] = { 0 };
		int ans = 0;
		d[1] = 0;
		for (int i = 1; i <= n; i++){
			int minn = 999999;
			int x = -1;
			for (int j = 1; j <= n; j++)
			{
				if (d[j]<minn && f[j] == 0) {
					minn = d[j];
					x = j;
				}
			}
			f[x] = 1;
			ans += d[x];
			for (int k = 1; k <= n; k++){
				if (f[k] == 0)
					d[k] = min(mpt[x][k], d[k]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
*/