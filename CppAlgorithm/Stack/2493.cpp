#include <iostream>
#include <stack>
using namespace std;

#define X first
#define Y second

int N;
stack<pair<int, int>> tower;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    tower.push({ 100000001, 0 });
    for (int i = 1; i <= N; i++) {
        int height;
        cin >> height;
        while (tower.top().X < height) // 수신 불가능 제거
            tower.pop();
        cout << tower.top().Y << " "; // 수신하는 수 출력
        tower.push({ height, i }); // 수신 개수도 저장
    }
}