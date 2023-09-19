#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int t, n;
int visited[100001] = { 0 };
int selected[100001] = { 0 };
int finished[100001] = { 0 };
int cnt;

void dfs(int now) {
	visited[now] = 1;
	int next = selected[now];

	if (!visited[next]) dfs(next);
	else if (!finished[next]) {
		for (int i = next; i != now; i = selected[i]) {
			cnt++;
		}
		cnt++;
	}
	finished[now] = 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;
		fill(visited, visited + 100001, 0);
		fill(selected, selected + 100001, 0);
		fill(finished, finished + 100001, 0);

		for (int j = 1; j <= n; j++) {
			cin >> selected[j];
		}

		cnt = 0;

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) dfs(i);
		}

		cout << n - cnt << '\n';
	}
	return 0;
}