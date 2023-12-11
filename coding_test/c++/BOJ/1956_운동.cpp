#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

#define INF 2134567890

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int v, e;
	cin >> v >> e;

	vector<vector<int>> nodes(v + 1, vector<int>(v + 1, INF));

	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		nodes[from][to] = cost;
	}

	for (int k = 1; k < v + 1; k++) {
		for (int i = 1; i < v + 1; i++) {
			for (int j = 1; j < v + 1; j++) {
				if (nodes[i][k] != INF && nodes[k][j] != INF && nodes[i][j] > nodes[i][k] + nodes[k][j]) {
					nodes[i][j] = nodes[i][k] + nodes[k][j];
				}
			}
		}
	}

	int answer = INF;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i != j) continue;
			answer = min(answer, nodes[i][j]);
		}
	}

	answer = (answer == INF) ? -1 : answer;

	cout << answer;

	return 0;
}