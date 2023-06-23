#include<iostream>
#include<algorithm>

using namespace std;

long long arr[100001];
long long tree[400004];

long long init(int node, int start, int end) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

void update(int node, int start, int end, int index, int diff) {
	if (!(start <= index && index <= end)) return;
	if (start == end) {
		tree[node] = diff;
		return;
	}
	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, index, diff);
		update(node * 2 + 1, mid + 1, end, index, diff);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
}

long long querry(int node, int start, int end, int left, int right) {
	if (end < left || right < start) return 2134567890;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return min(querry(node * 2, start, mid, left, right), querry(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	init(1, 0, n - 1);

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a; int b; int c;
		cin >> a >> b >> c;
		if (a == 1) {
			arr[b -1] = c;
			update(1, 0, n - 1, b - 1, c);
		}
		if (a == 2) {
			long long num = querry(1, 0, n - 1, b - 1, c - 1);
			for (int i = b - 1; i < c; i++) {
				if (arr[i] == num) {
					cout << i + 1 << "\n";
					break;
				}
			}
		}
	}

	return 0;
}