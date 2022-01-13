#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
int board[304][304];
int dist[304][304];
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int t, l;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    int x1, y1, x2, y2;

    while (t--) {
        cin >> l >> x1 >> y1 >> x2 >> y2;
        for (int i = 0; i < l; i++)
            fill(dist[i], dist[i] + l, -1);
        queue<pair<int, int>> q;
        q.push({ x1, y1 });
        dist[x1][y1] = 0;
        while (dist[x2][y2] == -1) {
            auto cur = q.front();
            q.pop();
            for (int dir = 0; dir < 8; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if (dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({ nx, ny });
            }
        }
        cout << dist[x2][y2] << "\n";
    }

    return 0;
}