#include <iostream>
using namespace std;

int n = 10;
int arr[1000001] = { 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };
int tmp[1000001]; // 병합 결과 임시로 저장할 배열

void merge(int st, int en) {
	int mid = (st + en) / 2;
	// arr[st:mid], arr[mid:en]은 이미 정렬된 상태일 때,
	// arr[st:mid]와 arr[mid:en]을 합치는 과정
	int lidx = st;
	int ridx = mid;
	for (int i = st; i < en; i++) {
		if (ridx == en) tmp[i] = arr[lidx++];
		else if (lidx == mid) tmp[i] = arr[ridx++];
		else if (arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
		else tmp[i] = arr[ridx++];
	}
	for (int i = st; i < en; i++) arr[i] = tmp[i];
}

void merge_sort(int st, int en) { // arr[st:en]을 정렬
	if (en == st + 1) return; // 길이가 1인 경우
	int mid = (st + en) / 2;
	merge_sort(st, mid); // arr[st:mid] 정렬
	merge_sort(mid, st); // arr[mid:en] 정렬
	merge(st, en); // arr[st:mid], arr[mid:en] 병합
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	merge_sort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';

	return 0;
}