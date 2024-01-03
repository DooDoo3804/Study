#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

int moves[4][2] = { {0, 1}, {0,-1}, {1,0}, {-1, 0} };
int total_map[501][501];
int dp[501][501];
int answer;
int m; int n;

int dfs(int x, int y) {

	if (dp[x][y] != -1) return dp[x][y];

	if (x == n - 1 && y == m - 1) return 1;

	dp[x][y] = 0;
	int now = total_map[x][y];

	for (auto move : moves) {
		int next_x = x + move[0];
		int next_y = y + move[1];

		if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;

		if (now > total_map[next_x][next_y]) dp[x][y] += dfs(next_x, next_y);
	}

	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> total_map[i][j];
		}
	}

	for (int i = 0; i < 501; i++) fill(dp[i], dp[i] + 501, -1);

	answer = dfs(0, 0);
	
	cout << answer;

	return 0;
}