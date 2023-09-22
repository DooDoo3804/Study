#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;
int result[10001];
int indegree[10001];
int dist[10001];
vector<vector<pair<int, int>>> graph(10001);

void t_sort() {
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			result[i] = dist[i];
			q.push({ i, result[i] });
		}
	}
	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		for (auto next : graph[now.first]) {
			result[next.first] = max(result[next.first], now.second + next.second);

			if (--indegree[next.first] == 0) q.push({ next.first, result[next.first] });

		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i < n + 1; i++) {
		int t, node;
		cin >> t >> node;
		for (int j = 0; j < node; j++) {
			int input;
			cin >> input;
			graph[input].push_back(make_pair(i, t));
			
		}
		indegree[i] = node;
		dist[i] = t;
	}

	t_sort();

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer = max(answer, result[i]);
	}
	cout << answer;
	return 0;
}