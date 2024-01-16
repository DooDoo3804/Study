#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 2134567890;
    vector<vector<int>> nodes(n + 1);
    
    for (auto wire : wires) {
        nodes[wire[0]].push_back(wire[1]);
        nodes[wire[1]].push_back(wire[0]);
    }
    
    for (auto wire : wires) {
        int visited[101] = { 0 };
        int from = wire[0];
        int to = wire[1];
        int cnt1 = 0;
        int cnt2 = 0;

        function<void(int, int&)> dfs = [&] (int now, int &cnt) {
            visited[now] = 1;
            cnt++;
            for (int next : nodes[now]) {
                if (!visited[next]) dfs(next, cnt);
            }
        };
        
        nodes[from].erase(find(nodes[from].begin(), nodes[from].end(), to));
        nodes[to].erase(find(nodes[to].begin(), nodes[to].end(), from));
            
        dfs(from, cnt1);
        dfs(to, cnt2);
        
        answer = min(answer, abs(cnt1 - cnt2));
        
        nodes[from].push_back(to);
        nodes[to].push_back(from);
    }
    
    return answer;
}