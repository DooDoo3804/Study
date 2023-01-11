numbers = list(input())
number_list = []
for n in numbers:
    if number_list == []:
        number_list.append(n)
    elif number_list[-1] != n:
        number_list.append(n)
cnt1 = number_list.count('0')
cnt0 = number_list.count('1')
print(min(cnt0, cnt1))