#include <iostream>
#include <deque>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> dq;
    int n;
    cin >> n;
    while (n--) {
        string command;
        cin >> command;
        if (command == "push_front") {
            int num;
            cin >> num;
            dq.push_front(num);
        }
        else if (command == "push_back") {
            int num;
            cin >> num;
            dq.push_back(num);
        }
        else if (command == "pop_front") {
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (command == "pop_back") {
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (command == "size") {
            cout << dq.size() << '\n';
        }
        else if (command == "empty") {
            cout << dq.empty() << '\n';
        }
        else if (command == "front") {
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        }
        else if (command == "back") {
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }
    }
}