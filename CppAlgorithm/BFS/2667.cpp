#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second
string board[32];
bool visited[32][32];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> board[i];

	int cnt = 0;
	vector<int> areas;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] || board[i][j] == '0') continue;
			cnt++;
			queue<pair<int, int>> q;
			visited[i][j] = 1;
			q.push({ i, j });
			int area = 0;
			while (!q.empty()) {
				area++;
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (visited[nx][ny] || board[nx][ny] == '0') continue;
					visited[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}
			areas.push_back(area);
		}
	}
	sort(areas.begin(), areas.end());
	cout << cnt << '\n';
	for (int i : areas)
		cout << i << '\n';

	return 0;
}