#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool isUsed[10];

void func(int k) {
	if (k == m) {
		// ��� ĭ�� á�� ��(Ʈ�� ���� ������ ��忡 ����)
		// m�� ��ŭ �� �ٿ� ���
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	// 1���� n���� �ݺ�
	for (int i = 1; i <= n; i++) {
		if (!isUsed[i]) { // ������ ���� ���
			arr[k] = i; // �ε����� i�� ����
			isUsed[i] = true; // i�� ��� ǥ��
			func(k + 1); // ����, +1 �Լ� ����
			isUsed[i] = false; // ���� ���� �ε��� �ʱ�ȭ
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