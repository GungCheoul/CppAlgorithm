#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define X first
#define Y second

char board[1000][1000];
int dist[1000][1000][2];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			dist[i][j][0] = dist[i][j][1] = -1;
	}
	dist[0][0][0] = dist[0][0][1] = 1;
	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });
	while (!q.empty()) {
		auto cur = q.front();
		int x, y, b;
		tie(x, y, b) = cur;
		if (x == n - 1 && y == m - 1) {
			cout << dist[x][y][b];
			return 0;
		}
		q.pop();
		int nd = dist[x][y][b] + 1;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == '0' && dist[nx][ny][b] == -1) {
				dist[nx][ny][b] = nd;
				q.push({ nx, ny, b });
			}
			if (!b && board[nx][ny] == '1' && dist[nx][ny][1] == -1) {
				dist[nx][ny][1] = nd;
				q.push({ nx, ny, 1 });
			}
		}
	}
	cout << -1;
}
