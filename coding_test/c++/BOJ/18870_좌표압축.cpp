#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>

using namespace std;

long long answer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int nums[10000001] = { 0 };
	int answer[1000001] = { 0 };
	map<int, int> q;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		nums[i] = input;
		q[input] = 0;
	}
	int cnt = 0;
	for (auto &sub_q : q) {
		sub_q.second = cnt++;
	}

	for (int i = 0; i < n; i++) {
		cout << q[nums[i]] << ' ';
	}
	return 0;
}