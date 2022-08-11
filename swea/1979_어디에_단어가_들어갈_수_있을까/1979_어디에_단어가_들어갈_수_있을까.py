# 1979_어디에_단어가_들어갈_수_있을까
# 2022-08-11

import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for t in range(1, T+1):
    N, K = map(int, input().split())
    puzzle_map = []
    for _ in range(N):
        puzzle_map.append(list(map(int, input().split())))
    # 가로 탐색
    count = 0
    for i in range(N):
        word_len = 0
        for j in range(N):
            if puzzle_map[i][j] == 0:
                if word_len == K:
                    count += 1
                word_len = 0
            elif puzzle_map[i][j] == 1:
                word_len += 1
                if j == N-1 and word_len == K:
                    count += 1
        # 세로 탐색
    for i in range(N):
        word_len = 0
        for j in range(N):
            if puzzle_map[j][i] == 0:
                if word_len == K:
                    count += 1
                word_len = 0
            elif puzzle_map[j][i] == 1:
                word_len += 1
                if j == N-1 and word_len == K:
                    count += 1
    print('#{} {}' .format(t, count))