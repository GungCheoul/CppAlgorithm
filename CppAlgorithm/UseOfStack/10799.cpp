#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;
    stack<char> s;
    int stick = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(' && input[i + 1] == ')') {
            stick += s.size();
            i++;
        }
        else if (input[i] == '(') {
            s.push(input[i]);
            stick++;
        }
        else if (input[i] == ')') {
            s.pop();
        }
    }
    cout << stick;
}