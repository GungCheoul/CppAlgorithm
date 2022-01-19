#include <iostream>
using namespace std;

int students[100005];
int sel[100005];
int n;

const int notvisited = 0;
const int cycle = -1;

void check(int x) {
	int cur = x;
	while (true) {
		sel[cur] = x;
		cur = students[cur];
		if (sel[cur] == x) {
			while (sel[cur] != cycle) {
				sel[cur] = cycle;
				cur = students[cur];
			}
			return;
		}
		else if (sel[cur] != 0) return;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		fill(sel + 1, sel + n + 1, 0);
		for (int i = 1; i <= n; i++)
			cin >> students[i];

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (sel[i] == notvisited)
				check(i);
		}

		for (int i = 1; i <= n; i++) {
			if (sel[i] != cycle) cnt++;
		}
		cout << cnt << '\n';
	}
}