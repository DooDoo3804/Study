#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	vector<int> nums;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());

	int num_range = roundf(n * 0.15);
	double ans[2] = { 0 };

	for (int i = 0; i < n; i++) {
		if (num_range <= i && i < n - num_range) {
			ans[0] += nums[i];
			ans[1] ++;
		}
	}

	cout << roundf(ans[0] / ans[1]);

	return 0;
}