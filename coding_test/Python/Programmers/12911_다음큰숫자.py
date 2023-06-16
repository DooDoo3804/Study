def make_binary(a):
    bi_num = ""
    while a != 0:
        if a % 2 == 1:
            bi_num = "1" + bi_num
        elif a % 2 == 0:
            bi_num = "0" + bi_num
        a = a // 2
    return bi_num
def solution(n):
    answer = make_binary(n)
    count1 = count2 = 0
    for a in answer:
        if a == "1":
            count1 += 1
            
    while True:
        count2 = 0
        n += 1
        sub_bi = make_binary(n)
        for a in sub_bi:
            if a == "1":
                count2 += 1
        if count1 == count2:
            answer =  n
            break
    return answer