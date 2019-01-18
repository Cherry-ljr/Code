#include<iostream>
#include<algorithm>
using namespace std;


int main(){
	int a[105] = { 0 };
	int f[105];
	int val;
	int n;
	cin >> n>>val;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i <= val; i++){
		f[i] = 999;
	}
	f[0] = 0;

	for (int i = 1; i <= val; i++){		
		for (int j = 0; j < n; j++) {
			int temp = i - a[j];
			if (temp >= 0 && f[temp] != 999){
				f[i] = min(f[i], f[temp] + 1);
			}
		}
	   cout<<f[val]<<endl;
	}

	return 0;
}