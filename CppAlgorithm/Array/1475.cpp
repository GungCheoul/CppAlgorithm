#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int count = 1;
    int num[10] = {};
    int n;
    cin >> n;
    while (n > 0) {
        num[n % 10]++;
        n /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9)
            continue;
        count = max(count, num[i]);
    }
    count = max(count, (num[6] + num[9] + 1) / 2);
    cout << count;
}