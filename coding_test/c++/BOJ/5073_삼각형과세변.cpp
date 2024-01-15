#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;
	int arr[3] = { 0 };

	while (true) {
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr + 3);
		a = arr[2]; b = arr[1]; c = arr[0];
		
		if (a == 0 && b == 0 && c == 0) break;

		if (a >= b + c) cout << "Invalid" << '\n';
		else if (a == b && b == c) cout << "Equilateral" << '\n';
		else if (a == b || b == c) cout << "Isosceles" << '\n';
		else cout << "Scalene" << '\n';
	}

	return 0;
}