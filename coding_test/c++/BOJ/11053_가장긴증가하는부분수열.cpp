#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> nums(n + 1);
	int dp[1001][2] = { 0 };

	for (int i = 1; i <= n; i++) {
		dp[i][0] = 2134567890;
		cin >> nums[i];
	}

	int answer = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (dp[j][0] >= nums[i]) continue;
			if (dp[j][1] + 1 >= dp[i][1]) {
				dp[i][1] = dp[j][1] + 1;
				answer = max(answer, dp[i][1]);
				dp[i][0] = min(nums[i], dp[i][0]);
			}

		}
	}

	cout << answer;
	return 0;
}