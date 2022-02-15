#include <iostream>
using namespace std;

int n;
char board[6561][6561];

void func(int i, int x, int y) {
	if (i == 1) {
		board[x][y] = '*';
		return;
	}
	for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 3; k++) {
			if (j == 1 && k == 1) continue;
			func(i / 3, x + i / 3 * j, y + i / 3 * k);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		fill(board[i], board[i] + n, ' ');

	func(n, 0, 0);
	for (int i = 0; i < n; i++)
		cout << board[i] << '\n';

	return 0;
}