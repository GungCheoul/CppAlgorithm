#include <iostream>
#include <stack>
using namespace std;

int a[1000000];
int ans[1000000];
int N;
stack<int> S;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = N - 1; i >= 0; i--) {
		while (!S.empty() && S.top() <= a[i]) // while문을 통해 반복적 stack값 비교
			S.pop();
		if (S.empty())
			ans[i] = -1;
		else
			ans[i] = S.top();
		S.push(a[i]);
	}
	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
	
	return 0;
}

/*
* Base logic
* while(!stack.empty() && stack.top() <= (number to check))
*	stack.pop()
* stack.push(number)
*/