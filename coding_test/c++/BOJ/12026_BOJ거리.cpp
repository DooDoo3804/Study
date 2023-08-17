#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int dp[1001] = { 0 };
	int type[1001] = { 0 };

	fill(dp, dp + 1001, 2134567890);

	string input;
	cin >> input;
	
	for (int i = 0; i < n; i++) {
		if (input[i] == 'B') type[i + 1] = 0;
		else if (input[i] == 'O') type[i + 1] = 1;
		else if (input[i] == 'J') type[i + 1] = 2;
	}

	for (int i = 1; i < input.size() + 1; i++) {
		if (i == 1) dp[i] = 0;
		else if (type[i] == 0) {
			for (int j = i - 1; j > 0; j--) {
				if (type[j] == 2) {
					dp[i] = min(dp[j] + (j - i) * (j - i), dp[i]);
				}
			}
		}
		else if (type[i] == 1) {
			for (int j = i - 1; j > 0; j--) {
				if (type[j] == 0) {
					dp[i] = min(dp[j] + (j - i) * (j - i), dp[i]);
				}
			}
		}
		else if (type[i] == 2) {
			for (int j = i - 1; j > 0; j--) {
				if (type[j] == 1) {
					dp[i] = min(dp[j] + (j - i) * (j - i), dp[i]);
				}
			}
		}
	}

	if (dp[n] == 2134567890) cout << -1;
	else cout << dp[n];
	return 0;
}