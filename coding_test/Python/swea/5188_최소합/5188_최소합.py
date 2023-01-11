# 5188_최소합
# 2022-09-21
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
directions = [[0, 1], [1, 0],]

def find_way(now):
    """
    현재 위치 now를 입력받아 길을 찾아 움직이는 함수
    Args:
        now (list): 현재 위치의 인덱스 리스트 [i, j]

    Returns:
        int: 경로의 모든 숫자의 합이 최소가 되는 값을 찾아
            이를 반환
    """
    global sub_sum, result
    if sub_sum > result :
        return
    if now == end :
        if sub_sum < result :
            result = sub_sum
        return
    for direction in directions:
        di = now[1] + direction[1]
        dj = now[0] + direction[0]
        if 0<= di < n and 0<= dj < n and visited[dj][di] == 0:
            sub_sum += total_map[dj][di]
            visited[dj][di] = 1
            find_way([dj, di])
            visited[dj][di] = 0
            sub_sum -= total_map[dj][di]

for t in range(1, 1+T):
    n = int(input())
    total_map = [[] for _ in range(n)]
    visited = [[0 for _ in range(n)] for _ in range(n)]
    visited[0][0] = 1
    for i in range(n):
        total_map[i] = list(map(int,input().split()))
    sub_sum = total_map[0][0]
    result = 10**6
    start = [0, 0]
    end = [n-1, n-1]
    find_way(start)
    print('#{} {}' .format(t, result))
