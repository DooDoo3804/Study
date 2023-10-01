#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, l;
	cin >> n >> l;

	deque<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;

		while (!q.empty() && q.back().first > input) {
			q.pop_back();
		}
		q.push_back(make_pair(input, i));

		if (q.front().second < i + 1 - l) q.pop_front();
		cout << q.front().first << ' ';
	}



	return 0;
}