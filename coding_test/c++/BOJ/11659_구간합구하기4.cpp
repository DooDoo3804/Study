#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;


int init_tree(vector<int>&nodes, vector<int> &tree, int start, int end, int node) {
	if (start == end) return tree[node] = nodes[start];
	int mid = (start + end) / 2;
	return tree[node] = init_tree(nodes, tree, start, mid, node * 2) + init_tree(nodes, tree, mid + 1, end, node * 2 + 1);
}

int sum_tree(vector<int>&tree, int left, int right, int start, int end, int node) {
	if (end < left || start > right) return 0;
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return sum_tree(tree, left, right, start, mid, node * 2) + sum_tree(tree, left, right, mid + 1, end, node * 2 + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> nodes(n + 1);
	vector<int> tree(4 * (n + 1));

	for (int i = 1; i <= n; i++) {
		int input;
		cin >> input;
		nodes[i] = input;
	}

	init_tree(nodes, tree, 1, n, 1);
	
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cout << sum_tree(tree, x, y, 1, n, 1) << '\n';
	}

	return 0;
}