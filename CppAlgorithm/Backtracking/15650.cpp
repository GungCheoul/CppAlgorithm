#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

void func(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	int start = 1;
	if (cur != 0) start = arr[cur - 1] + 1;
	for (int i = start; i <= n; i++) {
		if (isused[i]) continue;
		arr[cur] = i;
		isused[i] = true;
		func(cur + 1);
		isused[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);

	return 0;
}