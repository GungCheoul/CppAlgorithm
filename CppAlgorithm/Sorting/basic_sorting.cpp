#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[10] = { 3, 2, 7, 116, 62, 235, 1, 23, 55, 77 };
	int n = 10;
	for (int i = n - 1; i > 0; i--) { // 기초적인 방법
		int mxidx = 0;
		for (int j = 1; j <= i; i++) {
			if (arr[mxidx] < arr[j]) mxidx = j;
		}
		swap(arr[mxidx], arr[i]);
	}

	for (int i = n - 1; i > 0; i--) // 알고리즘 사용
		swap(*max_element(arr, arr + i + 1), arr[i]);

	int arr[5] = { -2, 2, 4, 6, 13 };
	int n = 5;
	for (int i = 0; i < n; i++) { // bubble sort
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}

	return 0;
}