#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> menu, vector<int> order, int k) {
    int now = 0;
    int make_time = 0;
    int index = 1;
    queue<int> q;
    q.push(menu[order[0]]);
    int answer = 1;
    
    while (!q.empty()) {
        now += k;

        while (!q.empty() && make_time + q.front()<= now) {
            make_time += q.front();
            q.pop();
        }
        
        if (index < order.size()) {
            if (q.empty()) make_time = now;
            q.push(menu[order[index]]);
            index ++;
        }
        
        int n = q.size();
        answer = max(answer, n);
    }
    return answer;
}