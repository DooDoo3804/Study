#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long A_perH[1040001] = { 0 };
	// 1. 최소 높이부터 최대 높이까지로 환산하기
	// 2. 이분 탐색으로 부피 계산해서 빼주기
	int min_h = 1000001;
	int max_h = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int b; int h; int w; int d;
		cin >> b >> h >> w >> d;
		for (int j = b; j < b + h; j++) {
			A_perH[j] += w * d;
		}
		min_h = min(min_h, b);
		max_h = max(max_h, b+h);

	}
	long long v;
	cin >> v;

	int right = 1040000;
	int left = 0;


	return 0;
}