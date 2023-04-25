#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;
    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++)
        q.push(i);
    int index = 0;
    int result = 0;
    while (q.size() > 1)
    {
        if (index % 2)
        {
            int nn = 0;
            nn = q.front();
            q.pop();
            q.push(nn);
        }
        else
            q.pop();
        index++;
    }
    cout << q.front();
    return 0;
}