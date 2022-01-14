#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int alpha[26] = {};
        string s1, s2;
        cin >> s1 >> s2;
        for (int i = 0; i < s1.length(); i++)
            alpha[s1[i] - 'a']++;
        for (int i = 0; i < s2.length(); i++)
            alpha[s2[i] - 'a']--;

        bool check = true;
        for (int i = 0; i < 26; i++) {
            if (alpha[i] != 0)
                check = false;
        }

        if (check)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}