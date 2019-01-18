//#include<iostream>
//using namespace std;
//
//int main(){
//
//	int a[105] = { 0 };
//	int n;
//	int f[105] = { 0 };
//	cin >> n;
//	for (int i = 0; i < n; i++){
//		cin >> a[i];
//	}
//	f[0] = a[0];
//	f[1] = a[1];
//	for (int i = 2; i < n; i++){
//		f[i] = f[i - 2]+a[i];
//		if (f[i] < f[i - 1]) f[i] = f[i - 1];
//		if (i == n - 1) cout << f[i] << endl;
//	}
//
//	return 0;
//}
