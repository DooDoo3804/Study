#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, s;
	cin >> n >> s;

	int nums[100001] = { 0 };

	for (int i = 1; i <= n; i++) {
		int input;
		cin >> input;
		nums[i] = nums[i - 1] + input;
	}

	int right = 0;
	int left = 0;
	int mid = 0;
	int answer = 2134567890;

	for (int i = 0; i <= n; i++) {

		right = n;
		left = i + 1;

		while (left < right) {
			mid = (left + right) / 2;
			if (nums[mid] - nums[i] < s) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		if (nums[left] - nums[i] < s) continue;
		answer = min(left - i, answer);
	}
	answer = (answer == 2134567890) ? 0 : answer;
	cout << answer;
	
	return 0;
}