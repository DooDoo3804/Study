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
	int dp[12] = { 0 };

	dp[0] = dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 12; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	while (t--) {
		int input;
		cin >> input;
		cout << dp[input] << '\n';
	}

	return 0;
}