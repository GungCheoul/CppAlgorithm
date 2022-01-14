#include <iostream>
using namespace std;

int num[10];
int pos[9];
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int result = a * b * c;
    int i = 0;
    while (result / 10 != 0) {
        pos[i] = result % 10;
        result /= 10;
        i++;
    }
    pos[i] = result;
    for (int k = 0; k < i + 1; k++)
        num[pos[k]]++;
    for (int k = 0; k < 10; k++)
        cout << num[k] << "\n";
}