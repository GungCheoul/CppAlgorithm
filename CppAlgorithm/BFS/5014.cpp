#include <iostream>
#include <queue>
using namespace std;

int dist[1000002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	fill(dist, dist + f + 1, -1);

	queue<int> q;
	dist[s] = 0;
	q.push(s);
	while (dist[g] == -1 && !q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nxt : {cur + u, cur - d}) {
			if (nxt < 1 || nxt > f) continue;
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	if (dist[g] == -1) cout << "use the stairs";
	else cout << dist[g];

	return 0;
}