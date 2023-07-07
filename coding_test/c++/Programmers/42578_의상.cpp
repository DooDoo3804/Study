#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> all_cloth;
    
    for (auto cloth : clothes) {
        all_cloth[cloth[1]] += 1;
    }

    for (auto &[key, value] : all_cloth) {
        answer *= (value+1);
    }
    return answer-1;
}