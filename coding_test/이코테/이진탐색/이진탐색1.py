"""
집합 자료형으로 풀이
"""
N = int(input())
n_list = list(map(int, input().split()))
M = int(input())
m_list = list(map(int, input().split()))
for m in m_list:
    if m in n_list:
        print('yes', end=' ')
    else :
        print('no', end=' ')

print()
print('==========================')

"""
이진 탐색으로 풀이
"""
# N = int(input())
# n_list = list(map(int, input().split()))
# M = int(input())
# m_list = list(map(int, input().split()))

n_list = sorted(n_list)
start = 0
end = len(n_list)
def find_num(start, end, num):
    mid_num = (start+end) // 2
    if num == n_list[mid_num]:
        return True
    elif start == end:
        return False
    elif num > n_list[mid_num]:
        s = mid_num+1
        e = end
        return find_num(s, e, num)
    elif num < n_list[mid_num]:
        s = start
        e = (start+end)//2
        return find_num(s, e, num)

for m in m_list:
    if find_num(start, end, m):
        print('yes', end=' ')
    else:
        print('no', end=' ')
print()
print('==========================')
"""
계수 정렬 풀이
"""

check = [0]*1000001
for n in n_list:
    check[n] += 1
for m in m_list:
    if check[m]:
        check[m] -= 1
        print('yes', end=' ')
    else:
        print('no', end=' ')