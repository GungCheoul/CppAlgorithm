#include <iostream>
using namespace std;

int n, s, cnt = 0;
int arr[30];

void func(int cur, int sum) {
	if (cur == n) { // sum = s, cnt++
		if (sum == s) cnt++;
		return;
	}
	func(cur + 1, sum);
	func(cur + 1, sum + arr[cur]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	func(0, 0);
	if (s == 0) cnt--;
	cout << cnt;

	return 0;
}