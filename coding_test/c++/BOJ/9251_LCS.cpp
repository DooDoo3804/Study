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

	string input1, input2;
	cin >> input1 >> input2;

	int dp[1001][1001] = { 0 };

	for (int i = 1; i <= input1.size(); i++) {
		for (int j = 1; j <= input2.size(); j++) {
			if (input1[i - 1] == input2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}

		}
	}

	cout << dp[input1.size()][input2.size()];

	return 0;
}