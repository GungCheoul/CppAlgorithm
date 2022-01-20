#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int board[101][101];
int visited[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		board[r - 1][c - 1] = 1;
	}

	int maxarea = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] || board[i][j] != 1) continue;
			queue<pair<int, int>> q;
			visited[i][j] = 1;
			q.push({ i, j });
			int area = 1;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
					if (visited[nx][ny] || board[nx][ny] != 1) continue;
					visited[nx][ny] = 1;
					q.push({ nx , ny });
					area++;
				}
			}
			maxarea = max(maxarea, area);
		}
	}
	cout << maxarea;
}