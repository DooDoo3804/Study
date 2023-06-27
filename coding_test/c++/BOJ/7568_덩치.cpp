#include <iostream>
#include <vector>

using namespace std;

struct person {
	int weight, height, p_count, ranking;
};

vector<person> person_list;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int weight; int height;
		cin >> weight >> height;
		person_list.push_back({ weight, height, 1, 0});
	}

	for (int i = 0; i < person_list.size(); i++) {
		person check_person = person_list[i];
		for (int j = 0; j < person_list.size(); j++) {
			if (i != j) {
				if (check_person.height < person_list[j].height && check_person.weight < person_list[j].weight) {
					person_list[i].p_count++;
				}
			}
		}
		cout << person_list[i].p_count << " ";
	}

	return 0;
}