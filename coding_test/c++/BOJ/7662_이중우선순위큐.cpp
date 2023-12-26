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

	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		priority_queue<int, vector<int>, greater<int>> min_q;
		priority_queue<int, vector<int>, less<int>> max_q;
		map<int, int> arr;

		for (int i = 0; i < k; i++) {
			char type;
			int num;
			cin >> type >> num;
			if (type == 'I') {
				min_q.push(num);
				max_q.push(num);
				arr[num]++;
			}
			else if (type == 'D') {
				if (num == 1 && !max_q.empty()) {
					arr[max_q.top()]--;
					max_q.pop();
				}
				else if (num == -1 && !min_q.empty()){ 
					arr[min_q.top()]--;
					min_q.pop();
				}
			}
			while (!max_q.empty() && arr[max_q.top()] == 0) max_q.pop();
			while (!min_q.empty() && arr[min_q.top()] == 0) min_q.pop();
		}

		if (!max_q.empty() && !min_q.empty()) cout << max_q.top() << ' ' << min_q.top();
		else cout << "EMPTY";
		cout << '\n';
	}

	return 0;
}