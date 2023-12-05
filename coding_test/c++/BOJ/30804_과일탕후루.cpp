#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	int answer = 0;
	cin >> n;

	int fruits[200000] = { 0 };
	int counts[10] = { 0 };

	for (int i = 0; i < n; i++) {
		cin >> fruits[i];
	}

	int type = 0;
	int l = 0;
	for (int r = 0; r < n; r++) {
		if (++counts[fruits[r]] == 1) type++;
		while (type > 2) {
			if (--counts[fruits[l++]] == 0) type--;
		}
		answer = max(answer, r - l + 1);
	}

	cout << answer;
	return 0;
}
