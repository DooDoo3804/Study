#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	vector<int> nums;
	vector<int> stack;
	vector<string> ans;
	vector<int> check_list;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}
	
	int index = 0;
	int num = 1;
	stack.push_back(0);

	while(check_list.size() < n){
		if (stack.back() == nums[index]) {
			check_list.push_back(stack.back());
			stack.pop_back();
			ans.push_back("-");
			index++;
		}
		else if (stack.back() < nums[index]) {
			stack.push_back(num);
			ans.push_back("+");
			num++;
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}