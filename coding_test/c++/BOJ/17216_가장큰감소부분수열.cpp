#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int nums[1000] = { 0 };
	int dp[1000] = { 0 };
	
	for (int i = 0; i < n; i++) cin >> nums[i];

	for (int i = 0; i < n; i++) {
		dp[i] = nums[i];
		for (int j = 0; j < i; j++) {
			if (nums[i] < nums[j]) dp[i] = max(dp[i], dp[j] + nums[i]);
		}
	}

	cout << *max_element(dp, dp + n);
	
	return 0;
}