#include <iostream>
using namespace std;

int n;
int board[64][64];

void func(int z, int y, int x) {
	if (z == 1) {
		cout << board[y][x];
		return;
	}
	bool zero = true, one = true;
	for (int i = y; i < y + z; i++) {
		for (int j = x; j < x + z; j++) {
			if (board[i][j]) zero = false;
			else one = false;
		}
	}
	if (zero) cout << 0;
	else if (one) cout << 1;
	else {
		cout << "(";
		func(z / 2, y, x);
		func(z / 2, y, x + z / 2);
		func(z / 2, y + z / 2, x);
		func(z / 2, y + z / 2, x + z / 2);
		cout << ")";
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
			board[i][j] = str[j] - '0';
	}
	func(n, 0, 0);

	return 0;
}