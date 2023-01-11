# 1213_String활용
# 2022-08-12

import sys
sys.stdin = open('input.txt', 'r', encoding='utf-8')

for _ in range(10):
    t = int(input())
    test_word = list(input())
    test_string = list(input())
    test_string_len = test_word_len = 0

    for _ in test_string:
        test_string_len += 1

    for _ in test_word:
        test_word_len += 1

    count = 0
    for i in range(test_string_len-test_word_len+1):
        for j in range(test_word_len):
            if test_word[j] != test_string[i+j]:
                break
        else:
            count += 1
    print('#{} {}' .format(t, count))
