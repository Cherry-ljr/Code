#include "iostream"
using namespace std;

int abs(int a)
{
	if (a > 0) return a;
	else return -a;
}
int main(){

	int n, m;
	cin >> n >> m;//n ––£¨m¡–
	int a[1005][35] = { 0 };
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
		{
			if (abs(a[i][j]) == abs(a[i][j + 1]) && abs(a[i][j]) == abs(a[i][j + 2])) a[i][j] = a[i][j + 1] = a[i][j + 2] = -a[i][j];
			if (abs(a[i][j]) == abs(a[i + 1][j]) && abs(a[i][j]) == abs(a[i + 2][j]))  a[i][j] = a[i + 1][j] = a[i + 2][j] = -a[i][j];
		}
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
		{
			if (a[i][j]<0) a[i][j] = 0;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}