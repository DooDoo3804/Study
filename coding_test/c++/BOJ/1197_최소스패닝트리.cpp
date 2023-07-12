#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int from, to;
	long long weight;
};

int find(vector<int>& parent, int x) {
	if (parent[x] != x) parent[x] = find(parent, parent[x]);
	return parent[x];
}

void merge(vector<int>& parent, vector<int>& rank, int u, int v) {
	u = find(parent, u);
	v = find(parent, v);
	if (rank[u] > rank[v]) swap(u, v);
	parent[u] = v;
	if (rank[u] == rank[v]) rank[v]++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int v; int e;
	cin >> v >> e;

	vector<Edge> edges;
	vector<int> parent(v + 1);
	vector<int> rank(v + 1);

	for (int i = 0; i < v; i++) {
		parent[i] = i;
		rank[i] = 1;
	}
	for (int i = 0; i < e; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		edges.push_back({ from, to, weight });
	}
	sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
		return a.weight < b.weight;
	});

	vector<Edge> result;
	for (auto& edge : edges) {
		int u = edge.from, v = edge.to, weight = edge.weight;
		if (find(parent, u) != find(parent, v)) {
			merge(parent, rank, u, v);
			result.push_back(edge);
		}
	}

	long long ans = 0;
	for (int i = 0; i < result.size(); i++) {
		ans += result[i].weight;
	}
	cout << ans;
	return 0;
}
