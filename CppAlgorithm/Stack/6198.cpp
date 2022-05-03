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
		while (!building.empty() && building.top() <= height) // �� �� ���� ���� ����
			building.pop();
		result += building.size(); // ���� �� ��ŭ �� �� ����
		building.push(height);
	}
	cout << result;

	return 0;
}