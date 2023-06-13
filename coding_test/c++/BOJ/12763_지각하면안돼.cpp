#include <iostream>
#include <vector>
#include <queue>

#define INF 999999999

using namespace std;

struct node {
	int from, to, time, cost;
};

struct edge {
	int now, time, money;
};

bool operator<(edge a, edge b)
{
	if (a.time > b.time)
		return true;
	if (a.time < b.time)
		return false;
	if (a.money > b.money)
		return true;
	if (a.money < b.money)
		return false;
	return false;
}

vector <node> buildings[101];

int results[101];
int n; int t; int m; int l;

void dijk(int start) {

	priority_queue<edge> pq;
	pq.push({ start, 0, 0 });
	while (!pq.empty()) {
		edge now_node = pq.top();
		pq.pop();

		for (auto next_node : buildings[now_node.now]) {
			if (next_node.to == n) {
				if (now_node.time + next_node.time <= t && now_node.money + next_node.cost <= m) {
					results[next_node.to] = min(now_node.money + next_node.cost, results[next_node.to]);
				}
			}
			else {
				if (now_node.time + next_node.time < t && now_node.money + next_node.cost < m) {
					results[next_node.to] = min(results[next_node.to], now_node.money + next_node.cost);
					pq.push({ next_node.to, now_node.time + next_node.time, now_node.money + next_node.cost });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> t >> m >> l;

	for (int i = 0; i < l; i++) {
		int from, to, time, cost;
		cin >> from >> to >> time >> cost;
		buildings[from].push_back({ from, to, time, cost });
		buildings[to].push_back({ to, from, time, cost });
	}

	fill(results, results + 101, INF);

	dijk(1);
	if (results[n] == INF) cout << -1;
	else cout << results[n];
	return 0;
}