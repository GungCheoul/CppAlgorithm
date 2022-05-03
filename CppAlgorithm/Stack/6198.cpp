#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> building;
long long result;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N--) {
		long long height;
		cin >> height;
		while (!building.empty() && building.top() <= height) // 볼 수 없는 빌딩 제거
			building.pop();
		result += building.size(); // 남은 수 만큼 볼 수 있음
		building.push(height);
	}
	cout << result;

	return 0;
}