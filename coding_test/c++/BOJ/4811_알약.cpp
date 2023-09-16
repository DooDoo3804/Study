#include<iostream>

using namespace std;

//카탈란 수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long dp[31] = { 0 };
	dp[0] = 1;
	for (int i = 1; i <= 30; i++) {
		dp[i] = 0;
		for (int j = 0; j < i; j++) {
			dp[i] += dp[j] * dp[i - j - 1];
		}
	}

	int n;
	while (cin >> n && n != 0) {
		cout << dp[n] << '\n';
	}

	return 0;
}