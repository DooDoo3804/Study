# 1221_GNS
# 2022-08-12

import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    tc, tc_len = map(str, input().split())
    test_string = list(map(str, input().split()))
    num_count = [i for i in range(10)]
    num_dict = {
        'ZRO': 0,
        'ONE': 0,
        'TWO': 0,
        'THR': 0,
        'FOR': 0,
        'FIV': 0,
        'SIX': 0,
        'SVN': 0,
        'EGT': 0,
        'NIN': 0,
    }
    for word in test_string:
        for i in num_dict.keys():
            if i == word:
                num_dict[word] += 1


    print('#{}' .format(t))
    for dict_key, dict_value in num_dict.items():
        for _ in range(dict_value):
            print('{}'.format(dict_key), end=' ')
    print()