#include <iostream>
#include <string>
#include <vector>

using namespace std;

string a;
string b;
string nums;
int n;
int alp[26] = { 3,2,1,2,3,3,2,3,3,2,2,1,2,2,1,2,2,2,1,2,1,1,1,2,2,1 };
vector <int> result;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++) {
		result.push_back(alp[a[i] - int('A')]);
		result.push_back(alp[b[i] - int('A')]);
	}

	 n = result.size();

	 while (n > 2) {
		 vector <int> sub_vector;
		 for (int i = 0; i < n - 1; i++) {
			 int num = 0;
			 num = result[i] + result[i + 1];
			 if (num >= 10) num -= 10;
			 sub_vector.push_back(num);
		 }
		 result = sub_vector;
		 n--;
	 }

	 cout << result[0] << result[1];
	return 0;
}