n = int(input())
num_list = list(map(str, input().split()))
operators = ['+', '-', '*', '//']
operator_list = list(map(int, input().split()))
result = ''
for i, operator in enumerate(operator_list):
    if operator:
        