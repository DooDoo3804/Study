#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int answer = 2134567890;
int visited[100][100];
int moves[4][2] = {{0,1}, {1,0}, {0,-1},{-1,0}};
int n; int m;

struct node{
  int x; int y; int count;  
};

int solution(vector<vector<int>> maps)
{
    n = maps.size();
    m = maps[0].size();
    
    visited[0][0] = 1;
    
    queue<node> q;
    q.push({0, 0, 1});
    
    while(!q.empty()) {
        node now = q.front();
        q.pop();
        for(auto move: moves) {
            int next_x = now.x + move[0];
            int next_y = now.y + move[1];
            if (0 <= next_x && next_x < n && 0 <= next_y && next_y < m and visited[next_x][next_y] == 0 && maps[next_x][next_y] == 1) {
                visited[next_x][next_y] = 1;
                if (now.count >= answer) continue;
                if (next_x == n - 1 && next_y == m - 1) {
                answer = min(answer, now.count + 1);
                continue;
            }
            q.push({next_x, next_y, now.count + 1});
                
           }
        }
    }
    
    
    if (answer == 2134567890) answer = -1;
    return answer;
}