#include <iostream>
#include <vector>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int, int>> dp;
	int t;
	cin >> t;
	dp.push_back(make_pair(1, 0));
	dp.push_back(make_pair(0, 1));
	while (dp.size() != 41) {
		auto pre1 = dp[dp.size() - 1];
		auto pre2 = dp[dp.size() - 2];
		dp.push_back(make_pair(pre1.first + pre2.first, pre1.second + pre2.second));
	}

	for (int i = 0; i < t; i++) {
		int input;
		cin >> input;
		cout << dp[input].first << " " << dp[input].second << "\n";
	}	
	return 0;
}