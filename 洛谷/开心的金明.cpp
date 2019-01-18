#include<iostream>
#include<algorithm>
using namespace std;

int v[30] = {0};
int w[30] = {0};
int f[30][30005] = {0};
int n;   //m是物品个数，n是总钱数
int m;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> v[i] >> w[i];
	}
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++)
		{	
			int temp = j - v[i];
		//	f[i][j] = max(f[i - 1][j], f[temp][j - v[i]] + v[i] * w[i]);
			
			if (temp>=0) f[i][j] = max(f[i-1][j],f[i-1][j-v[i]] +v[i] * w[i]);
			else f[i][j] = f[i - 1][j];
		}
	}
	cout << f[m][n] << endl;
return 0;

}