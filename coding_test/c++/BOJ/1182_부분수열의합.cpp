#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n = 0;
	int s = 0;
	cin >> n >> s;

	int nums[20] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int result = 0;

	for (int i = 1; i < 1 << n; i++) {
		int sub_sum = 0;
		for (int j = 0; j < n; j++) {
			if (i&(1 << j)) sub_sum += nums[j];
		}
		if (sub_sum == s) result++;
	}

	cout << result;
	return 0;
}