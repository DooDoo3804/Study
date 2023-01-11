def solution(board, skill):
    for num_list in skill:
        if num_list[0] == 1:
            for j in range(num_list[1], num_list[3]+1):
                for i in range(num_list[2], num_list[4]+1):
                    board[j][i] -= num_list[5]
        else:
            for j in range(num_list[1], num_list[3]+1):
                for i in range(num_list[2], num_list[4]+1):
                    board[j][i] += num_list[5]
    answer = 0
    for row in board:
        for i in row:
            if i >= 1:
                answer += 1
    return answer

# 효율성 검사에서 시간초과 발생