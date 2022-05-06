#include <iostream>
#include <stack>
using namespace std;

#define X first
#define Y second

int N;
stack<pair<int, int>> S;
long long ans = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long cnt = 0;
	cin >> N;
	while (N--) {
		int height;
		cin >> height;
		cnt = 1;
		while (!S.empty() && S.top().X <= height) {
			ans += S.top().Y;
			if (S.top().X == height) cnt += S.top().Y;
			S.pop();
		}
		if (!S.empty()) ans++;
		S.push({ height, cnt });
	}
	cout << ans;

	return 0;
}