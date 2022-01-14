#include <iostream>
using namespace std;

int main() {
    int num[100] = {};
    int check[201] = {};
    int n, v;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    cin >> v;

    for (int i = 0; i < n; i++) {
        if (num[i] >= 0)
            check[num[i]]++;
        else
            check[100 - num[i]]++;
    }
    if (v >= 0)
        cout << check[v];
    else
        cout << check[100 - v];
}