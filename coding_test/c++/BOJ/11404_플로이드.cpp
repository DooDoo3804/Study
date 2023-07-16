#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2134567890

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; int m;
	cin >> n >> m;

	vector<vector<int>> nodes(n, vector<int>(n, INF));


	for (int i = 0; i < m; i++) {
		int from; int to; int cost;
		cin >> from >> to >> cost;
		nodes[from - 1][to - 1] = min(cost, nodes[from - 1][to - 1]);
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) nodes[i][j] = 0;
				else if (nodes[i][k] != INF && nodes[k][j] != INF && nodes[i][j] > nodes[i][k] + nodes[k][j]) nodes[i][j] = nodes[i][k] + nodes[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (nodes[i][j] == INF) cout << 0 << " ";
			else cout << nodes[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
