#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

int visited[1001] = { 0 };

void dfs(int v, vector<vector<int>> &nodes) {
	visited[v] = 1;
	cout << v << ' ';
	for (auto node : nodes[v]) {
		if (visited[node] == 0) dfs(node, nodes);
	}
}

void bfs(int v, vector<vector<int>> &nodes, queue<int> &q) {
	q.push(v);
	visited[v] = 1;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		cout << now << ' ';
		for (auto node : nodes[now]) {
			if (visited[node] == 0) {
				q.push(node);
				visited[node] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, v;
	cin >> n >> m >> v;

	vector<vector<int>> nodes(n + 1);
	queue<int> q;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		nodes[from].push_back(to);
		nodes[to].push_back(from);
	}

	for (int i = 0; i <= n; i++) {
		sort(nodes[i].begin(), nodes[i].end());
	}

	dfs(v, nodes);
	fill(visited, visited + 1001, 0);
	cout << '\n';
	bfs(v, nodes, q);

	return 0;
}