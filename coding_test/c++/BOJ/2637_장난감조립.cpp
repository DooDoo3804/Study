#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n; int m;
vector<pair<int, int>> part[101];
int in[101] = { 0 };
int cnt[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, k;
		cin >> x >> y >> k;
		part[x].push_back({ y, k });
		in[y]++;
	}

	vector<int> ans;
	queue<int> q;

	q.push(n);
	cnt[n] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (part[now].empty()) ans.push_back(now);
		for (auto p : part[now]) {
			int next = p.first;
			int c = p.second;
			cnt[next] += cnt[now] * c;
			if (--in[next] == 0) q.push(next);
		}
	}
	sort(ans.begin(), ans.end());

	for (auto k : ans) cout << k << " " << cnt[k] << "\n";


	return 0;
}