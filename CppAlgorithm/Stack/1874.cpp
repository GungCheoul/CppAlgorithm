#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;
    stack<int> S;
    int cnt = 1; // current num to push
    string ans;
    while (n--) {
        int t;
        cin >> t;
        while (cnt <= t) {
            S.push(cnt++);
            ans += "+\n";
        }
        if (S.top() != t) { // not matching with given sequence
            cout << "NO\n";
            return 0;
        }
        S.pop(); // pop to make sequence
        ans += "-\n";
    }
    cout << ans;

	return 0;
}