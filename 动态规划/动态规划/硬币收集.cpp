#include<iostream>
using namespace std;


int main(){
	int n, m;
	int a[105][105] = { 0 };
	int f[105][105] = { 0 };
	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)
		{
			f[i][j] = f[i - 1][j] + a[i][j];
			if (f[i][j] < f[i][j - 1] + a[i][j]) f[i][j] = f[i][j - 1] + a[i][j];
		}
	}
	cout << f[n][m] << endl;


	return 0;
}