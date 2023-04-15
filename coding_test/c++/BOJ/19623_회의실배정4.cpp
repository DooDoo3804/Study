#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool comp(vector <int> a, vector <int> b) {
	return a[1] < b[1];
}

bool compare(int a, int b) {
	return a < b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n = 0;
	cin >> n;
	vector <vector<int>> time_line;
	map <int, int> time_list;

	for (int i = 0; i < n; i++) {
		int start = 0;
		int end = 0;
		int people = 0;
		cin >> start >> end >> people;
		time_line.push_back({ start, end, people });
		time_line.push_back({ end, start, people });
		time_list[start] = 0;
		time_list[end] = 0;
	}

	int c = 0;
	for (auto& tm : time_list) {
		tm.second = c++;
	}

	sort(time_line.begin(), time_line.end(), comp);
	int dp[200001] = { 0 };

	for (int i = 0; i < time_line.size(); i++) {
		if (i == 0) dp[i] = 0;
		else if (time_line[i][0] > time_line[i][1]) dp[i] = dp[i - 1];
		else {
			dp[i] = max(dp[i - 1], dp[time_list[time_line[i][0]]] + time_line[i][2]);
		}
	}
	cout << dp[time_list.size()-1];
	return 0;
}
