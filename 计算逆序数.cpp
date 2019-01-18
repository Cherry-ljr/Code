#include<iostream>
using namespace std;
 
int n;
int a[1005] = { 0 };
int b[1005] = { 0 };
int c[1005] = { 0 };
int ans = 0;
 
 
void combine(int b[], int c[], int first, int mid, int last){
 
    int bf = first;
    int cf = mid + 1;
    int af = first;
    while (1) {
        if (bf > mid || cf > last) break;
        if (b[bf] < c[cf]) {
            a[af++] = b[bf];
            bf++;
        }
        else {
            ans = ans + (mid - bf + 1);
            a[af++] = c[cf];
            cf++;
        }
    }
    for (int i = bf; i <= mid; i++) a[af++] = b[i];
    for (int i = cf; i <= last; i++) a[af++] = c[i];
}
 
void divide(int first, int last){
    if (first == last) return;
     
    int mid = (first + last) / 2;
    divide(first, mid);
    divide(mid + 1, last);
 
    for (int i = first; i <= mid; i++)
        b[i] = a[i];
    for (int j = mid + 1; j <= last; j++)
        c[j] = a[j];
    combine(b, c, first, mid, last);
}
 
 
int main(){
 
    while (cin >> n && n != 0)
    {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        divide(1, n);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}