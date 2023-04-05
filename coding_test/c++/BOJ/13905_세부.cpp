#include <iostream>

using namespace std;

int result[100001] = { 0 };

int main() {
	int n = 0;
	int m = 0;
	cin >> n >> m;
	int parent[100001] = { 0 };
	int apl[100001] = { 0 };
	
	for (int i = 1; i < n+1; i++) {
		int sub_int = 0;
		cin >> sub_int;
		parent[i] = sub_int;
	}
	
	for (int i = 0; i < m; i++) {
		int a = 0;
		int b = 0;
		cin >> a >> b;
		apl[a] += b;
	}
	
	for (int i = 1; i < n+1; i++) {
		if (i == 1) {
			result[i] = 0;
		}
		else {
			result[i] = apl[i] + result[parent[i]];
		}
	}

	for (int i = 1; i < n+1; i++) {
		cout << result[i] << " ";
	}
	return 0;
}