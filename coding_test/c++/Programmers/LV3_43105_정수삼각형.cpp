#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int h = triangle.size();
    int dp[502][502] = {0};
    
    for (int i = 0 ; i < h; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            dp[i + 1][j + 1] = max(dp[i][j] + triangle[i][j], dp[i][j+1] + triangle[i][j]);
        }
    }
    
    for (int i = 1; i <= h; i++)
        answer = max(answer, dp[h][i]);
    
    return answer;
}