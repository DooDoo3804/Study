#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int test(int n) {
	vector <vector <int>> nodes;
	int dp[100000][3] = {0};

	for (int i = 0; i < n; i++) {
		int a = 0; int b = 0; int c = 0;
		cin >> a >> b >> c;
		nodes.push_back({ a, b, c });
	}

	int t = 0;
	int s = 1;
	int w = nodes[0][1];
	dp[0][0] = 100000;
	dp[0][1] = nodes[0][1];
	dp[0][2] = nodes[0][1]+nodes[0][2];

	for (int i = 1; i < n; i++) {
		if (i == 1) {
			dp[i][0] = dp[0][1] + nodes[1][0];
			dp[i][1] = min(dp[0][1] + nodes[1][1], dp[0][2] + nodes[1][1]);
			dp[i][2] = min(dp[0][1] + nodes[1][2], dp[0][2] + nodes[1][2]);
		}
		else {
			dp[i][0] = min(nodes[i][0] + dp[i - 1][0], nodes[i][0] + dp[i - 1][1]);
			dp[i][1] = min(nodes[i][1] + dp[i - 1][0], min(nodes[i][1] + dp[i - 1][1], nodes[i][1] + dp[i - 1][2]));
			dp[i][2] = min(nodes[i][2] + dp[i - 1][1], nodes[i][2] + dp[i - 1][2]);
		}
		dp[i][1] = min(dp[i][0] + nodes[i][1], dp[i][1]);
		dp[i][2] = min(dp[i][1] + nodes[i][2], dp[i][2]);
	}
	return dp[n-1][1];
}


int main() {
	int tc = 1;
	while (true) {
		int n = 0;
		cin >> n;
		if (n == 0) {
			return 0;
		}
		int r = test(n);
		cout << tc << '.' << ' ' << r << '\n';
		tc++;
	}	
	return 0;
}