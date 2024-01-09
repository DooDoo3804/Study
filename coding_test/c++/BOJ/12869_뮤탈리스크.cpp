#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> m(3, 0);
	for (int i = 0; i < n; i++) cin >> m[i];

	vector<vector<vector<int>>> dp(61, vector<vector<int>>(61, vector<int>(61, 2134567890)));
	dp[0][0][0] = 0;

	for (int i = 0; i <= m[0]; i++) {
		for (int j = 0; j <= m[1]; j++) {
			for (int k = 0; k <= m[2]; k++) {
				if (i == 0 && j == 0 && k == 0) continue;

				dp[i][j][k] = min(dp[i][j][k], 1 + dp[max(0, i - 9)][max(0, j - 3)][max(0, k - 1)]);
				dp[i][j][k] = min(dp[i][j][k], 1 + dp[max(0, i - 9)][max(0, j - 1)][max(0, k - 3)]);
				dp[i][j][k] = min(dp[i][j][k], 1 + dp[max(0, i - 3)][max(0, j - 9)][max(0, k - 1)]);
				dp[i][j][k] = min(dp[i][j][k], 1 + dp[max(0, i - 3)][max(0, j - 1)][max(0, k - 9)]);
				dp[i][j][k] = min(dp[i][j][k], 1 + dp[max(0, i - 1)][max(0, j - 3)][max(0, k - 9)]);
				dp[i][j][k] = min(dp[i][j][k], 1 + dp[max(0, i - 1)][max(0, j - 9)][max(0, k - 3)]);
			}
		}
	}

	cout << dp[m[0]][m[1]][m[2]];
	return 0;
}