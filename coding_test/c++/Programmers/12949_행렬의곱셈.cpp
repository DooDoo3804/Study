#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for (int i = 0; i < arr1.size(); i++) {
        vector<int> sub_vector;
        for (int j = 0; j < arr2[0].size(); j++) {
            int sub_num = 0;
            for (int k = 0; k < arr1[i].size(); k++) {
                sub_num += arr1[i][k] * arr2[k][j];
            }
            sub_vector.push_back(sub_num);
        }
        answer.push_back(sub_vector);
    }
    
    return answer;
}