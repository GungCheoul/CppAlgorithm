#include <iostream>
using namespace std;

int n;
char board[3076][3076];

void star(const int &x, const int &y) {
	board[x][y] = '*';
	board[x + 1][y - 1] = '*';
	board[x + 1][y + 1] = '*';
	for (int i = y - 2; i <= y + 2; i++)
		board[x + 2][i] = '*';
}

void func(const int &z, const int &x, const int &y) {
	if (z == 3) {
		star(x, y);
		return;
	}
	func(z / 2, x, y);
	func(z / 2, x + z / 2, y - z / 2);
	func(z / 2, x + z / 2, y + z / 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		fill(board[i], board[i] + n, ' ');

	func(n, 0, n-1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2 - 1; j++) {
			if (board[i][j] == '*')
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}