#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long dp[65][10] = { 0 };

	for (int i = 1; i < 65; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 1) dp[i][j] = j + 1;
			else {
				for (int k = 0; k <= j; k++) {
					dp[i][j] += dp[i - 1][k];
				}
			}
		}
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int tc;
		cin >> tc;
		cout << dp[tc][9] << "\n";
	}

	return 0;
}