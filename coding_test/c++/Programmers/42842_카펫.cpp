#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total_tile = brown + yellow;
    int vertical = 0;
    int horizon = 0;
    
    for (int i = 1; i <= sqrt(yellow); i++) {
        if (yellow % i == 0) {
            horizon = yellow / i;
            vertical = i;
            if ((horizon + 2) * (vertical + 2) == total_tile) {
                answer.push_back(horizon + 2);
                answer.push_back(vertical + 2);
            }
        }
    }
    
    return answer;
}