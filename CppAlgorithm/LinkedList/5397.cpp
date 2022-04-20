#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string L;
		cin >> L;
		list<char> pw; // result string
		auto cursor = pw.begin(); // cursor start
		for (auto k : L) {
			if (k == '<') {
				if (cursor != pw.begin())
					cursor--;
			}
			else if (k == '>') {
				if (cursor != pw.end())
					cursor++;
			}
			else if (k == '-') {
				if (cursor != pw.begin()) {
					cursor--;
					cursor = pw.erase(cursor);
					// important
					// after erase, cannot use the used iterator
					// if wanna use after erasing,
					// should save the return value of erase again
				}
			}
			else pw.insert(cursor, k);
		}
		for (auto k : pw)
				cout << k;
		cout << '\n';
	}
	
	return 0;
}