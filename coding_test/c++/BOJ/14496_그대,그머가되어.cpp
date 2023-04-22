#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 99999999

using namespace std;

vector<pair<int, int>> nodes[1001];

vector<int> dijkstra(int start, int N) {
	vector<int> dist(N, INF);
	priority_queue<pair<int, int>> pq;

	dist[start] = 0;
	pq.push({ 0, start });

	// 작은 것부터 다익스트라 적용하기 위해 -로 넣어준다
	while (!pq.empty()) {
		int now_dist = -pq.top().first;
		int now_node = pq.top().second;
		pq.pop();

		for (int i = 0; i < nodes[now_node].size(); i++) {
			int nxt_node = nodes[now_node][i].first;
			int nxt_dist = now_dist + nodes[now_node][i].second;

			if (nxt_dist < dist[nxt_node]) {
				dist[nxt_node] = nxt_dist;
				pq.push({ - nxt_dist, nxt_node });
			}

		}
	}
	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a; int b; int n; int m;
	cin >> a >> b >> n >> m;

	for (int i = 0; i < m; i++) {
		int x; int y;
		cin >> x >> y;
		nodes[x].push_back({ y, 1 });
		nodes[y].push_back({ x, 1 });
	}

	vector<int> dist = dijkstra(a, 1001);
	dist[b] != INF ? cout << dist[b] : cout << -1;
	return 0; 
}

