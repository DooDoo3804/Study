#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	stack <long long> q;
	long long ans = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		if (i == 0) q.push(input);
		else {
			if (q.top() <= input) {
				ans += input - q.top();
				q.pop();
				q.push(input);
			}
			else {
				q.push(input);
			}
		}
	}

	long long max_num = q.top();
	while (!q.empty()) {
		int num = q.top();
		q.pop();
		if (max_num < num) {
			ans += num - max_num;
			max_num = num;
		}
		else continue;
	}
	cout << ans;
	return 0;
}
