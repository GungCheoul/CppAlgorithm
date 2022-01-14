#include <iostream>
using namespace std;

int n, k, rcount = 0;
int room[2][7] = {};
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int m, w;
        cin >> m >> w;
        room[m][w]++;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < 7; j++) {
            rcount += room[i][j] / k;
            if (room[i][j] % k)
                rcount++;
        }
    }

    cout << rcount;
}