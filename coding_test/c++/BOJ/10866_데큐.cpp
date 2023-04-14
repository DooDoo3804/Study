#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <int> dq;

void dq_push_front(int a) {
	dq.insert(dq.begin(), a);
}

void dq_push_back(int a) {
	dq.push_back(a);
}

void dq_pop_front() {
	if (dq.empty()) cout << -1 << "\n";
	else {
		cout << dq.front() << "\n";
		dq.erase(dq.begin(), dq.begin()+1);
	}
}

void dq_pop_back() {
	if (dq.empty()) cout << -1 << "\n";
	else {
		cout << dq.back() << "\n";
		dq.pop_back();
	}
}

void dq_size() {
	cout << dq.size() << "\n";
}

void dq_empty() {
	if (dq.empty()) cout << 1 << "\n";
	else cout << 0 << "\n";
}

void dq_front() {
	if (dq.empty()) cout << -1 << "\n";
	else {
		cout << dq.front() << "\n";
	}
}

void dq_back() {
	if (dq.empty()) cout << -1 << "\n";
	else {
		cout << dq.back() << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		if (input == "push_back") {
			int input_num;
			cin >> input_num;
			dq_push_back(input_num);
		}
		else if (input == "push_front") {
			int input_num;
			cin >> input_num;
			dq_push_front(input_num);
		}
		else if (input == "pop_front") {
			dq_pop_front();
		}
		else if (input == "pop_back") {
			dq_pop_back();
		}
		else if (input == "size") {
			dq_size();
		}
		else if (input == "empty") {
			dq_empty();
		}
		else if (input == "front") {
			dq_front();
		}
		else if (input == "back") {
			dq_back();
		}
	}

	return 0;
}