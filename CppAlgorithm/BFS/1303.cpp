#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

string board[101];
int visited[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> board[i];

	int wpower = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] || board[i][j] != 'W') continue;
				queue<pair<int, int>> q;
			visited[i][j] = 1;
			q.push({ i, j });
			int cnt = 1;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
					if (visited[nx][ny] || board[nx][ny] != 'W') continue;
					visited[nx][ny] = 1;
					q.push({ nx, ny });
					cnt++;
				}
			}
			wpower += cnt * cnt;

		}
	}
	for (int i = 0; i < n; i++)
		fill(visited[i], visited[i] + m, 0);
	int bpower = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] || board[i][j] != 'B') continue;
			queue<pair<int, int>> q;
			visited[i][j] = 1;
			q.push({ i, j });
			int cnt = 1;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
					if (visited[nx][ny] || board[nx][ny] != 'B') continue;
					visited[nx][ny] = 1;
					q.push({ nx, ny });
					cnt++;
					
				}
			}
			bpower += cnt * cnt;
		}
	}

	cout << wpower << " " << bpower;
}