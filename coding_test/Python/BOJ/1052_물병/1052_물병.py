x, y = map(int, input().split())
x_binary = ''
x_sub = x
answer = 0
while x != 0:
    x_binary = str(x % 2) + x_binary
    x = x // 2

while x_binary.count('1') > y:
    index = x_binary[::-1].index('1')
    x_sub += 2**(index)
    x = x_sub
    answer += 2**(index)
    x_binary = ''
    while x != 0:
        x_binary = str(x % 2) + x_binary
        x = x // 2

print(answer)
# answer = 0
# count = 0
# if y == 1:
#     answer = 2**(len(x_binary)) - x_sub
# elif y < bottles:
#     while True:
#         if x_binary[0] == '1':
#             count += 1
#         x_binary = x_binary[1::]
#         if count == y - 1:
#             break
#     if answer != 1:
#         while x_binary[0] == '0':
#             x_binary = x_binary[1::]
#         answer = 2 ** (len(x_binary))
#         while x_binary != '':
#             if x_binary[0] == '1':
#                 answer -= 2**(len(x_binary)-1)
#             x_binary = x_binary[1::]
