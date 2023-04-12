#include <iostream>

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool comp(vector <int> a, vector <int> b) {
	if (a[1] == b[1]) return a[2] > b[2];
	else return a[1] < b[1];
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
	vector <int> time_list;
	int time_array[200001] = { 0 };
	for (int i = 0; i < n; i++) {
		int start = 0;
		int end = 0;
		int people = 0;
		cin >> start >> end >> people;
		time_line.push_back({ start, end, people });
		if (count(time_list.begin(), time_list.end(), start) == 0) time_list.push_back(start);
		if (count(time_list.begin(), time_list.end(), end) == 0) time_list.push_back(end);
	}

	sort(time_list.begin(), time_list.end(), compare);
	sort(time_line.begin(), time_line.end(), comp);

	// 끝나는 시간 기준으로 정렬ㄹ하고
	// dp로 구현
	return 0;
}
