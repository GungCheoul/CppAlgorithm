#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
int num[10];

void func(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	int s = 0;
	for (int i = 0; i < n; i++) {
		if (s == num[i]) continue;
		arr[cur] = num[i];
		s = arr[cur];
		func(cur + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	func(0);

	return 0;
}