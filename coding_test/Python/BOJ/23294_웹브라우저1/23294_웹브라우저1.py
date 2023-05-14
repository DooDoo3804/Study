import sys


def backward(p):
    if len(back_pages):
        next_pages.append(p)
        return back_pages.pop(-1)
    else:
        return p


def forward(p):
    if len(next_pages):
        back_pages.append(p)
        return next_pages.pop(-1)
    else:
        return p


def access(p, r):
    global total_cache
    for i in next_pages:
        total_cache -= cache_list[i-1]
    next_pages.clear()

    total_cache += cache_list[r - 1]

    if now_page:
        back_pages.append(p)
        while total_cache > c:
            total_cache -= cache_list[back_pages.pop(0) - 1]
    return r


def compress():
    global total_cache
    sub_list = []
    pre = 0
    for bp in back_pages:
        if pre == bp:
            total_cache -= cache_list[bp-1]
        else:
            sub_list.append(bp)
        pre = bp
    return sub_list


back_pages = []
next_pages = []
# OLD ... NEW
n, q, c = map(int, sys.stdin.readline().split())
cache_list = list(map(int, sys.stdin.readline().split()))
now_page = total_cache = 0
for _ in range(q):
    input_list = str(sys.stdin.readline().strip())
    if len(input_list) == 1:
        a = input_list[0]
    else:
        a = input_list[0]
        b = input_list[2::]
    if a == "A":
        now_page = access(now_page, int(b))
    elif a == "B":
        now_page = backward(now_page)
    elif a == "F":
        now_page = forward(now_page)
    elif a == "C":
        back_pages = compress()

    # print(f"{back_pages} | {now_page} | {next_pages[::-1]}")
    # print(total_cache)

print(now_page)
if len(back_pages):
    print(*back_pages[::-1])
else:
    print(-1)
if len(next_pages):
    print(*next_pages[::-1])
else:
    print(-1)