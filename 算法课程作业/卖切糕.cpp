#include<iostream>
#include<cstring>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    int a[10005] = { 0 };
    int f[10005] = { 0 };
    while (cin>>n && n!=0){
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        f[1] = a[1];
        for (int j = 2; j <= n; j++)
        {
            f[j] = a[j];
            for (int k = 1; k <= j; k++){
                if (f[j] < f[k] + f[j - k]) f[j] = f[k] + f[j - k];
            }
        }
        cout << f[n] << endl;
    }
     
     
 
    return 0;