#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n, k;
	cin >> n >> k;

	int nums[16] = { 0 };
	int count = 0;
	int index = 0;
	long long sub_num = n;

	while (sub_num != 0) {
		nums[index] = sub_num % 10;
		if (sub_num % 10 == 5) count++;
		index++;
		sub_num /= 10;
	}

	do {
		for (int i = 0; i < 16; i++) {
			if (count >= k) {
				if (nums[i] == 5) {
					count--;
				}
				nums[i]++;
				break;
			}
			if (nums[i] == 5) continue;
			if (nums[i] % 10 != 5) {
				nums[i] ++;
				index = i;
				while (nums[index] >= 10) {
					nums[index] -= 10;
					if (nums[index + 1] == 5) count--;
					if (++nums[index + 1] == 5) count++;
					index++;
				}
				if (nums[i] == 5) count++;
				break;
			}
		}
	} while (count < k);

	long long answer = 0;
	for (int i = 0; i < 16; i++) {
		answer += nums[i] * pow(10, i);
	}
	cout << answer;
	return 0;
}