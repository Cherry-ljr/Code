#include "iostream"
using namespace std;



 /*int main(){
	int n, l, t;//С��������߶γ��ȣ�t��
	int a[100] = { 0 };//���С���λ��

	int c[100] = { 0 };//���С��ǰ�˶�����1���ҡ�-1����
	cin >> n >> l >> t;
	for (int i = 0; i < n;i++){
		cin >> a[i];
	}

	for (int i = 0; i<100; i++)//С���˶������ʼ��Ϊ����
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