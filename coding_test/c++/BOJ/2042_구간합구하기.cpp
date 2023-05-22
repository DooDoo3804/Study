#include <iostream>

using namespace std;

long long arr[1000001];
long long tree[4000001];

/*
    기본형
    아래 3개의 함수가 세그먼트 트리를 구성하는 함수들
    array 말고 vector 를 사용하기도 함
*/

// 더하면서 만든 세그먼트트리 초기 값
long long init(int node, int start, int end)
{
    if (start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

// index의 값을 diff 만큼 차이나는 값으로 변경할 때
void update(int node, int start, int end, int index, long long diff)
{
    if (!(index >= start && index <= end))
        return;
    tree[node] += diff;
    if (start != end)
    {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

// 구간 [left right] 안에 존재하는 값들의 합을 구하는 경우
long long sum(int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    long long m;
    long long k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    init(1, 0, n - 1);

    for (int i = 0; i < m + k; i++)
    {
        long long a;
        long long b;
        long long c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(1, 0, n - 1, b - 1, c - arr[b - 1]);
            arr[b - 1] = c;
        }
        else if (a == 2)
            cout << sum(1, 0, n - 1, b - 1, c - 1) << "\n";
    }
    return 0;
}
