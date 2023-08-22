#include <iostream>
#include <queue>
#include <algorithm>

#define INF 2134567890

using namespace std;

struct step{
	int now; int copy_num; int c;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	int dp[1001][1001] = { 0 };
	
	for (int i = 0; i < 1001; i++) fill(dp[i], dp[i] + 1001, INF);

	dp[1][0] = 0;

	queue<step> q;
	q.push({ 1, 0, 0 });

	int answer = 0;

	while (!q.empty()) {
		step now_step = q.front();
		q.pop();
		int now = now_step.now;
		int count = now_step.c;
		int copy = now_step.copy_num;

		if (now == n) {
			answer = count;
			break;
		}

		if (copy != now && dp[now][now] > count + 1) {
			dp[now][now] = count + 1;
			q.push({ now, now, count + 1 });
		}

		if (now + copy <= 1000 && dp[now + copy][copy] > count + 1) {
			dp[now + copy][copy] = count + 1;
			q.push({ now + copy, copy, count + 1 });
		}

		if (now - 1 > 0 && dp[now - 1][copy] > count + 1) {
			dp[now - 1][copy] = count + 1;
			q.push({ now - 1, copy, count + 1 });
		}
	}

	cout << answer;

	return 0;
}