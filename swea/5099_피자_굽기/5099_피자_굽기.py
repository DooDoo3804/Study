# 5099_피자_굽기
# 2022-08-25
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
def rotate(array):
    """
    피자 배열을 받아서 1이 될 때까지 회전한 배열을 반환하는 함수

    피자 배열 array를 받고 array[0]을 2로 나눠서 0 이 됨을 확인하면
    그 배열을 반환한다. 이때 피자의 초기 인덱스 또한 같이 작업한다

    Args:
        array [list]: N만큼 채운 피자 배열

    Returns:
        list : array[0] // 2가 0이 된 것을 확인한 피자 배열
    """
    while True:
        check = array[0]
        if check // 2 != 0:
            check = array.pop(0)
            array.append(check//2)
            pizza_idx.append(pizza_idx.pop(0))
        elif check // 2 == 0:
            return array
def remain1(array):
    """
    피자 배열을 받아 //2가 0이 되면 제거하고 남은 피자 하나를 반환하는 함수

    rotate와는 다르게 추가되는 피자가 없이 0이 되면 제거를 하고
    같은 과정을 반복하여 하나의 피자가 남을 때 까지 진행한다.
    이때 피자의 인덱스도 같이 작업한다.

    Args:
        array (list): N개의 피자의 배열

    Returns:
            int: 마지막으로 남은 피자의 순서 (인덱스+1)
    """
    while True:
        cnt = 0
        check = array[0]
        if check // 2 != 0:
            check = array.pop(0)
            array.append(check//2)
            pizza_idx.append(pizza_idx.pop(0))
        elif check // 2 == 0:
            array.pop(0)
            pizza_idx.pop(0)
        # 치즈가 제거될 때마다 피자의 개수를 확인하고
        # 1개가 남으면 종료한다
        for _ in array:
            cnt += 1
        if cnt == 1 :
            return pizza_idx[0]+1

for t in range(1, 1+T):
    N, M = map(int, input().split())
    pizzas = list(map(int, input().split()))
    queue = [] * N
    pizza_idx = [] * N

    for i in range(M):
        # M개의 피자를 N개의 화덕에 집어넣는데 꽉차면
        # rotate를 시켜준다
        if i < N :
            queue.append(pizzas[i])
            pizza_idx.append(i)

        if i == N-1:
            queue = rotate(queue)

        # rotate가 1회 진행된 이후에는 0이 될 맨 앞의 피자에 다음 피자를
        # 넣어주고 마지막 피자를 넣을 때 까지 반복한다
        if i >= N:
            queue[0] = pizzas[i]
            pizza_idx[0] = i
            queue = rotate(queue)
    # 피자를 다 넣었으면 추가되는 피자가 없으므로 remain1을 통해
    # 하나의 마지막 피자를 선정한다
    print('#{} {}' .format(t, remain1(queue)))

