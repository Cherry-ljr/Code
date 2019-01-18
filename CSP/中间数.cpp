#include"iostream"
using namespace std;

/*int main(){
	int n;
	int maxx = 0;
	int minx = 0;
	int flag = 0;//判断是否有中间数
	int a[1000] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[j]>a[i]) maxx++;
			else if (a[j] < a[i]) minx++;

		}
		if (minx == maxx && flag==0)
		{
			cout << a[i] << endl;
			flag = 1;
		}
		minx = maxx = 0;
	}
	if (flag == 0) cout << -1 <<endl;

	return 0;
}*/