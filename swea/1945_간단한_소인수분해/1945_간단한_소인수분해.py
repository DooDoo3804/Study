# 1945_간단한_소인수분해
# 2022-08-09
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for t in range(1, T+1):
    factors = [2, 3, 5, 7, 11]
    factor_cnt = [0, 0, 0, 0, 0]
    # 인수와 인수카운트
    number = int(input())
    while number != 1:
        for idx, factor in enumerate(factors):
            while number % factor == 0:
                number /= factor
                factor_cnt[idx] += 1
    print('#{} {} {} {} {} {}' .format(t, factor_cnt[0], factor_cnt[1], factor_cnt[2], factor_cnt[3], factor_cnt[4]))