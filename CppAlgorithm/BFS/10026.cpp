#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
char board[101][101];
bool visited[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n;

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({ i, j });
    visited[i][j] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny] == 1 || board[i][j] != board[nx][ny]) continue;
            visited[nx][ny] = 1;
            q.push({ nx, ny });
        }
    }
}

int area() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                cnt++;
                bfs(i, j);
            }
        }
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    int p1 = area();

    for (int i = 0; i < n; i++)
        fill(visited[i], visited[i] + n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'G')
                board[i][j] = 'R';
        }
    }

    int p2 = area();

    cout << p1 << " " << p2;

    return 0;
}