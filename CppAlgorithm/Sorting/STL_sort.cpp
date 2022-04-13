#include <iostream>
#include <vector>
#include <algorithm> // sort 함수 사용
using namespace std;

bool cmp(int a, int b) { // 5로 나눈 나머지 순으로 정렬
	if (a % 5 != b % 5) return a % 5 < b % 5;
	return a < b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[5] = { 1, 4, 5, 2, 7 };
	sort(a, a + 5);

	vector<int> b = { 1, 4, 5, 2, 7 };
	sort(b.begin(), b.end());

	int a2[7] = { 1, 2, 3, 4, 5, 6, 7 };
	sort(a2, a2 + 7, cmp); // 5, 1, 6, 2, 7, 3, 4

	return 0;
}