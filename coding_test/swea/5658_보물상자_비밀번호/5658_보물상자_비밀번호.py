# 5658_보물상자_비밀번호
# 2022-08-19
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for t in range(1, T+1):
    N, K = map(int, input().split())
    char_list = list(input())
    char_key = []
    char_16 = [10, 11, 12, 13, 14, 15]
    for n in range(N):
        inlist = []
        for i, v in enumerate(char_list):
            move_idx = i+n
            if move_idx >= N:
                move_idx -= N
            inlist.append(char_list[move_idx])
        char_key.append(inlist)
    result_list = []

    for i in range(N):
        inlist=[]
        for j in range(N):
            if j % (N//4) == (N//4-1):
                inlist.append(char_key[i][j])
                result_list.append(inlist)
                inlist = []
            else :
                inlist.append(char_key[i][j])

    final_list = []
    count = 0

    for char in result_list:
        if char not in final_list:
            final_list.append(char)
            count += 1

    for i in range(count):
        for j in range(i):
            for k in range(N//4):
                if final_list[j][k] < final_list[i][k] :
                    final_list[i], final_list[j] = final_list[j], final_list[i]
                    break
                elif final_list[j][k] == final_list[i][k]:
                    continue
                else : break
    result = 0
    for i, char in enumerate(final_list[K-1]):
        if char is not int :
            if char == 'A':
                char = char_16[0]
            if char == 'B':
                char = char_16[1]
            if char == 'C':
                char = char_16[2]
            if char == 'D':
                char = char_16[3]
            if char == 'E':
                char = char_16[4]
            if char == 'F':
                char = char_16[5]
        result += int(char) * 16**(N//4-i-1)
    print('#{} {}' .format(t, result))
