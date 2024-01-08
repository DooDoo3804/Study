#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, less<int>> pq;

	while (n--) {
		int input;
		cin >> input;
		if (input == 0) {
			if (!pq.empty()) {
				int top = pq.top();
				pq.pop();
				cout << top << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else pq.push(input);
	}

	return 0;
}