#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;

	int dp[10001] = { 0 };

	while (t--) {
		int n;
		cin >> n;
		fill(dp, dp + 10001, 0);
		dp[0] = 1;

		for (int i = 0; i < n; i++) {
			int coin;
			cin >> coin;
			for (int j = coin; j <= 10000; j++) {
				dp[j] += dp[j - coin];
			}
		}
		int answer;
		cin >> answer;
		cout << dp[answer] << "\n";
	}

	return 0;
}