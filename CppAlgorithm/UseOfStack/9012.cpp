#include <iostream>
#include <stack>
#include <string>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N--) {
		string a;
		cin >> a;
		stack<char> S;
		bool valid = true;
		for (auto s : a) {
			if (s == '(')
				S.push(s);
			else {
				if (S.empty() || S.top() != '(') {
					valid = false;
					break;
				}
				S.pop();
			}
		}
		if (!S.empty()) valid = false;
		if (valid) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}