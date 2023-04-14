#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int nums[10001] = { 0 };
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		nums[input]++;
	}

	for (int i = 1; i < 10001; i++) {
		if (nums[i]) {
			for (int j = 0; j < nums[i]; j++) {
				cout << i << "\n";
			}
		}
	}
	return 0;
}