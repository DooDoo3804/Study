#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	long long f_x[1000001] = { 0 };
	long long dp[1000001] = { 0 };

	for (int i = 1; i < 1000001; i++) {
		for (int j = i; j < 1000001; j += i) {
			f_x[j] += i;
		}

		dp[i] = dp[i - 1] + f_x[i];
	}

	while (t--) {
		int input;
		cin >> input;
		cout << dp[input] << '\n';
	}
	return 0;
}