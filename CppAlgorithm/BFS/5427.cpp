#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
int dist[1002][1002];
int fdist[1002][1002];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, w, h;
    cin >> t;

    while (t--) {
        queue<pair<int, int>> q = {};
        queue<pair<int, int>> fq = {};

        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            fill(dist[i], dist[i] + w, 0);
            fill(fdist[i], fdist[i] + w, 0);
        }
        for (int i = 0; i < h; i++) {
            string board;
            cin >> board;
            for (int j = 0; j < w; j++) {
                if (board[j] == '@') {
                    q.push({ i, j });
                }
                if (board[j] == '*') {
                    fq.push({ i, j });
                }
                if (board[j] == '.') {
                    dist[i][j] = -1;
                    fdist[i][j] = -1;
                }
            }
        }

        while (!fq.empty()) {
            auto cur = fq.front();
            fq.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (fdist[nx][ny] >= 0) continue;
                fdist[nx][ny] = fdist[cur.X][cur.Y] + 1;
                fq.push({ nx, ny });
            }
        }
        bool check = 1;
        bool check2 = 1;
        while (!q.empty() && check2) {
            auto cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                    cout << dist[cur.X][cur.Y] + 1 << "\n";
                    check = 0;
                    check2 = 0;
                    break;
                }
                if (dist[nx][ny] >= 0) continue;
                if (fdist[nx][ny] != -1 && fdist[nx][ny] <= dist[cur.X][cur.Y] + 1) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({ nx, ny });
            }
        }
        if (check) cout << "IMPOSSIBLE" << "\n";
    }

    return 0;
}