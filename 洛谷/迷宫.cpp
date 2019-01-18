//#include<iostream>
//#include<queue>
//#include<cstring>
//using namespace std;
//
//int t, m, n;
//char mpt[105][105];
//int vis[105][105] = { 0 };
//int ans;
//
//int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
//
//void dfs(int x, int y,int step){
//	
//	if (mpt[x][y] == 'E')
//	{
//		if (step < ans) ans = step;
//		return;
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		int tx = x + dir[i][0];
//		int ty=y+dir[i][1];
//		if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
//		if ((mpt[tx][ty] == '-' || mpt[tx][ty] == 'E') && vis[tx][ty] == 0)
//		{
//			vis[tx][ty] = 1;
//			dfs(tx, ty, step + 1);
//			vis[tx][ty] = 0;
//		}
//
//	}
//
//
//
//}
//
//struct node {
//	int x, y;
//	int step;
//};
//
//void bfs(int x, int y){
//	queue<node> q;
//	q.push(node{ x, y, 0 });
//	vis[x][y] = 1;
//	while (!q.empty()) {
//		node now = q.front();
//		q.pop();
//		if (mpt[now.x][now.y] == 'E')
//		{
//			ans = now.step;
//		}
//		for (int i = 0; i < 4; i++)
//		{
//			int tx = now.x + dir[i][0];
//			int ty = now.y + dir[i][1];
//			if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
//			if ((mpt[tx][ty] == '-' || mpt[tx][ty] == 'E') && vis[tx][ty] == 0)
//			{
//			    vis[tx][ty] = 1;
//				q.push(node{ tx, ty, now.step + 1 });
//
//			}
//		}
//	}
//
//}
//
//int main(){
//
//	cin >> t;
//
//	while (t--){
//		memset(vis, 0, sizeof(vis));
//		ans = 99999;
//		cin >> m >> n;
//		for (int i = 0; i < m; i++){
//			for (int j = 0; j < n; j++)
//				cin >> mpt[i][j];
//		}
//		for (int i = 0; i < m; i++){
//			for (int j = 0; j < n; j++)
//			{
//				
//				if (mpt[i][j] == 'S'){
//					//vis[i][j] = 1;
//					//dfs(i, j, 0);
//					//vis[i][j] = 0;
//					bfs(i, j);
//					
//				}
//			}
//		}
//		if (ans != 99999) cout << ans << endl;
//		else cout << -1<<endl;
//	}
//
//	return 0;
//}