#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[102][102];
int dist[102][102];
bool visited[102][102];
int n, cnt;
queue<pair<int, int>> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	// cnt: number of island, cnt=board[i][j] means same island
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0 || visited[i][j]) continue;
			cnt++;
			visited[i][j] = true;
			board[i][j] = cnt;
			Q.push({ i, j });
			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (visited[nx][ny] || board[nx][ny] == 0) continue;
					board[nx][ny] = cnt;
					visited[nx][ny] = true;
					Q.push({ nx, ny });
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++)
		fill(dist[i], dist[i] + n, -1);
	int temp = 999999;
	// bfs for island, calc when initial nx/ny is found
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] != 0) {
				Q.push({ i, j });
				dist[i][j] = 0;
				bool escape = false;
				while (!Q.empty() && !escape) {
					auto cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (dist[nx][ny] >= 0 || board[nx][ny] == board[i][j]) continue;
						if (board[nx][ny] != 0 && board[i][j] != board[nx][ny]) {
							temp = min(temp, dist[cur.X][cur.Y]);
							while (!Q.empty()) Q.pop();
							escape = true;
							break;
						}
						dist[nx][ny] = dist[cur.X][cur.Y] + 1;
						Q.push({ nx, ny });
					}
				}
				for (int i = 0; i < n; i++)
					fill(dist[i], dist[i] + n, -1);
			}
		}
	}
	cout << temp;

	return 0;
}