# 1231_중위순회
# 2022-09-13
import sys
sys.stdin = open('input.txt', 'r')

def preorder(v):
    if v:
        preorder(ch1[v])
        print(chars[v], end="")
        preorder(ch2[v])

for t in range(1, 11):
    N = int(input())
    ch1 = [0] * (N + 1)
    ch2 = [0] * (N + 1)
    chars = [0] * (N + 1)
    root = 1
    for _ in range(N):
        infos = list(input().split())
        idx = int(infos[0])
        for i, info in enumerate(infos):
            if info.isnumeric():
                if i == 0 :
                    pass
                elif ch1[idx] == 0:
                    ch1[idx] = int(info)
                else:
                    ch2[idx] = int(info)
            else:
                chars[idx] = info
    # print(ch1)
    # print(ch2)
    print('#{}' .format(t), end=" ")
    preorder(root)
    print()
