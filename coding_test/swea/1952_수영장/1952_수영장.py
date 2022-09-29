# 1952_수영장
# 2022-08-19
import sys
sys.stdin = open('input.txt', 'r')

# 한달의 이용 계획 적은 비용
# 10원 1일
# 40원 1달 1일부터 시작
# 100원 3달 이용권
# 300원 1년은 매년 1월 1일
#
# 1달에 4번이 넘으면 1달사용권
# 3달에 10번이 넘으면 3달 사용권
#     1달 이용권이 3달 이상 연속으로 있으면
# 1년동안 30번이 넘으면 1년 이용권

T = int(input())
for t in range(1, T+1):
    day_fee, month_fee, third_fee, year_fee = map(int, input().split())
    plans = list(map(int, input().split()))
    use_plan = [0 for _ in range(12)]
    # 처음에 전부 1일 이용권 구매
    pay_list = []
    print(day_fee, month_fee, third_fee, year_fee)
    print(plans)

    print(pay_list)