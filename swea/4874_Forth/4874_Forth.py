# 4874_Forth
# 2022-08-23
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    stack = []
    top = -1
    form = list(map(str, input().split()))
    # 숫자가 아닌 리스트
    not_num = ['+', '-', '/', '*', '.',]
    # 연산자 수행 함수 num1 num2 op를 받고 계산 값을 반환
    def my_operator(num1, num2, op):
        my_ops = {
            '+': lambda x, y: x + y,
            '-': lambda x, y: x - y,
            '*': lambda x, y: x * y,
            '/': lambda x, y: x // y,
        }
        return my_ops[op](int(num2), int(num1))

    for char in form:
        # char가 숫자가 아닌 경우
        if char in not_num:
            # 연산자인 경우
            if char != '.':
                # stack에 숫자가 2개 이하일 때 연산자가 들어오면 error
                if top <= 0:
                    result = 'error'
                    break
                else :
                    # 정상적이면 연산 수행하고 stack에 재반환
                    num1 = stack.pop()
                    num2 = stack.pop()
                    if char == '/' and num2 == 0:
                        result = 'error'
                        break
                    result = my_operator(num1, num2, char)
                    stack.append(result)
                    top -= 1
            else:
                # .이 들어와 출력해야 하는 경우
                # 숫자가 2개 이상 남았으면 error 출력
                if top > 0:
                    result = 'error'
                    break
                # 하나가 남았으면 그대로 출력
                result = stack.pop()
                break
        # 숫자인 경우 stack에 추가
        else :
            stack.append(char)
            top += 1
    print('#{} {}' .format(t, result))