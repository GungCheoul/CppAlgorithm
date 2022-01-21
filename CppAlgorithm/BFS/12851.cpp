#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int dist[100002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	fill(dist, dist + 100002, -1);
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	dist[n] = 1;
	int cnt = 0, mincnt = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		dist[cur.X] = 1;
		if (mincnt && mincnt == cur.Y && cur.X == k) cnt++;
		if (!mincnt && cur.X == k) {
			mincnt = cur.Y;
			cnt++;
		}
		for (int nxt : {cur.X - 1, cur.X + 1, cur.X * 2}) {
			if (nxt < 0 || nxt > 100000) continue;
			if (dist[nxt] != -1) continue;
			q.push({ nxt, cur.Y + 1 });
		}
	}
	cout << mincnt << '\n' << cnt;
}