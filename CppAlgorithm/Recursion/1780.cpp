#include <iostream>
using namespace std;

int n;
int board[2200][2200];
int cnt[3];

bool check(int x, int y, int c) {
	for (int i = x; i < x + c; i++) {
		for (int j = y; j < y + c; j++) {
			if (board[x][y] != board[i][j]) return false;
		}
	}
	return true;
}

void func(int x, int y, int c) {
	if (check(x, y, c)) {
		cnt[board[x][y] + 1] += 1;
		return;
	}
	int third = c / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			func(x + i * third, y + j * third, third);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	}

	func(0, 0, n);
	for (int i = 0; i < 3; i++)
		cout << cnt[i] << "\n";

	return 0;
}