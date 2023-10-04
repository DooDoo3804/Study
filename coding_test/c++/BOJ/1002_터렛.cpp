#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		int dist1 = max(r1, r2) - min(r1, r2);
		int dist2 = r1 + r2;

		if (x1 == x2 & y1 == y2 && r1 == r2) cout << -1;
		else if(0 <= dist && dist < dist1) cout << 0;
		else if (dist == dist1 || dist == dist2) cout << 1;
		else if (dist1 < dist && dist < dist2) cout << 2;
		else cout << 0;
		cout << "\n";
	}

	return 0;
}