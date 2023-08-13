n = int(input())
r = 31
m = 1234567891
start = 96
result = 0
count = 0
char_list = list(input())
for char in char_list:
    result += (ord(char) - start) * r**count
    count += 1
print(result % m)