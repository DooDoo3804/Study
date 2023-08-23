#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n; int m;
	cin >> n >> m;

	vector<vector<int>> nodes(n);
	
	int answer[10001] = { 0 };
	int visited[10001] = { 0 };
	int max_answer = 0;
	int sub_answer = 0;

	for (int i = 0; i < m; i++) {
		int a; int b;
		cin >> a >> b;
		nodes[b - 1].push_back(a - 1);
	}

	queue<int> q;

	for (int i = 1; i < n + 1; i++) {
		q = queue<int>();
		fill(visited, visited + 10001, 0);
		sub_answer = 0;

		q.push(i - 1);
		visited[i] = 1;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (auto node : nodes[now]) {
				int next = node;
				if (!visited[next + 1]) {
					sub_answer++;
					visited[next + 1] = 1;
					q.push(next);
				}
			}
		}

		answer[i] = sub_answer;
		max_answer = max(max_answer, sub_answer);
	}

	for (int i = 1; i < n + 1; i++) {
		if (answer[i] == max_answer) cout << i << " ";
	}

	return 0;
}