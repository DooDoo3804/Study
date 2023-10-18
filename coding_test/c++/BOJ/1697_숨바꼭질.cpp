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

	int n, k;
	cin >> n >> k;

	queue<pair<int, int>> q;
	int dp[100001] = { 0 };
	int visited[100001] = { 0 };
	q.push(make_pair(n, 0));
	visited[n] = 1;

	if (n >= k) {
		cout << n - k;
		return 0;
	}
	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		if (now.first + 1 <= 100000 && visited[now.first + 1] == 0) {
			dp[now.first + 1] = now.second + 1;
			visited[now.first + 1] = 1;
			q.push({ now.first + 1, now.second + 1 });
		}
		if (now.first - 1 >= 0 && visited[now.first - 1] == 0) {
			dp[now.first - 1] = now.second + 1; 
			visited[now.first - 1] = 1;
			q.push({ now.first - 1, now.second + 1 });
		}
		if (now.first * 2 <= 100000 && visited[now.first * 2] == 0) {
			dp[now.first * 2] = now.second + 1;
			visited[now.first * 2] = 1;
			q.push({ now.first * 2, now.second + 1 });
		}
	}

	cout << dp[k];

	return 0;
}