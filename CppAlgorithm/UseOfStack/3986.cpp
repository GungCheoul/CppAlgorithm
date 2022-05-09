#include <iostream>
#include <stack>
#include <string>
using namespace std;

int N;
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N--) {
		string word;
		cin >> word;
		stack<int> S;
		for (auto w : word) {
			if (!S.empty() && S.top() == w)
				S.pop();
			else S.push(w);
		}
		if (S.empty()) ans++;
	}
	cout << ans << "\n";

	return 0;
}