#include <iostream>
#include <string>

using namespace std;

int nums[21] = { 0 };

void s_add(int a) {
	if (nums[a] == 0) nums[a]++;
}

void s_remove(int a) {
	if (nums[a] == 1) nums[a]--;
}

void s_check(int a) {
	if (nums[a]) cout << 1 << "\n";
	else cout << 0 << "\n";

}

void s_toggle(int a) {
	nums[a] = !nums[a];
}

void s_all() {
	fill(nums, nums + 21, 1);
}

void s_empty() {
	fill(nums, nums + 21, 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string input_str;
		cin >> input_str;
		if (input_str == "all") s_all();
		else if (input_str == "empty") s_empty();
		else {
			int input_num;
			cin >> input_num;
			if (input_str == "add") s_add(input_num);
			else if (input_str == "remove") s_remove(input_num);
			else if (input_str == "toggle") s_toggle(input_num);
			else if (input_str == "check") s_check(input_num);
		}
	}
	return 0;
}