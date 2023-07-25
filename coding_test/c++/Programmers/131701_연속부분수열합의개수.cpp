#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    map<int, int> q;
    for (int i = 1; i < elements.size() + 1; i ++) {
        for (int j = 0; j < elements.size(); j++) {
            int count = 0;
            int sub_sum = 0;
            while (count != i) {
                int index = count + j;
                if (index >= elements.size()) index -= elements.size();
                sub_sum += elements[index];
                count++;
            }
            q[sub_sum] = 0;
        }
    }
    answer = q.size();
    return answer;
}