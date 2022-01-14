#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "push") {
            int num;
            cin >> num;
            q.push(num);
        }
        else if (command == "pop") {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (command == "size") {
            cout << q.size() << '\n';
        }
        else if (command == "empty") {
            cout << q.empty() << '\n';
        }
        else if (command == "front") {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if (command == "back") {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }
}