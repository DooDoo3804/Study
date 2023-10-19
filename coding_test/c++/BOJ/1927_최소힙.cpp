#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	priority_queue<int> q;
	while (n--) {
		int input;
		cin >> input;
		if (input == 0) {
			if (q.empty()) cout << 0 << '\n';
			else {
				int now = q.top();
				q.pop();
				cout << -now << '\n';
			}
		}
		else {
			q.push(-input);
		}
	}

	return 0;
}