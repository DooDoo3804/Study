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

	long long dp[1001] = { 0 };
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i < 1001; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}

	int input;
	cin >> input;
	cout << dp[input];  

	return 0;
}