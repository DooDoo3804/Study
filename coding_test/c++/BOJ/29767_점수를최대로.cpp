#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	cin >> n >> k;

	vector<long long> dp;
	for (int i = 0; i < n; i++) {
		long long input = 0;
		cin >> input;
		if (dp.empty()) dp.push_back(input);
		else dp.push_back(dp.back() + input);
	}
	
	sort(dp.begin(), dp.end());
	reverse(dp.begin(), dp.end());

	long long answer = 0;
	for (int i = 0; i < k; i++) answer += dp[i];
	cout << answer;

	return 0;
}