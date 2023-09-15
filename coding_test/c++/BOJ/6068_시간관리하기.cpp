#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct time {
	int t, s;
};

bool compare(time a, time b) {
	if (a.s == b.s) return a.t > b.t;
	return a.s > b.s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	priority_queue<time> pq;

	vector<time> time_table;
	for (int i = 0; i < n; i++) {
		int t, s;
		cin >> t >> s;
		time_table.push_back({ t, s });
	}
	sort(time_table.begin(), time_table.end(), compare);

	int now_time = time_table[0].s;
	
	int answer = 0;

	for (int i = 0; i < n; i++) {
		if (now_time > time_table[i].s) now_time = time_table[i].s;
		now_time -= time_table[i].t;
	}
	answer = (now_time < 0) ? - 1 : now_time;
	cout << answer;
	return 0;
}