# 1225_암호생성기
# 2022-08-24

import sys
sys.stdin = open('input.txt', 'r')

for _ in range(10):
    t = int(input())
    num_list = list(map(int, input().split()))
    cycle = True
    while cycle:
        # num_list의 0을 pop하여 (i+1)을 빼고 0보다 작거나 같으면 0을 뒤에 추가하고 종료
        # 아니면 차를 뒤에 추가하고 계속 진행
        for i in range(5):
            num = num_list.pop(0) - (i+1)
            if num <= 0:
                num_list.append(0)
                cycle = False
                break
            else:
                num_list.append(num)
    print('#{}' .format(t), end= ' ')
    print(*num_list)