#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string S;
    cin >> S;
    stack<char> B;

    int tmp = 1;
    int result = 0;
    bool fail = false;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(') {
            B.push(S[i]);
            tmp *= 2;
        }
        else if (S[i] == ')') {
            if (B.empty() || B.top() != '(') {
                fail = true;
                break;
            }
            else {
                if (S[i - 1] == '(')
                    result += tmp;
                B.pop();
                tmp /= 2;
            }
        }
        else if (S[i] == '[') {
            B.push(S[i]);
            tmp *= 3;
        }
        else if (S[i] == ']') {
            if (B.empty() || B.top() != '[') {
                fail = true;
                break;
            }
            else {
                if (S[i - 1] == '[')
                    result += tmp;
                B.pop();
                tmp /= 3;
            }
        }
    }
    if (fail == true || !B.empty())
        cout << '0' << endl;
    else
        cout << result << endl;

    return 0;
}
