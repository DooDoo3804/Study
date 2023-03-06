import sys
d, k = map(int, sys.stdin.readline().split())
# a b a+b a+b+b (a+b)*2+b (a+b)*3+b+2


def co1(d):
    if d == 3 or d == 4:
        return 1
    else:
        return co1(d-1)+co1(d-2)


def co2(d):
    if d == 3:
        return 0
    elif d == 4 or d == 5 :
        return 1
    else:
        return co2(d-1)+co2(d-2)


a_coeff = co1(d)
b_coeff = co1(d) + co2(d)
a_count = b_count = 0
while True:
    b_count += 1
    if not (k-b_coeff*b_count)%a_coeff:
        a_count = (k-b_coeff*b_count)//a_coeff
        if a_count < b_count:
            break
print(a_count)
print(b_count)
