#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    int alpha[2][26] = {};
    int result = 0;
    for (char s : s1)
        alpha[0][s - 'a']++;
    for (char s : s2)
        alpha[1][s - 'a']++;
    for (int i = 0; i < 26; i++)
        result += abs(alpha[0][i] - alpha[1][i]);

    cout << result;
}