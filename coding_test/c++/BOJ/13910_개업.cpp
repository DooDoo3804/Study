#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; int m;
	cin >> n >> m;

	int dp[10001] = { 0 };
	int check[22222] = { 0 };

	int works[101] = { 0 };
	for (int i = 0; i < m; i++) {
		cin >> works[i];
	}

	fill(dp, dp + 10001, 2134567890);
	dp[0] = 0;
	check[0] = 1;

	for (int i = 0; i < m; i++) {
		check[works[i]] = 1;
		dp[works[i]] = 1;
		for (int j = i + 1; j < m; j++) {
			check[works[i] + works[j]] = 1;
			dp[works[i] + works[j]] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (check[i]) continue;
		for (int j = i - 1; j > 0; j--) {
			if (dp[j] != 2134567890 && dp[i - j] != 2134567890){
				dp[i] = min(dp[i], dp[i - j] + dp[j]);
			}
		}
	}
	int answer = (dp[n] != 2134567890) ? dp[n] : -1;
	cout << answer;

	return 0;
}