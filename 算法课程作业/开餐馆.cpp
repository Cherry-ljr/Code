#include<iostream>
#include<algorithm>
using namespace std;
 
int main()
{
    int n;
    int p[10005] = { 0 };
    int m[10005] = { 0 };
    int f[10005] = { 0 };
    int k;
    while (cin >> n && n != 0){
 
        for (int i = 1; i <= n; i++)
            cin >> m[i];
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        cin >> k;
         
        for (int i = 1; i<=n; i++)
        {
         
            f[i] = 0;   //记录每个位置的初始总利润 
        }
        f[1] = p[1];
        for (int i = 2; i <= n; i++)
        {
            int maxx = 0;
            for (int j = 1; j<i; j++)
            {
                if (m[i] - m[j] >= k)
                {
                    maxx = max(maxx, f[j] + p[i]);//每个位置的最大利润 
                }
            }
            f[i] = maxx;
        }
        int ans = f[1];
        for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
        cout << ans << endl;
 
    }
    return 0;
}