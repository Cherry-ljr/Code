#include <bits/stdc++.h>
using namespace std;

int n = 3;
int vis[10] = {0};
int a[10];

void dfs(int step) {

    if (step >= n + 1) {
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            a[step] = i;
            dfs(step + 1);
            vis[i] = 0;
        }
    }
}

int main() {
    dfs(1);
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

int cmp(int x, int y) {
    if (x < y) return 1;
    else return 0;
}

int main() {
    int arr1[3] = {3,1,2};
    sort(arr1, arr1+3,cmp);
    for (int i = 0; i < 3; i++) {
        //cout << arr1[i] << " ";
    }
    //cout << endl;
    while(1) {
        for (int i = 0; i < 3; i++) {
            cout << arr1[i] << " ";
        }
        cout << endl;
        if (next_permutation(arr1, arr1+3) == 0) break;
    }
    return 0;
}
