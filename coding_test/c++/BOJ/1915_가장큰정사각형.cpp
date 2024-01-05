#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int answer = 0;
	cin >> n >> m;

	int total_map[1001][1001] = { 0 };
	int dp[1001][1001] = { 0 };
	
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			total_map[i + 1][j + 1] = input[j] - '0';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (total_map[i][j] == 0) continue;
			dp[i][j] = min({ dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j] }) + 1;
			answer = max(dp[i][j], answer);
		}
	}

	cout << pow(answer,2);

	return 0;
}