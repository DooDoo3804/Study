#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int prices[100001] = { 0 };
	for (int i = 1; i <= n; i++) {
		cin >> prices[i];
	}

	int dp[100001] = { 0 };

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + prices[j]);
		}
	}

	cout << dp[n];

	return 0;
}