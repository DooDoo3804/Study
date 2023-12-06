#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int index = 0;

	priority_queue<int, vector<int>, less<int>> pq_l;
	priority_queue<int, vector<int>, greater<int>> pq_r;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;

		if (pq_l.size() > pq_r.size()) pq_r.push(input);
		else pq_l.push(input);

		if (!pq_l.empty() && !pq_r.empty() && pq_l.top() > pq_r.top()) {
			int temp_l = pq_l.top();
			int temp_r = pq_r.top();
			pq_l.pop();
			pq_r.pop();
			pq_l.push(temp_r);
			pq_r.push(temp_l);
		}
		cout << pq_l.top() << '\n';
	}


	return 0;
}