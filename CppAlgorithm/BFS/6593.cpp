#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 1, -1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		char board[31][31][31];
		int dist[31][31][31];
		int l, r, c;
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++)
				fill(dist[i][j], dist[i][j] + c, 0);
		}

		queue<tuple<int, int, int>> q;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S') {
						dist[i][j][k] = 0;
						q.push({ i, j, k });
					}
					else if (board[i][j][k] == '.') dist[i][j][k] = -1;
				}
			}
		}
		bool check = false;
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			int curZ, curX, curY;
			tie(curZ, curX, curY) = cur;
			for (int dir = 0; dir < 6; dir++) {
				int nz = curZ + dz[dir];
				int nx = curX + dx[dir];
				int ny = curY + dy[dir];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
				if (dist[nz][nx][ny] > 0 || board[nz][nx][ny] == '#') continue;
				
				dist[nz][nx][ny] = dist[curZ][curX][curY] + 1;
				if (board[nz][nx][ny] == 'E') {
					cout << "Escaped in " << dist[nz][nx][ny] << " minute(s)." << "\n";
					check = true;
					break;
				}
				q.push({ nz, nx, ny });
			}
		}
		while (!q.empty()) q.pop();
		if (!check) cout << "Trapped!\n";
	}
}