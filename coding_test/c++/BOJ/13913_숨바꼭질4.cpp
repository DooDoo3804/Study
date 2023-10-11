#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	int visited[100001] = { 0 };
	int dist[100001] = { 0 };
	int pre_num[100001] = { 0 };

	visited[n] = 1;
	pre_num[n] = -1;

	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		if (now.first == k) {
			vector<int> answer;
			cout << dist[now.first] << '\n';
			for (int i = now.first; i != -1; i = pre_num[i]) {
				answer.push_back(i);
			}
			reverse(answer.begin(), answer.end());
			for (auto a : answer) {
				cout << a << ' ';
			}
			return 0;
		}
		if (now.first + 1 < 100001 && visited[now.first + 1] == 0) {
			visited[now.first + 1] = 1;
			dist[now.first + 1] = now.second + 1;
			pre_num[now.first + 1] = now.first;
			q.push(make_pair(now.first + 1, now.second + 1));
		}
		if (now.first - 1 >= 0 && visited[now.first - 1] == 0) {
			visited[now.first - 1] = 1;
			dist[now.first - 1] = now.second + 1;
			pre_num[now.first - 1] = now.first;
			q.push(make_pair(now.first - 1, now.second + 1));
		}
		if (now.first * 2 < 100001 && visited[now.first * 2] == 0) {
			visited[now.first * 2] = 1;
			dist[now.first * 2] = now.second + 1;
			pre_num[now.first * 2] = now.first;
			q.push(make_pair(now.first * 2, now.second + 1));
		}
	}

	return 0;
}