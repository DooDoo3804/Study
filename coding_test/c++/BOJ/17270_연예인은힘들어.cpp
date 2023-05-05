#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 999999999

struct node {
	int to, cost;
};

bool operator<(node a, node b) {
	return a.cost > b.cost;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<node> nodes[101];

	int v; int m;
	cin >> v >> m;

	for (int i = 0; i < m; i++) {
		int from; int to; int cost;
		cin >> from >> to >> cost;
		nodes[from].push_back({ to, cost });
		nodes[to].push_back({ from, cost });
	}

	int j; int s;
	cin >> j >> s;

	int visited[101][2];
	fill(visited[0], visited[101], INF);
	visited[j][0] = 0;
	visited[s][1] = 0;

	priority_queue<node> pq;
	pq.push({ j, 0 });
	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();
		for (auto next_node : nodes[now.to]) {
			if (next_node.to == j) continue;
			if (visited[next_node.to][0] > now.cost + next_node.cost) {
				visited[next_node.to][0] = now.cost + next_node.cost;
				pq.push({ next_node.to, now.cost + next_node.cost });
			}
		}
	}

	pq = priority_queue<node>();
	pq.push({ s, 0 });
	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();
		for (auto next_node : nodes[now.to]) {
			if (next_node.to == s) continue;
			if (visited[next_node.to][1] > now.cost + next_node.cost) {
				visited[next_node.to][1] = now.cost + next_node.cost;
				pq.push({ next_node.to, now.cost + next_node.cost });
			}
		}
	}

	int min_dis = INF;
	for (int i = 0; i < v + 1; i++) {
		if (i == j || i == s) continue;
		if (min_dis > visited[i][0] + visited[i][1]) {
			min_dis = visited[i][0] + visited[i][1];
		}
	}

	int result[3] = { 0 };
	result[0] = min_dis;
	result[1] = INF;
	result[2] = -1;

	for (int i = 1; i < v + 1; i++) {
		if (i == j || i == s) continue;
		if (visited[i][0] + visited[i][1] > result[0]) continue;
		if (visited[i][0] - visited[i][1] <= 0 && visited[i][0] - visited[i][1] < result[1]) {
			result[1] = visited[i][0] - visited[i][1];
			result[2] = i;
		}

	}

	if (result[1] > 0) cout << -1;
	else cout << result[2];

	return 0;
}