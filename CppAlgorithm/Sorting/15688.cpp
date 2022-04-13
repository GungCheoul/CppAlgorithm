#include <iostream>
using namespace std;

int freq[2000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) { // counting sort, 임의의 큰 배열에 각 수의 사용 횟수를 저장
		int a;
		cin >> a;
		freq[a + 1000000]++;
	}
	for (int i = 0; i <= 2000000; i++) { // 각 수(작은 순서로)를 횟수만큼 출력->오름차순 정렬 완료
		while (freq[i]--)
			cout << i - 1000000 << '\n';
	}

	return 0;
}