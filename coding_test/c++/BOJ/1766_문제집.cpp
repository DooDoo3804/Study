#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct comp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.first > b.first;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(32001);
	int indegree[32001] = { 0 };

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back( b );
		indegree[b]++;
	}

	priority_queue<pair<int, int>, vector<pair<int,int>>, comp> q;
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) q.push({ i, i });
	}

	vector<int> ans;

	while (!q.empty()) {
		auto now = q.top();
		q.pop();
		ans.push_back(now.first);

		for (auto next : graph[now.first]) {
			if (--indegree[next] == 0) q.push({ next, next });
		}
	}

	for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';

	return 0;
}