#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 2134567890

using namespace std;

int moves[4][2] = {{0, 1}, {-1, 0}, {1,0}, {0, -1}};
int dp[1001][1001][2];
int visited[1001][1001][2];
int total_map[1001][1001];

struct coord {
    int x, y, cnt, jump;
};

bool operator< (coord a, coord b) {
    return a.cnt > b.cnt;
}


int solution(int n, int m, vector<vector<int>> hole) {
    int answer = 0;
    
    for (auto h: hole) total_map[h[1]][h[0]] = -1;
    
    for (int i = 1; i< m+1; i++) 
        for (int j = 1; j< n+1; j++) 
            dp[i][j][0] = dp[i][j][1] = INF;
    visited[1][1][0] = visited[1][1][1] = 1;
    
    priority_queue<coord> q;
    q.push({ 1, 1, 0, 0 });
    
    while(!q.empty()) {
        auto now = q.top();
        q.pop();
        if (dp[now.x][now.y][now.jump] < now.cnt) continue;
        for (auto move : moves) {
            for (int i = 1;  i <= 2; i++) {
                if (i == 2 && now.jump == 1) continue;
                int next_x = now.x + move[0] * i;
                int next_y = now.y + move[1] * i;
                
                if (1 <= next_x && next_x <= m && 1 <= next_y && next_y <= n && total_map[next_x][next_y] != -1) {
                    if (dp[next_x][next_y][(i == 2) || now.jump] < now.cnt + 1) continue;
                    if (dp[next_x][next_y][(i == 2) || now.jump] != INF) continue;
                    dp[next_x][next_y][(i == 2) || now.jump] = now.cnt + 1;
                    q.push({ next_x, next_y, now.cnt + 1, (i == 2) || now.jump });
                }
            }
        }
    }
    
    answer = min(dp[m][n][0], dp[m][n][1]);
    if (answer == INF) answer = -1;
    
    return answer;
}