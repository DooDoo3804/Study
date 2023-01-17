i, j = map(str, input().split())

print(max(int(i[::-1]), int(j[::-1])))