# 5203_베이비진_게임
# 2022-09-22
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    cards = list(map(int, input().split()))
    player1 = {i:0 for i in range(10)}
    player2 = {i: 0 for i in range(10)}
    result = 0
    runs = []
    flag = False
    for i in range(8):
        runs.append([i, i+1, i+2])
    while cards:
        a = cards.pop(0)
        b = cards.pop(0)
        player1[a] += 1
        for run_card in runs:
            if 0 not in [player1[run_card[0]],player1[run_card[1]],player1[run_card[2]]] or 3 in list(player1.values()):
                result = 1
                flag = True
                break
        if flag:
            break
        player2[b] += 1
        for run_card in runs:
            if 0 not in [player2[run_card[0]],player2[run_card[1]],player2[run_card[2]]] or 3 in list(player2.values()):
                result = 2
                flag = True
                break
        if flag:
            break

    print('#{} {}' .format(t, result))