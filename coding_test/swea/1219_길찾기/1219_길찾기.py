# 1219_길찾기
# 2022-08-18
import sys
sys.stdin = open('input.txt', 'r')

for _ in range(10):
    t, test_len = map(int, input().split())
    test_list = list(map(int, input().split()))
    node_list = [[] for _ in range(100)]
    move = []
    visited = []
    visited_check = [0 for _ in range(100)]
    for i, v in enumerate(test_list):
        if v == 99 :
            visited.append(test_list[i-1])
        if i % 2 :
            node_list[test_list[i-1]].append(v)
    if visited == []:
        result = 0
    else:
        visited = 0
        visited_check[visited] = 1
        move.append(visited)
        while True:
            if node_list[visited] == []:
                move.pop()
                visited = move[-1]
            for i in node_list[visited]:
                if visited_check[i] == 0:
                    visited = i
                    visited_check[visited] = 1
                    move.append(visited)
                    break
                elif visited_check[i] == 1:
                    move.pop()
                    if move == []:
                        result = 0
                        break
                    visited = move[-1]
            if 99 in node_list[visited]:
                result = 1
                break
            if move == []:
                result = 0
                break
    print('#{} {}' .format(t, result))