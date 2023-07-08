#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> work_list;
    
    for (int i = 0; i < progresses.size(); i++) {
        if ((100 - progresses[i]) % speeds[i]) {
            work_list.push((100 - progresses[i]) / speeds[i] + 1);
        }
        else {
            work_list.push((100 - progresses[i]) / speeds[i]);
        }
    }
    while (!work_list.empty()) {
        int sub_sum = 1;
        int now = work_list.front();
        work_list.pop();
        while (!work_list.empty()) {
            int next = work_list.front();
            if (next <= now) {
                sub_sum++;
                work_list.pop();
            }
            else break;
        }
        answer.push_back(sub_sum);
    }
    
    return answer;
}