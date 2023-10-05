#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> liqs;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		liqs.push_back(input);
	}

	sort(liqs.begin(), liqs.end());

	int answer[3] = { 2134567890, 0, 0 };

	for (int i = 0; i < n; i++) {
		int start = i + 1;
		int end = n - 1;
		while (start <= end) {
			int middle = (start + end) / 2;
			if (abs(liqs[middle] + liqs[i]) < answer[0]) {
				answer[0] = abs(liqs[middle] + liqs[i]);
				answer[1] = min(liqs[i], liqs[middle]);
				answer[2] = max(liqs[i], liqs[middle]);
			}
			if (abs(liqs[start] + liqs[i]) < abs(liqs[end] + liqs[i])) {
				end = middle - 1;
			}
			else {
				start = middle + 1;
			}
		}
	}

	cout << answer[1] << ' ' << answer[2];

	return 0;
}