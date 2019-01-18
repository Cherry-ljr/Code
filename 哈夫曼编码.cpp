#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
 
priority_queue<int, vector<int>, greater<int> > q;
int main() {
    int n;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            char ch; int x;
            cin >> ch >> x;
            q.push(x);
        }
        int ans = 0;
        while (!q.empty()) {
            int a = q.top();
            q.pop();
            if (q.empty()) break;
            int b = q.top();
            q.pop();
            ans += a + b;
            q.push(a + b);
        }
        cout << ans << endl;
    }
    return 0;
}