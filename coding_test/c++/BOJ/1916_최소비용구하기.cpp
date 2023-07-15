#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
	int from; int to; int cost;
};

bool operator < (node a, node b) {
	return a.cost > b.cost;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	int m;
	cin >> n >> m;
	vector<node> nodes[1001];
	int dist[1001];
	fill(dist, dist + 1001, 2134567890);

	for (int i = 0; i < m; i++) {
		int from; int to; int cost;
		cin >> from >> to >> cost;
		nodes[from].push_back({ from, to, cost });
	}
	
	int s_node; int e_node;
	cin >> s_node >> e_node;

	priority_queue<node> pq;

	pq.push({ s_node, s_node, 0 });

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();
		if (now.from == e_node) {
			break;
		}
		for (auto next : nodes[now.from]) {
			if (next.cost + now.cost < dist[next.to]) {
				dist[next.to] = next.cost + now.cost;
				pq.push({ next.to, next.to, next.cost + now.cost });
			}
		}
	}

	cout << dist[e_node];
	return 0;
}