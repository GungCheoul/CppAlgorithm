#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool isUsed[10];

void func(int k) {
	if (k == m) {
		// 모든 칸이 찼을 때(트리 기준 마지막 노드에 도달)
		// m개 만큼 한 줄에 출력
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	// 1부터 n까지 반복
	for (int i = 1; i <= n; i++) {
		if (!isUsed[i]) { // 쓰이지 않은 경우
			arr[k] = i; // 인덱스에 i값 저장
			isUsed[i] = true; // i값 사용 표시
			func(k + 1); // 다음, +1 함수 실행
			isUsed[i] = false; // 들어갔다 나온 인덱스 초기화
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);

	return 0;
}