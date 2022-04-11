/* 기본적인 quick sort 형식
int arr[8] = { 6, -8, 1, 12, 8, 3, 7, -7 };
int pivot = arr[0]; // 임의로 하나 설정
int l = 1, r = 7; // l->pivot보다 클 때, r->pivot보다 작을 때
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

// 재귀를 이용한 quick sort
void quick_sort(int st, int en) { // arr[st:en-1]을 정렬
	if (en <= st + 1) return; // 길이가 1이면 종료, base condition
	int pivot = arr[st]; // 제일 앞을 pivot으로 설정
	int l = st + 1; // 오른쪽으로 가는 l
	int r = en - 1; // 왼쪽으로 가는 r
	while (1) {
		while (l <= r && arr[l] <= pivot) l++;
		while (l <= r && arr[r] >= pivot) r--;
		if (l > r) break; // l과 r이 교차되는 순간 종료
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