#include <iostream>
#include <string>
using namespace std;

int a() {
	long n = 0;
	string c;
	cin >> n >> c;
	int D = 0; int K = 0; int S = 0; int H = 0;

	for (int i = 0; i < n; i++) {
		if (c[i] == 'D') {
			D++;
		}
		else if (c[i] == 'K') {
			K += D;
		}
		else if (c[i] == 'S') {
			S += K;
		}
		else if (c[i] == 'H') {
			H += S;
		}
	}
	std::cout << H;

	return 0;
}
