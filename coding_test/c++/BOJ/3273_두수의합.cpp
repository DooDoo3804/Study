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

	int n, x;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		nums.push_back(input);
	}
	cin >> x;

	sort(nums.begin(), nums.end());

	int end_ind = n - 1;
	int answer = 0;

	for (int i = 0; i < n; i++) {
		int start = 0;
		int end = end_ind;
		while (start <= end) {
			int middle = (start + end) / 2;
			if (nums[middle] + nums[i] == x) {
				answer++;
				break;
			}
			else if (nums[middle] + nums[i] > x) {
				end = middle - 1;
			}
			else start = middle + 1;
		}
	}

	cout << answer / 2;

	return 0;
}