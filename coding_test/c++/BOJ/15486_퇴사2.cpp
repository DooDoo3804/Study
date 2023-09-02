#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; 
	cin >> n;

	int dp[1500001] = { 0 };
	vector<pair<int, int>> days;

	for (int i = 0; i < n; i++) {
		int t, p;
		cin >> t >> p;
		days.push_back(make_pair(t, p));
	}

	int answer = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (i + days[i].first < n + 1) {
			int next_day = i + days[i].first;
			dp[i] = max(dp[next_day] + days[i].second, dp[i + 1]);
		}
		else dp[i] = dp[i + 1];
	}

	cout << dp[0];
	
	return 0;
}