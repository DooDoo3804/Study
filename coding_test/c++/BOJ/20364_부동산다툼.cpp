#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>

using namespace std;

#define INF 213456790

int parent[1111111];
int visited[1111111];
queue<int> answer;

int get_parent(int x) {
	return parent[x] = x / 2;
}

void check_parent(int x) {
	if (parent[x] == x) return;
	if (visited[x] == 1) {
		answer.push(x);
	}
	check_parent(parent[x]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		get_parent(i);
	}
	parent[1] = 1;

	for (int i = 0; i < q; i++) {
		answer = queue<int>();
		int input;
		cin >> input;
		check_parent(input);
		if (answer.empty()) {
			visited[input] = 1;
			cout << 0 << '\n';
		}
		else cout << answer.back() << '\n';
	}

	return 0;
}