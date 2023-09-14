#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;

	int total_map[501][501];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> total_map[i][j];
		}
	}

	int dist[501][501] = { 0 };
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (total_map[i][k] + total_map[k][j] < total_map[i][j]) {
					total_map[i][j] = total_map[i][k] + total_map[k][j];
				}
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		string output = "Enjoy other party";
		if (total_map[a][b] > c) output = "Stay here";
		cout << output << '\n';
	}

	return 0;
}