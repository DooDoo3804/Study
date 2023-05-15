#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	int s;
	int m;
	cin >> n >> s >> m;

	int dp[51][1001];
	fill(dp[0], dp[51], -1);

	dp[0][s] = 1;

	for (int i = 1; i < n + 1; i++) {
		int input;
		cin >> input;
		for (int j = 0; j <= m; j++) {
			if (dp[i - 1][j] == -1) continue;
			else {
				if (j + input <= m) dp[i][j + input] = 1;
				if (j - input >= 0) dp[i][j - input] = 1;
			}
		}
	}

	int ans = -1;

	for (int i = 0; i <= m; i++) {
		if (dp[n][i] == 1) ans = max(ans, i);
	}

	cout << ans;

	return 0;
}