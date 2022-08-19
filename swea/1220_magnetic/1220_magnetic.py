# 1220_magnetic
# 2022-08-19
import sys
sys.stdin = open('input.txt', 'r')
# 1 : N극 // 2 : S극

for t in range(1, 11):
    N = int(input())
    magnetic_list = []
    for n in range(N):
        magnetic_list.append(list(map(int, input().split())))
    # 90도 회전 즉 왼쪽이 N극 오른쪽이 S극
    for i in range(N):
        for j in range(i, N):
            magnetic_list[i][j], magnetic_list[j][i] = magnetic_list[j][i], magnetic_list[i][j]

    for i in range(N):
        for j in range(N):
            if magnetic_list[i][j] == 2 :
                magnetic_list[i][j] = 0
            elif magnetic_list[i][j] == 1 :
                break
            # 왼쪽부터 탐색이므로 만나는 S극을 지운다. N극을 만나면 종료
    stack = [0]
    count = 0
    for i in range(N):
        for j in range(N):
            if stack[-1] == 1 and magnetic_list[i][j] == 2:
                stack.append(magnetic_list[i][j])
                count +=1
            elif stack[-1] == 1 and magnetic_list[i][j] == 1:
                stack.append(magnetic_list[i][j])
            elif stack[-1] == 2 and magnetic_list[i][j] == 2:
                stack.append(magnetic_list[i][j])
            elif magnetic_list[i][j] == 0:
                continue
            else:
                stack.append(magnetic_list[i][j])
    print('#{} {}' .format(t, count))

