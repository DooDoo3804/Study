#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

#define INF 2134567890

using namespace std;

struct node {
	int from, to, cost;
};

vector<vector<node>> nodes;
int dist[501];

bool isPossible(int n, int start) {

	if (dist[start] == INF) dist[start] = 0;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j <= n; j++) {
			for (auto next : nodes[j]) {
				int f = next.from;
				int t = next.to;
				int c = next.cost;
				if (dist[f] != INF && dist[f] + c < dist[t]) {
					dist[t] = dist[f] + c;
				}
			}
		}
	}

	for (int j = 1; j <= n; j++) {
		for (auto next : nodes[j]) {
			int f = next.from;
			int t = next.to;
			int c = next.cost;
			if (dist[f] != INF && dist[f] + c < dist[t]) {
				return true;
			}
		}
	}
	return false;
}

bool isPossibleAll(int n) {
	for (int i = 1; i <= n; i++) {
		if (dist[i] != INF) continue;
		if (isPossible(n, i)) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	
	while (t--) {
		int n; int m; int w;
		cin >> n >> m >> w;
		nodes = vector<vector<node>>(n + 1);
		fill(dist, dist + 501, INF);

		for (int i = 0; i < m; i++) {
			int s; int e; int t;
			cin >> s >> e >> t;
			nodes[s].push_back({ s, e, t });
			nodes[e].push_back({ e, s, t });
		}
		for (int i = 0; i < w; i++) {
			int s; int e; int t;
			cin >> s >> e >> t;
			nodes[s].push_back({ s, e, -t });
		}

		if (isPossibleAll(n)) cout << "YES" << '\n';
		else cout << "NO" << '\n';


	}
	return 0;
}