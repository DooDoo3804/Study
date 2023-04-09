#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input_str;
	cin >> input_str;

	long long index = 0;
	string q;

	queue <long long> nums_q;
	vector <int> operators_q;
	while (index < input_str.size()) {
		if (input_str[index] == 'O' && input_str[index + 1] == 'N' && input_str[index + 2] == 'E') {
			q += '1';
			index += 3;
		}
		else if (input_str[index] == 'E' && input_str[index + 1] == 'I' && input_str[index + 2] == 'G' && input_str[index + 3] == 'H' && input_str[index + 4] == 'T') {
			q += '8';
			index += 5;
		}
		else if (input_str[index] == 'N'&& input_str[index + 1] == 'I'&& input_str[index + 2] == 'N'&& input_str[index + 3] == 'E') {
			q += '9';
			index += 4;
		}
		else if (input_str[index] == 'Z'&&input_str[index + 1] == 'E'&&input_str[index + 2] == 'R'&&input_str[index + 3] == 'O') {
			q += '0';
			index += 4;
		}
		else if (input_str[index] == 'T'&&input_str[index + 1] == 'W'&&input_str[index + 2] == 'O') {
			q += '2';
			index += 3;
		}
		else if (input_str[index] == 'T' && input_str.at(index + 1) == 'H'&& input_str[index + 2] == 'R' && input_str.at(index + 3) == 'E'&&input_str.at(index + 4) == 'E') {
			q += '3';
			index += 5;
		}
		else if (input_str[index] == 'F'&&input_str[index + 1] == 'O'&&input_str[index + 2] == 'U'&&input_str[index + 3] == 'R') {
			q += '4';
			index += 4;
		}
		else if (input_str[index] == 'F'&&input_str[index + 1] == 'I'&&input_str[index + 2] == 'V'&&input_str[index + 3] == 'E') {
			q += '5';
			index += 4;
		}
		else if (input_str[index] == 'S'&&input_str[index + 1] == 'I'&&input_str[index + 2] == 'X') {
			q += '6';
			index += 3;
		}
		else if (input_str[index] == 'S'&&input_str[index + 1] == 'E'&&input_str[index + 2] == 'V'&&input_str[index + 3] == 'E'&&input_str[index + 4] == 'N') {
			q += '7';
			index += 5;

		}
		else {
			if (input_str[index] >= 'A' && input_str[index] <= 'Z') {
				cout << "Madness!";
				return 0;
			}
			else if (q.back() == '+' || q.back() == '/' || q.back() == '-' || q.back() == 'x') {
				cout << "Madness!";
				return 0;
			}
			else {
				q += (input_str[index]);
				index += 1;
			}
		}
	}

	string sub_num;
	for (long long i = 0; i < q.size(); i++) {
		cout << q[i];
		if (q[i] >= '0' && q[i] <= '9') {
			sub_num += q[i];
		}
		else {
			if (q[i] == '+') operators_q.push_back(1);
			else if (q[i] == '-') operators_q.push_back(2);
			else if (q[i] == 'x') operators_q.push_back(3);
			else if (q[i] == '/') operators_q.push_back(4);
			nums_q.push(stoi(sub_num));
			sub_num = "";
		}
	}

	cout << "\n";
	long long result = 0;

	for (int i = 0; i < operators_q.size() + 1; i++) {
		if (i == 0) {
			result = nums_q.front();
			nums_q.pop();
		}
		else if (operators_q[i - 1] == 1) {
			result += nums_q.front();
			nums_q.pop();
		}
		else if (operators_q[i - 1] == 2) {
			result -= nums_q.front();
			nums_q.pop();
		}
		else if (operators_q[i - 1] == 3) {
			result *= nums_q.front();
			nums_q.pop();
		}
		else if (operators_q[i - 1] == 4) {
			result /= nums_q.front();
			nums_q.pop();
		}
		else break;
	}
	string result_str = to_string(result);
	bool minus = false;
	if (result < 0) {
		result *= -1;
		minus = !minus;
	}
	string num_list[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
	for (char s : result_str) {
		if (s == '-') cout << '-';
		else cout << num_list[int(s) - '0'];
	}
	return 0;
}