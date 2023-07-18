#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int from, to;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> parent(n + 1);
	vector<vector<Node>> nodes(n + 1);
	int visited[100001] = { 0 };

	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		nodes[from].push_back({ from, to });
		nodes[to].push_back({ to, from });
	}

	queue<Node> q;
	q.push({ 1, 1 });
	visited[1] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (auto& next : nodes[now.from]) {
			if (!visited[next.to]) {
				q.push({ next.to, next.to });
				parent[next.to] = next.from;
				visited[next.to] = 1;
			}
		}
	}

	for (int i = 2; i < n + 1; i++) {
		cout << parent[i] << "\n";
	}

	return 0;
}