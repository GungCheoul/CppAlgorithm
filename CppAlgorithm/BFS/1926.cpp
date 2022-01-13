#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
int board[502][502] = {};
bool visited[502][502];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    int c = 0;
    int num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 || visited[i][j]) continue;
            num++;
            queue<pair<int, int>> q;
            visited[i][j] = 1;
            q.push({ i, j });
            int area = 0;
            while (!q.empty()) {
                area++;
                pair<int, int> cur = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (visited[nx][ny] || board[nx][ny] != 1) continue;
                    visited[nx][ny] = 1;
                    q.push({ nx, ny });
                }
            }
            c = max(c, area);
        }
    }
    cout << num << '\n' << c;
}