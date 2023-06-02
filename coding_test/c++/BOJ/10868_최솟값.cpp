#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int tree[400004];

int init(int node, int start, int end)
{
    if (start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

int find_min(int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return 2134567890;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return min(find_min(node * 2, start, mid, left, right), find_min(node * 2 + 1, mid + 1, end, left, right));
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
        int num;
        cin >> num;
        arr.push_back(num);
    }

    init(1, 0, n - 1);

    for (int i = 0; i < m; i++)
    {
        int left;
        int right;
        cin >> left >> right;
        cout << find_min(1, 0, n - 1, left - 1, right - 1) << "\n";
    }

    return 0;
}
