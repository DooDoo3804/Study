#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int dp[21][2];
	int energy[21][2];

	for (int i = 0; i < 21; i++) fill(dp[i], dp[i] + 2, 2134567890);
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = 0;

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		energy[i][0] = a;
		energy[i][1] = b;
	}

	int k = 0;
	cin >> k;

	for (int i = 1; i <= n; i++) {
		if (dp[i][1] != 2134567890) {
			if (i + 1 <= n) dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + energy[i][0]);
			if (i + 2 <= n) dp[i + 2][1] = min(dp[i + 2][1], dp[i][1] + energy[i][1]);
		}
		if (i + 1 <= n) dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + energy[i][0]);
		if (i + 2 <= n) dp[i + 2][0] = min(dp[i + 2][0], dp[i][0] + energy[i][1]);
		if (i + 3 <= n) dp[i + 3][1] = min(dp[i + 3][1], dp[i][0] + k);
	}

	cout << min(dp[n][0], dp[n][1]);
	return 0;
}