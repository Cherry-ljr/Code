#include <iostream>
#include <cstring>
using namespace std;
 
const int maxn = 10000 + 5;
int tree[maxn << 2];
char a[15] = { 0 };
int n, m;
 
void build(int x, int h) {
    if (h == m + 1) {
        if (a[h] == 'Y') tree[x] = 1;
        else tree[x] = 0;
        return;
    }
    if (a[h] == 'H') {
        build(x * 2, h + 1);
        int now = tree[x];
        int lson = tree[2 * x];
        if (now == -1) tree[x] = tree[2 * x];
        else {
            if (now != lson) tree[x] = 2;
        }
    }
    else {
        build(x * 2 + 1, h + 1);
        int now = tree[x];
        int rson = tree[2 * x+1];
        if (now == -1) tree[x] = tree[2 * x+1];
        else {
            if (now != rson) tree[x] = 2;
        }
    }
     
}
 
char path[15] = { 0 };
void query(int x, int h) {
    if (tree[x] == 0 || tree[x] == 1) {
        for (int i = 1; i < h; i++) {
            cout << path[i];
        }
        if (tree[x] == 1) cout << "Y;";
        else cout << "N;";
        return;
    }
    if (tree[2 * x] != -1) {
        path[h] = 'H';
        query(2 * x, h + 1);
    }
    if (tree[2 * x + 1] != -1) {
        path[h] = 'L';
        query(2 * x + 1, h + 1);
    }
}
 
 
int main(){
     
 
    while (cin >> n >> m){
        if (n == 0 && m == 0)break;
        memset(tree, -1, sizeof(tree));
        memset(path, 0, sizeof(path));
        for (int i = 0; i < n; i++)
        {
            int index;
            cin >> index;
            memset(a, 0, sizeof(a));
            for (int j = 1; j <= m + 1; j++)
                cin >> a[j];
            build(1, 1);
 
        }
        query(1, 1);
        cout << endl;
    }
    return 0;
}