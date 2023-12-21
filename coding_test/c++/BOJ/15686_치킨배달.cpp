#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<pair<int, int>> chicks;
vector<pair<int, int>> homes;
int answer = 2134567890;

int calcDist(int visited[]) {
	int subSum = 0;
	for (auto home : homes) {
		int minDist = 2134567890;
		for (int i = 0; i < chicks.size(); i++) {
			if (visited[i] == 0) continue;
			minDist = min(minDist, abs(home.first - chicks[i].first) + abs(home.second - chicks[i].second));
		}
		subSum += minDist;
	}
	return subSum;
}

void selectChicks(int index, int k, int visited[]) {
	if (k == 0) {
		int distance = calcDist(visited);
		answer = min(answer, distance);
		return;
	}
	
	if (index == chicks.size()) return;

	visited[index] = 1;
	selectChicks(index + 1, k - 1, visited);
	visited[index] = 0;
	selectChicks(index + 1, k, visited);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	int total_map[51][51] = { 0 };
	int visited[14] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> total_map[i][j];
			if (total_map[i][j] == 2) chicks.push_back(make_pair(i, j));
			else if (total_map[i][j] == 1) homes.push_back(make_pair(i, j));
		}
	}
	
	selectChicks(0, m, visited);

	cout << answer;

	return 0;
}