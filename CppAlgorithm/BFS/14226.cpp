#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int emo[1002][1002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int s;
	cin >> s;

	for (int i = 0; i < 1002; i++)
		fill(emo[i], emo[i] + 1002, -1);
	queue<pair<int, int>> q;
	emo[1][0] = 0;
	q.push({ 1, 0 });
	int result = 9999;
	while (!q.empty()) {
		auto cur = q.front();
		int dis = cur.X;
		int clip = cur.Y;
		int t = emo[dis][clip];
		q.pop();
		if (dis == s) {
			result = min(result, t);
			continue;
		}
		if (emo[dis][dis] == -1) {
			emo[dis][dis] = t + 1;
			q.push({ dis, dis });
		}
		if (dis + clip <= s && emo[dis + clip][clip] == -1) {
			q.push({ dis + clip, clip });
			emo[dis + clip][clip] = t + 1;
		}
		if (dis - 1 >= 0 && emo[dis - 1][clip] == -1) {
			emo[dis - 1][clip] = t + 1;
			q.push({ dis - 1, clip });
		}
	}
	cout << result;

	return 0;
}