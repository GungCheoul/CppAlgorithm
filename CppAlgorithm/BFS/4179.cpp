#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define X first
#define Y second
string board[1002];
int dist[1002][1002];
int fdist[1002][1002];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        fill(dist[i], dist[i] + c, -1);
        fill(fdist[i], fdist[i] + c, -1);
    }
    for (int i = 0; i < r; i++)
        cin >> board[i];
    queue<pair<int, int>> q;
    queue<pair<int, int>> fq;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'J') {
                q.push({ i, j });
                dist[i][j] = 0;
            }
            if (board[i][j] == 'F') {
                fq.push({ i, j });
                fdist[i][j] = 0;
            }
        }
    }
    while (!fq.empty()) {
        auto cur = fq.front();
        fq.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (fdist[nx][ny] >= 0 || board[nx][ny] == '#')continue;
            fdist[nx][ny] = fdist[cur.X][cur.Y] + 1;
            fq.push({ nx, ny });
        }
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << dist[cur.X][cur.Y] + 1;
                return 0;
            }
            if (dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if (fdist[nx][ny] != -1 && fdist[nx][ny] <= dist[cur.X][cur.Y] + 1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({ nx, ny });
        }
    }
    cout << "IMPOSSIBLE";
}
