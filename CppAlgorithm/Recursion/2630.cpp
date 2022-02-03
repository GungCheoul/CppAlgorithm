#include <iostream>
using namespace std;

int n;
int board[129][129];
int cnt[2];

bool check(int x, int y, int z) {
	for (int i = x; i < x + z; i++) {
		for (int j = y; j < y + z; j++) {
			if (board[x][y] != board[i][j]) return false;
		}
	}
	return true;
}

void func(int x, int y, int z) {
	if (check(x, y, z)) {
		cnt[board[x][y]] += 1;
		return;
	}
	int half = z / 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			func(x + i * half, y + j * half, half);
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
	
	for (int i = 0; i < 2; i++) cout << cnt[i] << "\n";

	return 0;
}