#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; int m;
	cin >> n >> m;

	set<string> arr1;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		arr1.insert(input);
	}

	vector<string> ans;

	for (int i = 0; i < m; i++) {
		string input;
		cin >> input;
		if (arr1.count(input)) {
			ans.push_back(input);
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";

	for (auto a : ans) {
		cout << a << "\n";
	}

	return 0;
}