/* �⺻���� quick sort ����
int arr[8] = { 6, -8, 1, 12, 8, 3, 7, -7 };
int pivot = arr[0]; // ���Ƿ� �ϳ� ����
int l = 1, r = 7; // l->pivot���� Ŭ ��, r->pivot���� ���� ��
while (1) {
	while (l <= r && arr[l] <= pivot) l++;
	while (l <= r && arr[r] > pivot) r--;
	if (l > r) break;
	swap(arr[l], arr[r]);
}
swap(arr[0], arr[r]);
*/

#include <iostream>
using namespace std;

int n = 10;
int arr[1000001] = { 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };

// ��͸� �̿��� quick sort
void quick_sort(int st, int en) { // arr[st:en-1]�� ����
	if (en <= st + 1) return; // ���̰� 1�̸� ����, base condition
	int pivot = arr[st]; // ���� ���� pivot���� ����
	int l = st + 1; // ���������� ���� l
	int r = en - 1; // �������� ���� r
	while (1) {
		while (l <= r && arr[l] <= pivot) l++;
		while (l <= r && arr[r] >= pivot) r--;
		if (l > r) break; // l�� r�� �����Ǵ� ���� ����
		swap(arr[l], arr[r]);
	}
	swap(arr[st], arr[r]);
	quick_sort(st, r);
	quick_sort(r + 1, en);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	quick_sort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';

	return 0;
}