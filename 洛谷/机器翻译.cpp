#include<iostream>
using namespace std;


/*int main(){
	int m, n;//m为内存容量，n为文章长度
	int cnt = 0;
	int s[1005] = { 0 };
	int a[1005] = { 0 };
	int k = 0;
	cin >> m >> n;
	for (int i = 0; i < m; i++){
		s[i]  = -1;
	}
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	

	for (int i = 0; i < n; i++){
			int flag = 0;

			for (int j = 0; j < m; j++)
			{
				if (a[i] == s[j]) 
					 flag = 1;
			}

			if (flag == 1) continue;
			
			s[k%m] = a[i];
			cnt++;
			k++;			
	}

	cout << cnt<<endl;
	
	return 0;

}*/