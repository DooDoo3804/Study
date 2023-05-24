#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct card
{
    int card, count;
};

bool operator<(card a, card b)
{
    return a.card > b.card;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    cin >> n;

    priority_queue<card> cards;
    int dp[100001] = {0};

    for (int i = 0; i < n; i++)
    {
        int card;
        cin >> card;
        cards.push({card, card});
    }

    int ans = 0;

    while (cards.size() >= 2)
    {
        card f_card = cards.top();
        cards.pop();
        card s_card = cards.top();
        cards.pop();
        ans += f_card.card + s_card.card;
        cards.push({f_card.card + s_card.card, f_card.card + s_card.card});
    }

    cout << ans;
    return 0;
}
