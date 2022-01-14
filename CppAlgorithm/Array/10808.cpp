#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (char a = 'a'; a <= 'z'; a++) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (a == s[i])
                count++;
        }
        cout << count << ' ';
    }
    return 0;
}