#include "iostream"
using namespace std;



 /*int main(){
	int n, l, t;//小球个数，线段长度，t秒
	int a[100] = { 0 };//存放小球的位置

	int c[100] = { 0 };//存放小球当前运动方向，1向右、-1向左
	cin >> n >> l >> t;
	for (int i = 0; i < n;i++){
		cin >> a[i];
	}

	for (int i = 0; i<100; i++)//小球运动方向初始化为向右
		c[i] = 1;

	
	for (int i = 0; i < t; i++){
		for (int j = 0; j < n; j++)
		{
			a[j] = a[j] + c[j];
			if (a[j] == 0 || a[j] == l) c[j] = -c[j];	

			for (int k = 0; k < n;k++)
			if (a[k] == a[j]){
				c[k] = -c[k];
				c[j] = -c[j];
			}

		}
		
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}
*/