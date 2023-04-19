#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 999999999

vector<int[3]> nodes[101];
int t;

vector<int> dijkstra(int n)
{
    vector<int> cost(n, INF);
    priority_queue<int[3]> pq;

    cost[1] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty())
    {
        int now_cost = pq.top()[0];
        int now_node = pq.top()[1];
        int now_time = pq.top()[2];
        pq.pop();

        for (int i = 0; i < nodes[now_node].size(); i++)
        {
            int nxt_cost = nodes[now_node][i][0];
            int nxt_node = nodes[now_node][i][1];
            int nxt_time = nodes[now_node][i][2];

            if (now_time + nxt_time <= cost[nxt_node] > now_cost + nxt_cost)
            {
                cost[nxt_node] = now_cost + nxt_cost;
                pq.push({-(now_cost + nxt_cost), nxt_node, now_time + nxt_time});
            }
        }
    }
    return cost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int m;
    int l;
    cin >> n >> t >> m >> l;

    for (int i = 0; i < l; i++)
    {
        int s_a;
        int s_b;
        int s_t;
        int s_c;
        cin >> s_a >> s_b >> s_t >> s_c;
        nodes[s_a].push_back({s_b, s_t, s_c});
        nodes[s_b].push_back({s_a, s_t, s_c});
    }

    return 0;
}