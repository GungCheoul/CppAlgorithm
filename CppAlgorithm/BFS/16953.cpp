#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

#define LL long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	LL a, b;
	cin >> a >> b;
	
	map<LL, LL> mp;
	mp.insert({ a, 0 });
	queue<LL> q;
	q.push(a);
	while (!q.empty()) {
		LL cur = q.front();
		q.pop();
		for (LL nxt : {(cur * 10) + 1, cur * 2}) {
			if (mp.find(b) != mp.end()) {
				cout << mp[b] + 1;
				return 0;
			}
			if (nxt > b) continue;
			mp.insert({ nxt, mp[cur] + 1 });
			q.push(nxt);
		}
	}
	cout << -1;
}