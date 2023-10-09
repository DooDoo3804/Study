#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> bags(n + 1);
	for (int i = 1; i <= n; i++) {
		int w, v;
		cin >> w >> v;
		bags[i] = make_pair(w, v);
	}

	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (bags[i].first > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], bags[i].second + dp[i - 1][j - bags[i].first]);
			}
		}
	}

	cout << dp[n][k];
	return 0;
}