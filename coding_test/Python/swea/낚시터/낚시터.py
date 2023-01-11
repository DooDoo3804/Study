# 낚시터
# 2022-08-27
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
def find_min(gates):
    """최소값 찾기

    정렬된 gates를 받아 이동거리 최소값을 반환하는 함수

    정렬된 gates를 받아서 앞에서 부터 순서대로 거리가 가까운 곳 부터 사람을 채운다
    이때 앞에서 부터 채우는 경우와 뒤에서부터 채우는 경우 두 가지를 모두 진행해 준다
    사람을 채운 거리의 값이 최소가 되면 result에 반영한다

    Args:
        gates (list): 정렬된 gates의 리스트를 받는 함수

    Returns:
        int : result의 값

    """
    global result
    mresult = 0
    visited = [0 for _ in range(N)]
    for gate in gates:
        p = gate[1]
        distance = [N for _ in range(N)]
        for i in range(len(distance)):
            if abs(i + 1 - gate[0]) + 1 < distance[i]:
                distance[i] = abs(i + 1 - gate[0]) + 1
        dmin = 1
        while p != 0:
            for i in range(len(distance)):
                if dmin == distance[i] and visited[i] == 0:
                    visited[i] = 1
                    mresult += distance[i]
                    p -= 1
                    if p == 0:
                        break
            dmin += 1
    if mresult < result:
        result = mresult

    mresult = 0
    visited = [0 for _ in range(N)]
    for gate in gates:
        p = gate[1]
        distance = [N for _ in range(N)]
        for i in range(len(distance)):
            if abs(i+1-gate[0])+1 < distance[i]:
                distance[i] = abs(i+1-gate[0])+1
        dmin = 1
        while p != 0:
            for i in range(len(distance)-1,-1,-1):
                if dmin == distance[i] and visited[i] == 0:
                    visited[i] = 1
                    mresult += distance[i]
                    p -= 1
                    if p == 0 :
                        break
            dmin += 1
    if mresult < result:
        result = mresult

for t in range(1, T+1):
    N = int(input())
    gates = []
    visited = [0 for _ in range(N)]
    for _ in range(3):
        gates.append(list( map(int, input().split())))
    result = 2**N
    # 아래는 정렬된 gates를 정렬하고 최소값을 찾는 과정이다
    # 6가지 정렬에 대해 인덱스로 살펴보면 다음과 같다
    # [0, 1, 2] [0, 2, 1]
    # [1, 0, 2] [1, 2, 0]
    # [2, 0, 1] [2, 1, 0]

    find_min(gates)

    # gate 1차 정렬
    gates[1], gates[2] = gates[2], gates[1]
    find_min(gates)

    # gate 2차 정렬
    gates[1], gates[2] = gates[2], gates[1]
    gates[0], gates[1] = gates[1], gates[0]
    find_min(gates)

    # gate 3차 정렬
    gates[1], gates[2] = gates[2], gates[1]
    find_min(gates)

    # gate 4차 정렬
    gates[1], gates[2] = gates[2], gates[1]
    gates[0], gates[2] = gates[2], gates[0]
    find_min(gates)

    # gate 5차 정렬
    gates[1], gates[2] = gates[2], gates[1]
    find_min(gates)

    print('#{} {}' .format(t, result))

