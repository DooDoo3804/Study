#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int dp[21] = { 0 };

	int n; int k;
	cin >> n >> k;

	int foods[101] = { 0 };

	for (int i = 1; i < n + 1; i++) {
		cin >> foods[i];
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j <= i; j++) {
			int index = 0;
			int sub_dp = dp[j - 1];
			int sub_sum = 0;

			while (sub_sum < k && j + index <= i) {
				sub_sum += foods[j + index];

				if (sub_sum >= k) {
					dp[i] = max(dp[i], sub_dp + sub_sum - k);
					break;
				}
				index++;
			}
		}
	}
	cout << dp[n];
	return 0;
}