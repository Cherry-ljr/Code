//#include<bits/stdc++.h>
//using namespace std;
//
//const int maxn = 1e3 + 10;
//int a[maxn];
//
//int main(){
//	int n;
//	cin >> n;
//	for (int i = n; i >= 0; i--) {
//		cin >> a[i];
//	}
//	int first = 0;
//	for (int i = n; i >= 0; i--) {
//		if (a[i] == 0) continue;
//		if (a[i] > 0) {
//			if (a[i] == 1) {
//				if (i == 0) cout << "+" << "1";
//				else if (i == 1) cout << "+" << "x";
//				else cout << "+" << "x^" << i;
//			}
//			else {
//				if (i == 0) cout << "+" << a[i];
//				else if (i == 1)cout << "+" << a[i] << "x";
//				else cout << "+" << a[i] << "x^" << i;
//			}
//		}
//		else {
//			if (a[i] != -1) {
//				if (i == 0) cout << "-" << -a[i];
//				else if (i == 1) cout << "-" << -a[i] << "x" << i;
//				else cout << "-" << -a[i] << "x^" << i;
//			}
//			else {
//				if (i == 0) cout << "-" << -a[i];
//				else if (i == 1) cout << "-" << "x";
//				else cout << "-" << "x^" << i;
//			}
//		}
//		first = 1;
//	}
//	return 0;
//}
