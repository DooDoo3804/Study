#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int indegree[501] = { 0 };
	int times[501] = { 0 };
	int answer[501] = { 0 };

	vector<vector<int>> nodes(n + 1);

	for (int i = 1; i <= n; i++) {
		int time;
		cin >> time;
		times[i] = time;

		int input;
		while (cin >> input) {
			if (input == -1) break;
			indegree[i]++;
			nodes[input].push_back(i);
		}
	}
	queue<int> q;

	for (int i = 1; i <= n; i++) if (!indegree[i]) {
		q.push(i);
		answer[i] = times[i];
	}

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		for (auto next : nodes[now]) {
			answer[next] = max(answer[next], answer[now]);
			if (--indegree[next] == 0) {
				q.push(next);
				answer[next] += times[next];
			}
		}
	}
	
	for (int i = 1; i <= n; i++) cout << answer[i] << '\n';
	return 0;
}