#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int answer = 0;
int pick_stu[10];
int stu, abjs;
void select_stu(int sbj, int sum, vector<vector<int>> &ability) {
    if (sbj == abjs) {
        answer = max(answer, sum);
        return;
    }
    for (int i = 0; i < stu; i++) {
        if (pick_stu[i]) continue;
        else {
            pick_stu[i] = 1;
            select_stu(sbj + 1, sum + ability[i][sbj], ability);
            pick_stu[i] = 0;
        }
    }
}

int solution(vector<vector<int>> ability) {
    stu = ability.size();
    abjs = ability[0].size();
    
    select_stu(0, 0, ability);        
    
    return answer;
}