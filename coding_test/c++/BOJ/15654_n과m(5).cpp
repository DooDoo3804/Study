#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>

using namespace std;

int n, m;
vector<int> nums;
vector<int> q;

void greedy(int now) {
	if (q.size() == m) {
		for (int i = 0; i < q.size(); i++) {
			cout << q[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (find(q.begin(), q.end(), nums[i]) != q.end()) continue;
		q.push_back(nums[i]);
		greedy(i);
		q.pop_back();
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		nums.push_back(input);
	}
	sort(nums.begin(), nums.end());

	for (int i = 0; i < n; i++) {
		q.push_back(nums[i]);
		greedy(i);
		q.pop_back();
	}
	
	return 0;
}