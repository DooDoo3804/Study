#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int dp[41] = { 0 };
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < 41; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int n; int m;
	cin >> n >> m;

	vector<int> input_num;
	int input = 0;

	for (int i = 0; i < m; i++) {
		cin >> input;
		input_num.push_back(input);
	}

	int index = 0;
	int answer = 1;
	for (int next_num : input_num) {
		answer *= (dp[next_num - index - 1]);
		index = next_num;
	}
	answer *= dp[n - index];
	cout << answer;
	return 0;
}