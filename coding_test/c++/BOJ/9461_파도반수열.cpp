#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	long long dp[101] = { 0 };
	dp[0] = 0;
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = 2;

	for (int i = 5; i < 101; i++) {
		dp[i] = dp[i - 5] + dp[i - 1];
	}

	while (t--) {
		int input;
		cin >> input;
		cout << dp[input] << '\n';
	}
	return 0;
}