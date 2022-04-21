#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> table, result;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		table.push_back(i);

	for (int i = 0; result.size() < N; i++) {
		// until every people eliminate(result size=N)
		if (i % K == K - 1) result.push_back(table[i]); // eliminate Kth person
		else table.push_back(table[i]); // make circle(1, 2, 3, 1, 2, ...)
		// person who is not according to Kth, insert to main table
	}

	cout << "<"; // printing format
	for (int i = 0; i < N; i++) {
		if (i == N - 1) cout << result[i];
		else cout << result[i] << ", ";
	}
	cout << ">";
	
	return 0;
}