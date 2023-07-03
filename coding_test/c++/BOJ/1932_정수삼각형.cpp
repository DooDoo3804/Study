#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> arr;
	vector<vector<int>> ans_arr;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		vector<int> sub_vector;
		vector<int> sub_vector2;
		for (int j = 0; j < i + 1; j++) {
			int input;
			cin >> input;
			sub_vector.push_back(input);
			if (i == 0) {
				sub_vector2.push_back(input);
				ans = max(ans, input);
			}
			else {
				if (j == 0) {
					sub_vector2.push_back(input + ans_arr[i - 1][0]);
					ans = max(input + ans_arr[i - 1][0], ans);
				}
				else if (j == i) {
					sub_vector2.push_back(input + ans_arr[i - 1][i - 1]);
					ans = max(input + ans_arr[i - 1][i - 1], ans);
				}
				else {
					sub_vector2.push_back(max(ans_arr[i - 1][j - 1], ans_arr[i - 1][j]) + input);
					ans = max(max(ans_arr[i - 1][j - 1], ans_arr[i - 1][j]) + input, ans);
				}
			}
		}
		ans_arr.push_back(sub_vector2);
		arr.push_back(sub_vector);
	}

	cout << ans;

	return 0;
}