#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(vector <int> a, vector <int> b) {
	return a[1] < b[1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector <vector <int>> num_price;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		vector <int> sub_vec;
		int a;
		cin >> a;
		sub_vec.push_back(i);
		sub_vec.push_back(a);
		num_price.push_back(sub_vec);
	}

	sort(num_price.begin(), num_price.end(), compare);

	return 0;
}