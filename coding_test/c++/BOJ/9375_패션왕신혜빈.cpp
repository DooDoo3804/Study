#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	map<string, int> q;
	vector<string> gear;

	while (t--) {
		q = map<string, int>();

		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			q[b] ++;
			if (find(gear.begin(), gear.end(), b) == gear.end()) gear.push_back(b);
		}
		int answer = 1;
		for (auto g : gear) {
			answer *= (q[g] + 1);
		}
		cout << answer - 1 << '\n';
	}


	return 0;
}