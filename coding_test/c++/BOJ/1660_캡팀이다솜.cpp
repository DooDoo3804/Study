#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n = 0;
	cin >> n;

	int dp[300001][3] = { 0 };
	int index = 0;

	while (dp[index][2] < n) {
		index++;
		dp[index][1] = dp[index - 1][1] + index;
		dp[index][2] = dp[index - 1][2] + dp[index][1];
		if (dp[index][2] > 300000) break;
		dp[dp[index][2]][0] = 1;
		for (int i = dp[index][2] + 1; i < n + 1; i++) {
			if (index == 1) dp[i][0] = dp[i - dp[index][2]][0] + 1;
			else dp[i][0] = min(dp[i][0], dp[i - dp[index][2]][0] + 1);
		}
	}
	cout << dp[n][0];
	return 0;
}
