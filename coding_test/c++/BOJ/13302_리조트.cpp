#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define INF 999999999

using namespace std;

int n;
int dp[303][303];
map<int, int> npos_day;
int ans;

int find_min(int day, int coupon)
{
    if (day > n)
        return 0;
    else if (dp[day][coupon] != INF)
        return dp[day][coupon];
    else if (npos_day[day] == 1)
        return find_min(day + 1, coupon);
    else
    {
        int now = dp[day][coupon];
        now = min(now, find_min(day + 1, coupon) + 10000);
        now = min(now, find_min(day + 3, coupon + 1) + 25000);
        now = min(now, find_min(day + 5, coupon + 2) + 37000);
        if (coupon >= 3)
            now = min(now, find_min(day + 1, coupon - 3));
        if (now > ans)
            ans = now;
        return dp[day][coupon] = now;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin >> n >> m;

    fill(dp[0], dp[101], INF);

    for (int i = 0; i < m; i++)
    {
        int j;
        cin >> j;
        npos_day[j] = 1;
    }

    find_min(1, 0);
    cout << ans;
    return 0;
}

//------------------------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define INF 999999999

using namespace std;

int n;

// 같은 날이라도 보유한 쿠폰에 따라서 결과가 달라짐
int dp[303][303];

// not possible day
map<int, int> npos_day;
int ans;

int find_min(int day, int coupon)
{
	// day 가 n을 넘어가면 종료
	if (day > n)
		return 0;
	// dp가 존재하면 dp 값을 반환
	else if (dp[day][coupon] != INF)
		return dp[day][coupon];
	// not possible day라면 그냥 지나감
	else if (npos_day[day] == 1)
		return find_min(day + 1, coupon);

	// possible day
	else
	{
		/*
		초기 dp를 꺼냄(INF)
			하루 증가한 것
			3일 증가한 것
			5일 증가한 것
			과 각각 비교(재귀로)해서 최소 값을 찾음
		*/ 
		int now = dp[day][coupon];
		/*
		하루 짜리 샀을 때
			day + 1
			+10000원
		*/
		now = min(now, find_min(day + 1, coupon) + 10000);
		/*
		3일 짜리 샀을 때
			day + 3
			쿠폰 + 1
			+25000원
		*/
		now = min(now, find_min(day + 3, coupon + 1) + 25000);
		/*
		5일 짜리 샀을 때
			day + 5
			쿠폰 + 2
			+37000원
		*/
		now = min(now, find_min(day + 5, coupon + 2) + 37000);

		// 만약 쿠폰이 3장이 넘으면 하루 공짜로 진행 / 쿠폰 - 3
		if (coupon >= 3)
			now = min(now, find_min(day + 1, coupon - 3));
		/*
		여기까지 오면 now는 나올 수 있는 최소값
		출력해야하는 ans모다 now가 크면 갱신
		*/ 
		if (now > ans) ans = now;
		// dp에 최소로 뽑힌 now 저장
		return dp[day][coupon] = now;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m;
	cin >> n >> m;

	// 2차원 배열 INF로 초기화
	fill(dp[0], dp[101], INF);

	for (int i = 0; i < m; i++)
	{
		int j;
		cin >> j;
		npos_day[j] = 1;
	}

	// 첫날 1, 쿠폰 0개로 시작
	// 재귀로 진행
	find_min(1, 0);
	cout << ans;
	return 0;
}
