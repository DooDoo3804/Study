# 4881_배열_최소_합
# 2022-08-23
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
# now row를 입력받아 해당 행에서 값을 차례로 넣어 최소 값을 탐색하는 함수
def find_min(now_row):
    global now_sum, min_result
    if now_row >= N :
        if now_sum[-1] < min_result:
            min_result = now_sum[-1]
            now_sum.pop()
            visited_col.pop()
        return
    for j in range(N):
        if array[now_row][j] + now_sum[-1] < min_result and j not in visited_col:
            now_sum.append(now_sum[-1] + array[now_row][j])
            visited_col.append(j)
            find_min(now_row+1)
        elif array[now_row][j] + now_sum[-1] > min_result:
            pass
    if now_row == 0 :
        return
    now_sum.pop()
    visited_col.pop()

for t in range(1, T+1):
    N = int(input())
    array = []
    visited_col = []
    for _ in range(N):
        array.append(list(map(int, input().split())))
    now_sum = [0]
    min_result = 999999999
    find_min(0)
    print('#{} {}' .format(t, min_result))