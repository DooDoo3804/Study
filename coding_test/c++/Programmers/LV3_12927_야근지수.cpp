#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<int> pq;
    for (auto w: works) pq.push(w);
    for (int i = 0; i < n; i++) {
        if (pq.empty()) break;
        int now = pq.top();
        pq.pop();
        if (now - 1 != 0) pq.push(now - 1);
    }

    while(!pq.empty()) {
        int now = pq.top();
        pq.pop();
        answer += pow(now, 2);
    }

    return answer;
}