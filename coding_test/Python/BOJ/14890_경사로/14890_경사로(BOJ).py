# 14890_경사로
# 2022-08-19
import sys
sys.stdin = open('input', 'r')
N, L = map(int, input().split())
map_list = []
L_count = count = degree = L_total = 0
pos_way = 1
for i in range(N):
    map_list.append(list(map(int, input().split())))
