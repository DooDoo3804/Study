char_list = list(input())
char_list.sort()
stack1 = []
stack2 =''
for char in char_list:
    if char.isnumeric():
        stack1.append(char)
    else:
        stack2 += char
result = 0
for i in stack1:
    result += int(i)
print(stack2+str(result))