#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    int index = 0;
    vector<int> sub_arr;
    
    for (int i = 1; i < order.size() + 1; i++) {
        sub_arr.push_back(i);
        while (!sub_arr.empty() && sub_arr.back() == order[index]) {
            sub_arr.pop_back();
            index++;
            answer++;
        }
    }
    
    return answer;
}