#include <iostream>
#include<stdio.h>
#include <queue>
#include <vector>
#include<algorithm>
using namespace std;

int n;

struct node{
	int v1, v2;
	int d;
}a[5050];

int cmp(node n1, node n2){
	if (n1.d< n2.d)
		return 1;
	return 0;
}
int main() {

	while (scanf("%d", &n) != EOF && n){
		for (int i = 0; i<n*(n - 1) / 2; i++){
			//cin>>a[i].v1>>a[i].v2>>a[i].d;
			scanf("%d%d%d", &a[i].v1, &a[i].v2, &a[i].d);
		}
		int s[5050 + 5];//
		int ans = 0;

		for (int i = 1; i <= n; i++)
			s[i] = i;
		sort(a, a + n*(n - 1) / 2, cmp);
		int cnt = 0;

		for (int i = 0; i<n*(n - 1) / 2; i++)
		{

			if (s[a[i].v1] == s[a[i].v2]) continue;
			else
			{
				int temp = s[a[i].v2];
				cnt++;
				for (int j = 1; j <= n; j++){
					if (s[j] == temp)
						s[j] = s[a[i].v1];

				}
				ans += a[i].d;
			}
			if (cnt >= n - 1) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}