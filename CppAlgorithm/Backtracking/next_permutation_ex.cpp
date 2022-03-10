#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[3] = { 1, 2, 3 };
	do {
		for (int i = 0; i < 3; i++)
			cout << a[i];
		cout << '\n';
	} while (next_permutation(a, a + 3));
	/*
	123
	132
	213
	231
	312
	321
	*/

	return 0;
}