#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
int board[51][51];
bool dist[51][51];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, m, n, k;
    cin >> t;
    while (t--) {
        cin >> m >> n >> k;
        int x, y;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            board[y][x] = 1;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != 1 || dist[i][j]) continue;
                res++;
                q.push({ i, j });
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    dist[i][j] = true;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (dist[nx][ny] || board[nx][ny] != 1) continue;
                        dist[nx][ny] = true;
                        q.push({ nx, ny });
                    }
                }
            }
        }
        cout << res << "\n";
        for (int i = 0; i < n; i++) {
            fill(board[i], board[i] + m, 0);
            fill(dist[i], dist[i] + m, false);
        }
    }

    return 0;
}