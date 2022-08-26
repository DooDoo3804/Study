import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    N, P = map(int, input().split())
    total_map = []

    # 지도 받기
    for _ in range(N):
        total_map.append(list(map(int, input().split())))

    # 십자 탐색과 대각선 탐색을 모두 진행해 주어야 한다
    # 탐색할 범위를 search_range로 지정하여 모든 탐색 범위를 구해준다
    # 십자 탐색 범위
    search_range = [[0, 0]]
    for i in range(1, P+1):
        search_range.append([0, i])
        search_range.append([0, -i])
        search_range.append([i, 0])
        search_range.append([-i, 0])
    result = 0

    # 십자 탐색
    # 탐색의 조건에 범위 내에서만 진행해야 된다는 것이 없으므로
    # 모든 범위에 대해서 해당되는 영역만 진행해 주면 된다
    for i in range(N):
        for j in range(N):
            sum = 0
            for search in search_range:
                if 0 <= i+search[0] < N and 0 <= j+search[1] < N:
                    sum += total_map[i+search[0]][j+search[1]]
            if sum > result:
                result = sum

    # 대각선 탐색 범위
    search_range = [[0, 0]]
    for i in range(1, P+1):
        search_range.append([i, i])
        search_range.append([i, -i])
        search_range.append([-i, -i])
        search_range.append([-i, i])

    # 십자 탐색과 마찬가지로 모든 범위에서 탐색을 진행하되
    # 해당되는 영역에서만 진행해 주면 된다
    for i in range(N):
        for j in range(N):
            sum = 0
            for search in search_range:
                if 0 <= i+search[0] < N and 0 <= j+search[1] < N:
                    sum += total_map[i+search[0]][j+search[1]]
            if sum > result:
                result = sum
    # 각 탐색을 진행하면서 최대값 보다 영역 합이 더 크면 반환한다
    print('#' + str(t) + ' ' + str(result))