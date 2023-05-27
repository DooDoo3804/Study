#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	long long dp[31][3] = { 0 };
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;
	dp[2][0] = 3;
	dp[2][1] = 3;
	dp[2][2] = 3;
	for (int i = 3; i < 31; i++) {
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1] * 2;
		if (i % 2) {
			dp[i][2] = dp[(i - 1)/ 2][1];
		}
		else {
			dp[i][2] = dp[(i) / 2][1] + dp[(i - 2) / 2][1] * 2;
		}
		dp[i][0] = (dp[i][1] + dp[i][2]) / 2;
	}
	cout << dp[n][0];
	return 0;
}