#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int input;
		cin >> input;
		if (input <= 25) cout << "Case #" << i << ": World Finals" << "\n";
		else if (input <= 1000) cout << "Case #" << i << ": Round 3" << "\n";
		else if (input <= 4500) cout << "Case #" << i << ": Round 2" << "\n";
		else cout << "Case #" << i << ": Round 1" << "\n";
	}

	return 0;
}