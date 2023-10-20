#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> times;

	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		times.push_back(make_pair(from, to));
	}

	sort(times.begin(), times.end(), comp);

	int pre_time = 0;
	int pre_cnt = 0;

	for (auto time : times) {
		if (time.first < pre_time) continue;
		pre_cnt++;
		pre_time = time.second;
	}
	cout << pre_cnt;
	return 0;
}