//#include<iostream>
//#include<cstring>
//#include<queue>
//#include<cstdio>
//using namespace std;
//
//int n;
//int m;
//char mpt[1005][1005] = { 0 };
//int vis[1005][1005] = { 0 };
//int f[1005][1005] = { 0 };
//int dir[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
//int ans;
//
//
//
//struct node{
//	int x, y;
//}p[1005*1005];
//
//void bfs(int xx, int yy){
//	queue<node> q;
//	q.push(node{ xx, yy });
//	ans = 0;
//	p[ans].x = xx;
//	p[ans].y = yy;
//	memset(vis, 0, sizeof(vis));
//	vis[xx][yy] = 1;
//	
//	
//	while (!q.empty())
//	{
//		node now = q.front();
//		q.pop();
//		ans++;
//		p[ans].x = now.x;
//		p[ans].y = now.y;
//		if (mpt[now.x][now.y] == '0'){
//			for (int i = 0; i < 4; i++)
//			{
//				int tx = now.x + dir[i][0];
//				int ty = now.y + dir[i][1];
//				if (tx<0 || tx >= n || ty<0 || ty >= n) continue;
//				if (mpt[tx][ty] == '1'&&vis[tx][ty] == 0)
//				{
//					q.push(node{ tx, ty });
//					vis[tx][ty] = 1;
//				}
//
//			}
//		}
//
//
//		else{
//
//			for (int i = 0; i < 4; i++)
//			{
//				int tx = now.x + dir[i][0];
//				int ty = now.y + dir[i][1];
//				if (tx<0 || tx >= n || ty<0 || ty >= n) continue;
//				if (mpt[tx][ty] == '0'&&vis[tx][ty] == 0)
//				{
//					q.push(node{ tx, ty });
//					vis[tx][ty] = 1;
//				}
//
//			}
//
//
//		}
//	}
//	for (int i = 0; i <= ans; i++) {
//		f[p[i].x][p[i].y] = ans;
//	}
//}
//
//int main(){
//
//	int x, y;
//	cin >> n >> m;
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < n; j++)
//			cin >> mpt[i][j];
//	}
//	for (int i = 0; i < n; i++) scanf("%s", mpt[i]);
//	ans = 0;
//
//	while (m--){
//		
//		cin >> x >> y;
//		scanf("%d%d", &x, &y);
//		x--; y--;
//		if (f[x][y] == 0) {
//			bfs(x, y);
//		}
//		
//		cout << f[x][y] << endl;
//		printf("%d\n", f[x][y]);
//
//	}
//
//	return 0;
//}