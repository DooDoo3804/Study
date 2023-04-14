#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue <int> q;

void qpush(int a) {
	q.push(a);
}

void qpop() {
	if (q.empty()) cout << -1 << "\n";
	else {
		cout << q.front() << "\n";
		q.pop();
	}
}

void qsize() {
	cout << q.size() << "\n";
}

void qempty() {
	if (q.empty()) cout << 1 << "\n";
	else cout << 0 << "\n";
}

void qfront() {
	if (q.empty()) cout << -1 << "\n";
	else cout << q.front() << "\n";
}

void qback() {
	if (q.empty()) cout << -1 << "\n";
	else cout << q.back() << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		if (input == "push") {
			int num;
			cin >> num;
			qpush(num);
		}
		else if (input == "front") qfront();
		else if (input == "back") qback();
		else if (input == "size") qsize();
		else if (input == "empty") qempty();
		else if (input == "pop") qpop();
	}
	return 0;
}