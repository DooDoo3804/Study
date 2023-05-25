#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100001];
int max_tree[400001];
int min_tree[400001];

long long max_init(int node, int start, int end)
{
    if (start == end)
    {
        return max_tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return max_tree[node] = max(max_init(node * 2, start, mid), max_init(node * 2 + 1, mid + 1, end));
}
long long min_init(int node, int start, int end)
{
    if (start == end)
    {
        return min_tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return min_tree[node] = min(min_init(node * 2, start, mid), min_init(node * 2 + 1, mid + 1, end));
}

long long max_max(int node, int start, int end, int left, int right)
{
    if (start > right || end < left)
        return -1;
    if (left <= start && end <= right)
        return max_tree[node];
    int mid = (start + end) / 2;
    return max(max_max(node * 2, start, mid, left, right), max_max(node * 2 + 1, mid + 1, end, left, right));
}

long long min_min(int node, int start, int end, int left, int right)
{
    if (start > right || end < left)
        return 2123456789;
    if (left <= start && end <= right)
        return min_tree[node];
    int mid = (start + end) / 2;
    return min(min_min(node * 2, start, mid, left, right), min_min(node * 2 + 1, mid + 1, end, left, right));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    fill(min_tree, min_tree + 400001, 213456789);

    max_init(1, 0, n - 1);
    min_init(1, 0, n - 1);

    for (int i = 0; i < m; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        int left = min(a, b);
        int right = max(a, b);
        cout << min_min(1, 0, n - 1, left - 1, right - 1) << " " << max_max(1, 0, n - 1, left - 1, right - 1) << "\n";
    }

    return 0;
}
