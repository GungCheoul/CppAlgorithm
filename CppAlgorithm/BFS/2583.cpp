#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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

	int m, n, k;
	cin >> m >> n >> k;
	for (int i = 0; i < n; i++)
		fill(board[i], board[i] + m, 1);
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = 0; i < y2 - y1; i++) {
			for (int j = 0; j < x2 - x1; j++)
				board[x1 + j][y1 + i] = 0;
		}
	}

	int cnt = 0;
	vector<int> area;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] || board[i][j] == 0) continue;
			cnt++;
			queue<pair<int, int>> q;
			q.push({ i, j });
			visited[i][j] = 1;
			int c = 1;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (visited[nx][ny] || board[nx][ny] == 0) continue;
					visited[nx][ny] = 1;
					q.push({ nx, ny });
					c++;
				}
			}
			area.push_back(c);
		}
	}
	sort(area.begin(), area.end());
	cout << cnt << "\n";
	for (int i : area)
		cout << i << " ";
	

	return 0;
}