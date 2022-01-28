#include <iostream>
using namespace std;

int n;

void underbar(const char* str, int stk) {
	for (int j = 0; j < stk; j++) cout << "____";
	cout << str;
}

void func(int cnt) {
	underbar("\"����Լ��� ������?\"\n", cnt);
	if (cnt == n) underbar("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n", cnt);
	else {
		underbar("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n", cnt);
		underbar("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n", cnt);
		underbar("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n", cnt);
		func(cnt + 1);
	}
	underbar("��� �亯�Ͽ���.\n", cnt);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	func(0);

	return 0;
}