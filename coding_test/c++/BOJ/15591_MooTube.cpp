#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	struct Node {
		int from, to, cost;
	};

	vector<vector<Node>> nodes(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		nodes[from].push_back({ from, to, cost });
		nodes[to].push_back({ to, from, cost });
	}

	int visited[5001] = { 0 };

	for (int i = 0; i < q; i++) {
		int answer = 0;
		int k, v;
		cin >> k >> v;
		fill(visited, visited + 5001, 0);

		queue<Node> q;
		q.push({ v, v, k });
		visited[v] = 1;

		while (!q.empty()) {
			Node now = q.front();
			q.pop();

			for (Node next : nodes[now.from]) {
				if (visited[next.to] == 1) continue;
				if (next.cost < k) continue;
				answer++;
				visited[next.to] = 1;
				q.push({ next.to, next.to, k });
			}
		}
		cout << answer << '\n';
	}

	return 0;
}