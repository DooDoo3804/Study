#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int k, m;
int answer = 0;
bool visited_check[100001][2];
bool check[10];
vector<int> mul_list;

bool is_prime(int num) {
	if (visited_check[num][0]) return visited_check[num][1];
	visited_check[num][0] = true;
	if (num <= 1) {
		visited_check[num][1] = false;
		return false;
	}
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			visited_check[num][1] = false;
			return false;
		}
	}
	visited_check[num][1] = true;
	return true;
}

bool is_check(int num) {
	fill(check, check + 10, 0);
	while (num) {
		int check_num = num % 10;
		num /= 10;
		if (check[check_num]) return false;
		check[check_num] = 1;
	}
	return true;
}

void get_mul(int k, int m) {
	for (int i = pow(10, k - 1); i < pow(10, k); i++) {
		int sub_num = i;
		if (is_check(i)) {
			while (sub_num % m == 0) {
				sub_num /= m;
			}
			for (int j = 2; j * j <= sub_num; j++) {
				if (sub_num % j == 0 && is_prime(j) && is_prime(sub_num / j)) {
					mul_list.push_back(i);
					break;
				}
			}
		}
	}
}

void get_add() {
	for (int num : mul_list) {
		for (int i = 2; i < num / 2; i++) {
			if (is_prime(i) && is_prime(num - i)) {
				answer++;
				break;
			}
		}
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> k >> m;

	get_mul(k, m);
	get_add();

	cout << answer;

	return 0;
}