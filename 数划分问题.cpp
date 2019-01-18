#include <iostream>
using namespace std;

int abs(int a){
	if (a>0) return a;
	else return -a;
}
int main(){
	int n;
	while (cin>>n&&n>0)
	{
	    int a[25] = { 0 };
	    int sum = 9999;
		int cnt = 1;
		for (int i = 0; i<n; i++)
			cin >> a[i];

		for (int j = 0; j<n; j++)
			cnt = cnt * 2;

		for (int i = 0; i<cnt; i++)
		{
			int temp = i;
			int sum1 = 0;
			int sum2 = 0;
			for (int j = 0; j <= n; j++)
			{
				if (temp % 2)
					sum1 += a[j];
				else sum2 += a[j];
				temp = temp / 2;
			}
			if (sum>abs(sum1 - sum2))
				sum = abs(sum1 - sum2);

		}
		cout << sum << endl;
	}

	return 0;
}
