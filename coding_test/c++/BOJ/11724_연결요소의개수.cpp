#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>

using namespace std;

int parent[1001];
int check[1001];

int find_parent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find_parent(parent[x]);
}

void make_parent(int x, int y) {
	int parent_x = find_parent(x);
	int parent_y = find_parent(y);
	if (x > y) parent[parent_x] = parent_y;
	else parent[parent_y] = parent_x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> nodes;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		make_parent(u, v);
	}
	
	for (int i = 1; i <= n; i++) {
		int pa = find_parent(i);
		if (pa) check[pa] = 1;
	}

	cout << count(check, check + 1001, 1);
	return 0;
}