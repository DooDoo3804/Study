#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long arr[2000001] = {0};
long long tree[8000004] = {0};

struct node
{
    long long left;
    long long right;
};

bool comp(node a, node b)
{
    if (a.left == b.left)
        return a.right < b.right;
    return a.left < b.left;
}

long long init(int node, int start, int end)
{
    if (start == end)
    {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int index)
{
    if (!(start <= index && index <= end))
        return;
    tree[node] += 1;
    if (start == end)
        return;
    if (start != end)
    {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index);
        update(node * 2 + 1, mid + 1, end, index);
    }
}

long long sum_num(int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return sum_num(node * 2, start, mid, left, right) + sum_num(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int m;
    cin >> n >> m;

    vector<node> nodes;

    for (int i = 0; i < m; i++)
    {
        int left;
        int right;
        cin >> left >> right;
        nodes.push_back({left, right});
    }

    sort(nodes.begin(), nodes.end(), comp);

    long long ans = 0;

    for (int i = 0; i < m; i++)
    {
        auto n_node = nodes[i];
        ans += sum_num(1, 0, n - 1, n_node.right, n - 1);
        // cout << ans << "\n";
        update(1, 0, n - 1, n_node.right - 1);
    }
    cout << ans;
    return 0;
}
