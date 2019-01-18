#include "iostream"
#include "algorithm"
using namespace std;

struct node {
	int w, s, c;
}a[1005];

int cmp(node x, node y) {
	return x.w < y.w;
}

/*int main(){

	int n, k;		//n间教室，k个老师
	//int w, s, c;	//钥匙编号，上课时间，上课时长
	//int a[1005][3] = { 0 };

	int b[1005] = { 0 };
	
	cin >> n >> k; 
	for (int i = 0; i < k; i++)
	{
			cin >> a[i].w >> a[i].s >> a[i].c;	
	}	
	for (int i = 1; i <= n; i++)//钥匙编号
		b[i] = i;

	sort(a, a + k, cmp);


	for (int t = 1; t <= 10100; t++){
		for (int i = 0; i < k; i++)
		{
			if (t == a[i].s + a[i].c){
				for (int j = 1; j <= n; j++)
				if (b[j] == 0){
					b[j] = a[i].w; break;
				}
			}


		}
		for (int i = 0; i < k; i++)
		{
			if (a[i].s == t)
			for (int j = 1; j <= n; j++)
			{
				if (b[j] == a[i].w)
				{
					b[j] = 0;
					break;
				}
			}

		}
	}
	for (int i = 1; i <= n; i++)
		cout << b[i] << " ";
	cout << endl;

	return 0;



}*/