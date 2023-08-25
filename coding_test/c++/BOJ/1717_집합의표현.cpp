#include <iostream>
#include <vector>

using namespace std;

int parent[1000001] = { 0 };
int n;
int m;

int Find(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n + 1; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int t;  int a; int b;
		cin >> t >> a >> b;

		if (t == 0) Union(a, b);
		else {
			if (Find(a) == Find(b)) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}

	return 0;
}