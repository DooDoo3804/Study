#include<iostream>

using namespace std;

long long arr[1000001];
long long tree[4000004];

long long init(int node, int start, int end) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end) % 1000000007;
}

void update(int node, int start, int end, int index, int mul, int div) {
	if (index < start || end < index) return;
	// tree[node] = tree[node] / div * mul % 1000000007;
	if (start != end) {
		int mid = (start + end) / 2 % 1000000007;
		update(node * 2, start, mid, index, mul, div);
		update(node * 2 + 1, mid + 1, end, index, mul, div);
		tree[node] = tree[node * 2] * tree[node * 2 + 1] % 1000000007;
	}
	else tree[node] = mul;
}

long long cal_mul(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 1;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return cal_mul(node * 2, start, mid, left, right) * cal_mul(node * 2 + 1, mid + 1, end, left, right) % 1000000007;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; int m; int k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	init(1, 0, n - 1);

	for(int i = 0; i < m + k; i++) {
		int a; int b; int c;
		cin >> a >> b >> c;
		if (a == 1) update(1, 0, n - 1, b - 1, c, arr[b - 1]);
		else if (a == 2) cout << cal_mul(1, 0, n - 1, b - 1, c - 1) << "\n";
	}
	return 0;
}