#include<iostream>
#include<string>
#include<set>
#include<map>

using namespace std;

int n, m;

struct problem {
	int p, l;
	bool operator<(const problem &rhs) const {
		if (l == rhs.l) return p < rhs.p;;
		return l < rhs.l;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	multiset<problem> problems;
	map<int, multiset<problem>::iterator> problem_map;

	for (int i = 0; i < n; i++){
		int p, l;
		cin >> p >> l;
		auto it = problems.insert({ p, l });
		problem_map[p] = it;
	}
	
	cin >> m;
	
	string cmd;
	int num;

	for (int i = 0; i < m; i++) {
		cin >> cmd;
		if (cmd == "add") {
			int p, l;
			cin >> p >> l;
			auto it = problems.insert({ p, l });
			problem_map[p] = it;
		}
		else if (cmd == "solved") {
			int num;
			cin >> num;
			auto it = problem_map.find(num);
			if (it != problem_map.end()) {
				problems.erase(it->second);
				problem_map.erase(it);
			}

		}
		else if (cmd == "recommend") {
			int num;
			cin >> num;
			if (num == 1) cout << problems.rbegin()->p << "\n";
			else cout << problems.begin()->p << "\n";
		}
	}

	return 0;
}