#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long dp[5001] = { 0 };
	dp[0] = 1;

	int t = 0;
	cin >> t;

	vector <int> ans;
	for (int i = 0; i < t; i++) {
		int sub;
		cin >> sub;
		ans.push_back(sub);
	}

	for (int i = 1; i < 5001; i++) {
		if (i % 2) dp[i] = 0;
		else if (i == 2) dp[2] = 1;
		else if (i == 4) dp[4] = 2;
		else {
			for (int j = 0; j <= i - 2; j+=2) {
				dp[i] += (dp[i - 2 - j] * dp[j] ) % 1000000007;
			}
			dp[i] = dp[i] % 1000000007;
		}
	}

	for (int a : ans) {
		cout << dp[a] << "\n";
	}
	return 0;
}
