#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <math.h>

using namespace std;

struct part {
	string name;
	double ri;
	double votes, v_rate, pi;
	double si_prime, si, ti, result;
};

bool comp(vector<double> a, vector<double> b) {
	return a.back() > b.back();
}

bool compp(const part & a, const part & b) {
	if (a.result == b.result) {
		return a.name < b.name;
	}
	return a.result > b.result;
}

vector <part> parties;
vector <int> selected_p;
double non_part = 253;
double effective_vote;

int step1() {
	double sub_sum = 0;
	double return_int = 0;
	double sub_non_part = non_part;

	for (auto & pp : parties) {
		pp.v_rate = pp.votes / effective_vote;
	}

	for (int i = 0; i < parties.size(); i++) {
		auto p = parties[i];
		if (p.ri >= 5 || p.v_rate >= 0.03) {
			selected_p.push_back(i);
			sub_sum += p.votes;
		}
		else sub_non_part += p.ri;
	}
	for (auto i : selected_p) {
		parties[i].pi = parties[i].votes / sub_sum;
		parties[i].si_prime = roundf(((300 - sub_non_part) * parties[i].pi - parties[i].ri) / 2);
		if (parties[i].si_prime <= 1) parties[i].si_prime = 0;
		return_int += parties[i].si_prime;
	}
	return return_int;
}

void step2(int x) {
	vector< vector<double>> under_int;
	double sum_s = 0;
	int assign = 30;

	for (auto i : selected_p) {
		if (parties[i].si_prime != 0) {
			sum_s += parties[i].si_prime;
		}
	}

	for (auto i : selected_p) {
		if (parties[i].si_prime == 0) continue;
		if (x < 30) parties[i].si = parties[i].si_prime + (30 - sum_s) * parties[i].pi;
		else parties[i].si = (30 * parties[i].si_prime / sum_s);
		assign -= floorf(parties[i].si);
		under_int.push_back({ double(i),  parties[i].si - floorf(parties[i].si) });
		parties[i].si = floorf(parties[i].si);
	}
	sort(under_int.begin(), under_int.end(), comp);
	if (assign > 0) {
		int devide = assign / under_int.size();
		int remain = assign % under_int.size();
		for (int i = 0; i < under_int.size(); i++) {
			auto ui = under_int[i];
			parties[ui.front()].si += devide;
			if (i < remain) parties[ui.front()].si += 1;
		}
	}
}

void step3() {
	vector <vector <double>> under_int;
	int assign = 17;

	for (auto i : selected_p) {
		parties[i].ti = 17 * parties[i].pi;
		assign -= floorf(parties[i].ti);
		under_int.push_back({ double(i),  parties[i].ti - floorf(parties[i].ti) });
		parties[i].ti = floorf(parties[i].ti);
	}
	sort(under_int.begin(), under_int.end(), comp);
	if (assign > 0) {
		int devide = assign / under_int.size();
		int remain = assign % under_int.size();
		for (int i = 0; i < under_int.size(); i++) {
			auto ui = under_int[i];
			parties[ui.front()].ti += devide;
			if (i < remain) parties[ui.front()].ti += 1;
		}
	}
	for (auto& p : parties) {
		p.result = p.ri + p.si + p.ti;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int p;
	double v;
	cin >> p >> v;

	for (int i = 0; i < p; i++) {
		string name;
		double seets;
		double votes;
		cin >> name >> seets >> votes;
		parties.push_back({ name, seets, votes, 0, 0, 0, 0, 0, 0 });
		effective_vote += votes;
		non_part -= seets;
	}
	   
	int step1_result = step1();
	step2(step1_result);
	step3();

	sort(parties.begin(), parties.end(), compp);
	for (auto r : parties) {
		cout << r.name << " " << r.result << "\n";
	}
	return 0;
}
