#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int board[102][102];
bool visited[102][102];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int m = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			m = max(m, board[i][j]);
		}
	}
	
	int mcnt = 0;
	for (int limit = 0; limit <= m; limit++) {
		for (int i = 0; i < n; i++)
			fill(visited[i], visited[i] + n, 0);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] || board[i][j] <= limit) continue;
				cnt++;
				visited[i][j] = 1;
				queue<pair<int, int>> q;
				q.push({ i, j });
				while (!q.empty()) {
					auto cur = q.front();
					q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (visited[nx][ny] || board[nx][ny] <= limit) continue;
						visited[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
		}
		mcnt = max(mcnt, cnt);
	}
	cout << mcnt;

	return 0;
}