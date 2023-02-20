n = int(input())
for _ in range(n):
    h, w, m = map(int, input().split())
    ehd = m%h
    ghtn = m//h + 1
    if m%h == 0:
        ehd = h
        ghtn = m//h
        print(ehd*100+ghtn)
    else:
        print(ehd*100+ghtn)
