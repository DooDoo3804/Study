import sys
sys.stdin = open('input.txt', 'r')

for _ in range(1, 11):
    t = int(input())
    total_table = []
    for i in range(100):
        total_table.append(str(input()))
    target_hrz_row = target_hrz_col = target_ver_row = target_ver_col = 0
    count = 0
    for i in range(100):
        for j in range(1, 100):
            # 회문의 길이 j
            for k in range(99-j):
                for m in range(j):
                    if total_table[i][k+m-1] == total_table[i][k + j - m - 1]:
                        count += 1
                    else :
                        count = 0
                        break
                if count == int(k / 2)+1:
                    target_hrz_col = k
                    target_hrz_row = i
                    hrz = True
    print(i, j)