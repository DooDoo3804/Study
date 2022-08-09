# 4834_숫자카드
# 2022-08-09
import sys, copy
sys.stdin = open('input.txt', 'r')
T = int(input())
for t in range(1, T+1):
    card_cnt = [0] * 10
    cards_num = int(input())
    cards = list(input())
    maxidx = 0
    for card in cards:
        card_cnt[int(card)] += 1
    card_clone = copy.deepcopy(card_cnt)
    for i in range(0, 10):
        for j in range(0, i):
            if card_cnt[j] > card_cnt[i] :
                card_cnt[j], card_cnt[i] = card_cnt[i], card_cnt[j]
    for idx, count in enumerate(card_clone):
        if count == card_cnt[-1]:
            maxidx = idx
    print('#{} {} {}' .format(t, maxidx, card_clone[maxidx]))