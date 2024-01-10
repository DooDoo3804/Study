#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

int total_map[7][8];
int dp[7][8][3] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> total_map[i + 1][j + 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1) dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = total_map[i][j];
			else {
				if (j != 1) dp[i][j][2] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + total_map[i][j];
				if (j != m) dp[i][j][0] = min(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]) + total_map[i][j];
				
				if (dp[i - 1][j][0] == 0) dp[i][j][1] = dp[i - 1][j][2] + total_map[i][j];
				else if (dp[i - 1][j][2] == 0) dp[i][j][1] = dp[i - 1][j][0] + total_map[i][j];
				else dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + total_map[i][j];
			}
		}
	}

	int answer = 2134567890;

	for (int i = 1; i <= m; i++)
		for (int j = 0; j < 3; j++)
			if (dp[n][i][j] != 0) answer = min(answer, dp[n][i][j]);

	cout << answer;

	return 0;
}