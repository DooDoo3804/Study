#include <iostream>
#include <map>
#include <algorithm>

#define INF 999999999

using namespace std;

map<int, int> nums;

int get_ans(int a, int b)
{
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n = 0;
	cin >> n;

	int total_num[1000001] = { 0 };
	int dp[1000001][3][2];
	for (int i = 0; i < 1000001; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 2; k++) {
				dp[i][j][k] = INF;
			}
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		int now;
		cin >> now;
		if (i == 1)
		{
			dp[i][0][0] = now;
			dp[i][0][1] = 0;
			dp[i][1][0] = 0;
			dp[i][1][1] = 0;
			dp[i][2][0] = 0;
			dp[i][2][1] = now;
		}
		else
		{
			dp[i][0][0] = get_ans(dp[i - 1][0][0], now);
			dp[i][0][1] = 0;

			// 1
			int first[2] = { 1 };
			int second[2] = { 1 };
			if (dp[i - 1][1][1] % get_ans(dp[i - 1][1][0], now) != 0) {
				first[0] = get_ans(dp[i - 1][1][0], now);
				first[1] = dp[i - 1][1][1];
			}
			if (dp[i - 1][2][1] % get_ans(dp[i - 1][2][0], now) != 0) {
				second[0] = get_ans(dp[i - 1][2][0], now);
				second[1] = dp[i - 1][2][1];
			}

			if (first[0] == second[0]) {
				dp[i][1][0] = min(first[0], second[0]);
				dp[i][1][1] = min(first[1], second[1]);
			}
			else {
				if (first[0] > second[0]) {
					dp[i][1][0] = first[0];
					dp[i][1][1] = first[1];
				}
				else {
					dp[i][1][0] = second[0];
					dp[i][1][1] = second[1];
				}
			}

			if (now % dp[i - 1][0][0] != 0) {
				dp[i][2][0] = dp[i - 1][0][0];
				dp[i][2][1] = now;
			}
			else if (now % dp[i - 1][0][0] == 0) {
				dp[i][2][0] = 1;
				dp[i][2][1] = 0;
			}
		}
	}

	int max[2] = { 0,0 };
	for (int i = 1; i < 3; i ++) {
		if (max[0] < dp[n][i][0]) {
			max[0] = dp[n][i][0];
			max[1] = dp[n][i][1];
		}
	}
	if (max[0] == 1 && max[1] == 0) cout << -1;
	else cout << max[0] << " " << max[1];

	return 0;
}