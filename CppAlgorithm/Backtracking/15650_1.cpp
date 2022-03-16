#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) arr.push_back(i < m ? 0 : 1);
	do {
		for (int i = 0; i < n; i++) {
			if (arr[i] == 0) cout << i + 1 << " ";
			cout << "\n";
		}
	} while (next_permutation(arr.begin(), arr.end()));

	return 0;
}