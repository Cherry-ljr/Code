#include"iostream"
using namespace std;

//int main(){
//	int n, k;
//	int a[1009] = { 0 };
//	int j = 0;
//	int m;
//	
//	cin >> n >> k;
//
//	while (1){
//		int	flag = 0;
//		int last = 0;
//		for (int i = 1; i <= n; i++){   
//			if (a[i] == 0) j++;
//			if (j%k == 0 || j % 10 == k) {
//				a[i] = 1;
//				last = i;
//			}
//		}
//		for (int i = 1; i <= n; i++)
//			if (a[i] == 0)  {flag++; m = i;}
//			if (flag == 0) m = last;
//		if (flag == 1 || flag == 0) break;
//	}
//	
//	 cout << m << endl;
//	
//	return 0;
//}