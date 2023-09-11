#include<iostream>
#include <string>
#include <vector>
#include<queue>

using namespace std;

struct abil {int aa, bb;};

bool operator<(abil a, abil b) {
    return a.aa > b.aa;
}

int solution(vector<int> ability, int number) {
    int answer = 0;
    
    priority_queue<abil> q;
    
    for (auto ab : ability) q.push({ab, 0});
    
    while (number--) {
        int a = q.top().aa; q.pop();
        int b = q.top().aa; q.pop();
        cout << a << " " << b;
        q.push({ a + b, 0 });
        q.push({ a + b, 0 });
    }
    
    while (!q.empty()) {
        answer += q.top().aa;
        q.pop();
    }
    
    return answer;
}