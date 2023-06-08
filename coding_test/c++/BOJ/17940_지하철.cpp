#include <iostream>
#include <queue>
#include <algorithm>

#define INF 999999999

using namespace std;

struct node
{
    int to, cost;
};

struct edge
{
    int now, change, cost;
};

bool operator<(edge a, edge b)
{
    if (a.change == b.change)
        return a.cost > b.cost;
    return a.change > b.change;
}

edge result[1001];

int company[1001];
int total_map[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int m;
    cin >> n >> m;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> company[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> total_map[i + 1][j + 1];
        }
    }

    priority_queue<edge> pq;
    pq.push({1, 0, 0});
    int ans[2] = {INF, INF};
    while (!pq.empty())
    {
        auto now_node = pq.top();
        pq.pop();

        if (now_node.now == m + 1)
        {
            if (result[now_node.now].change >= now_node.change)
            {
                ans[0] = min(ans[0], now_node.change);
                ans[1] = min(ans[1], now_node.cost);
            }
        }
        else
        {
            for (int i = 1; i < n + 1; i++)
            {
                if (total_map[now_node.now][i] == 0)
                    continue;
                int next_change = now_node.change;
                if (company[i] != company[now_node.now])
                    next_change++;
                if (result[i].cost == 0 && result[i].change == 0)
                {
                    result[i].change = next_change;
                    result[i].cost = now_node.cost + total_map[now_node.now][i];
                    pq.push({i, next_change, now_node.cost + total_map[now_node.now][i]});
                }
                else if (result[i].change == next_change)
                {
                    if (result[i].cost > now_node.cost + total_map[now_node.now][i])
                    {
                        result[i].cost = now_node.cost + total_map[now_node.now][i];
                        pq.push({i, next_change, now_node.cost + total_map[now_node.now][i]});
                    }
                }
                else if (result[i].change > next_change)
                {
                    result[i].change = next_change;
                    result[i].cost = now_node.cost + total_map[now_node.now][i];
                    pq.push({i, next_change, now_node.cost + total_map[now_node.now][i]});
                }
            }
        }
    }
    cout << ans[0] << " " << ans[1];
    return 0;
}