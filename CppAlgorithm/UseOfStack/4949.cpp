#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        string sen;
        getline(cin, sen);
        if (sen == ".") break;

        stack<char> comb;
        bool isValid = true;
        for (int i = 0; i < sen.length(); i++) {
            if (sen[i] == '(' || sen[i] == '[') {
                comb.push(sen[i]);
            }
            else if (sen[i] == ')') {
                if (comb.empty() || comb.top() != '(') {
                    isValid = false;
                    break;
                }
                if (comb.top() == '(') comb.pop();
            }
            else if (sen[i] == ']') {
                if (comb.empty() || comb.top() != '[') {
                    isValid = false;
                    break;
                }
                if (comb.top() == '[') comb.pop();
            }
        }
        if (!comb.empty()) isValid = false;
        if (isValid) cout << "yes\n";
        else cout << "no\n";
    }
}