#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num[1000001] = {};
    int check[2000001] = {};
    int count = 0;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    cin >> x;

    for (int i = 0; i < n; i++) {
        if (x - num[i] > 0 && check[x - num[i]] == 1)
            count++;
        check[num[i]] = 1;
    }
    cout << count;
}