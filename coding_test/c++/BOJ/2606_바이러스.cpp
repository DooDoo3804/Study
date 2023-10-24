#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

int parent[101];

int find_parent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find_parent(parent[x]);
}

void make_parent(int x, int y) {
	int p_x = find_parent(x);
	int p_y = find_parent(y);
	
	if (p_x == p_y) return;
	
	if (p_x > p_y) parent[p_x] = p_y;
	else parent[p_y] = p_x;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i <= n; i++) parent[i] = i;


	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		make_parent(x, y);
	}

	int answer = -1;

	for (int i = 1; i <= n; i++) {
		if (find_parent(i) == 1) answer++;
	}

	cout << answer;

	return 0;
}