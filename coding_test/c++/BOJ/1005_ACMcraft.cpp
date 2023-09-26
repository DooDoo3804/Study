#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	int n, k, x, y;
	
	int times[1001] = { 0 };
	int indegree[1001] = { 0 };
	int ans[1001] = { 0 };

	while (t--) {
		cin >> n >> k;
		fill(times, times + 1001, 0);
		fill(indegree, indegree + 1001, 0);
		fill(ans, ans + 1001, 0);

		vector<vector<int>> graph(1001);

		for (int i = 1; i <= n; i++) cin >> times[i];
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			graph[x].push_back(y);
			indegree[y]++;
		}

		queue<int> q;
		for (int i = 1; i <= n; i++)
			if (!indegree[i]) {
				q.push(i);
				ans[i] += times[i];
			}

		while (!q.empty()) {
			auto now = q.front();
			q.pop();

			for (auto next : graph[now]) {
				ans[next] = max(ans[now], ans[next]);
				if (--indegree[next] == 0) {
					q.push(next);
					ans[next] += times[next];
				}
			}
		}

		int input;
		cin >> input;
		cout << ans[input] << '\n';

	}

	return 0;
}