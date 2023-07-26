#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> q;
    
    for (int i = 0; i < discount.size() - 9; i++) {
        bool check = true;
        for (string stuff : want) {
            q[stuff] = 0;
        }
        for (int j = 0; j < 10; j++) {
            int index = i + j;
            q[discount[index]]++;
        }
        for (int j = 0; j < want.size(); j++) {
            if (q[want[j]] < number[j]) {
                check = false;
                break;
            }
            
        }
        if (check) answer++;
    }
    return answer;
}