#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>

using namespace std;

int n, m;
vector<int> q;

void greedy(int now) {
	if (q.size() == m) {
		for (int i = 0; i < q.size(); i++) {
			cout << q[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = now; i <= n; i++) {
		q.push_back(i);
		greedy(i);
		q.pop_back();
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		q.push_back(i);
		greedy(i);
		q.pop_back();
	}
	
	return 0;
}