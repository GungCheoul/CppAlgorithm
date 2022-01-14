#include <iostream>
#include <list>
using namespace std;

int main(void) {
    int n;
    string input = "";
    cin >> input;
    list<char> str;
    list<char>::iterator cursor = str.end();
    for (int i = 0; i < input.length(); i++)
        str.push_back(input[i]);

    cin >> n;
    for (int i = 0; i < n; i++) {
        char m;
        cin >> m;
        if (m == 'L') {
            if (cursor != str.begin()) cursor--;
        }
        else if (m == 'D') {
            if (cursor != str.end()) cursor++;
        }
        else if (m == 'B') {
            if (cursor != str.begin()) {
                cursor--;
                cursor = str.erase(cursor);
            }
        }
        else if (m == 'P') {
            char c;
            cin >> c;
            str.insert(cursor, c);
        }
    }
    for (auto c : str) cout << c;
}