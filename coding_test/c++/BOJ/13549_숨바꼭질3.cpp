#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>

using namespace std;

struct node {
	int index, time;
};

bool operator<(node a, node b) {
	return a.time > b.time;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	int dp[100001];
	fill(dp, dp + 100001, 2134567890);
	dp[n] = 0;

	priority_queue<node> q;
	q.push({ n, 0 });

	while (!q.empty()) {
		auto now = q.top();
		q.pop();
		if (now.index + 1 < 100001 && now.time + 1 < dp[now.index + 1]) {
			dp[now.index + 1] = now.time + 1;
			q.push({ now.index + 1, now.time + 1 });
		}
		if (now.index - 1 >= 0 && now.time + 1 < dp[now.index - 1]) {
			dp[now.index - 1] = now.time + 1;
			q.push({ now.index - 1, now.time + 1 });
		}
		if (now.index * 2 < 100001 && now.time < dp[now.index * 2]) {
			dp[now.index *2] = now.time;
			q.push({ now.index * 2, now.time });
		}
	}

	cout << dp[k];
	return 0;
}