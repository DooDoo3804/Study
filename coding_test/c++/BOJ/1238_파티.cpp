#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct node{
	int from; int to; int cost;
};

bool operator < (node a, node b) {
	return a.cost > b.cost;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; int m; int x;
	cin >> n >> m >> x;

	vector<node> go_nodes[1001];
	vector<node> back_nodes[1001];

	int go_time[1001];
	int back_time[1001];

	fill(go_time, go_time + 1001, 2134567890);
	fill(back_time, back_time + 1001, 2134567890);

	for (int i = 0; i < m; i++) {
		int from; int to; int cost;
		cin >> from >> to >> cost;
		go_nodes[to].push_back({ to, from, cost });
		back_nodes[from].push_back({ from, to, cost });
	}

	priority_queue<node> go_pq;
	priority_queue<node> back_pq;
	go_pq.push({ x, x, 0 });
	back_pq.push({ x, x, 0 });

	while (!go_pq.empty()) {
		node now = go_pq.top();
		go_pq.pop();
		for (auto next_node : go_nodes[now.from]) {
			if (go_time[next_node.to] > next_node.cost + now.cost) {
				go_time[next_node.to] = next_node.cost + now.cost;
				go_pq.push({ next_node.to, next_node.to, go_time[next_node.to] });
			}
		}
	}

	while (!back_pq.empty()) {
		node now = back_pq.top();
		back_pq.pop();
		for (auto next_node : back_nodes[now.from]) {
			if (back_time[next_node.to] > next_node.cost + now.cost) {
				back_time[next_node.to] = next_node.cost + now.cost;
				back_pq.push({ next_node.to, next_node.to, back_time[next_node.to] });
			}
		}
	}

	go_time[x] = 0;
	back_time[x] = 0;

	int answer = 0;

	for (int i = 1; i < n + 1; i++) {
		answer = max(answer, go_time[i] + back_time[i]);
	}
	cout << answer;

	return 0;
}