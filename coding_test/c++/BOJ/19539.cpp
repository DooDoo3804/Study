#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
	int n = 0;
	cin >> n;
	int trees[100001] = {0};
	int counts[2] = { 0, 0 };
	for (int i = 0; i < n; i++) {
		int t = 0;
		cin >> t;
		if (t % 2) {
			counts[0] += 1;
			counts[1] += t / 2;
		}
		else if (t % 2 == 0) {
			counts[1] += t / 2;
		}
		trees[i] = t;
	}
	
	if (counts[0] > counts[1]) {
		cout << "NO";
		return 0;
	}
	else {
		if ((counts[1] - counts[0]) % 3 == 0) {
			cout << "YES";
			return 0;
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	return 0;
}