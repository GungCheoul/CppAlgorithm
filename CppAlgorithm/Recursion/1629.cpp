#include <iostream>
using namespace std;

#define LL long long

LL mul(LL a, LL b, LL c) {
	if (b == 1) return a % c;
	LL result = mul(a, b / 2, c);
	result = result * result % c;
	if (b % 2 == 0) return result;
	return result * a % c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	LL a, b, c;
	cin >> a >> b >> c;

	cout << mul(a, b, c);
}