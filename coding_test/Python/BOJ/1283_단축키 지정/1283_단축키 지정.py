import sys
n = int(sys.stdin.readline().strip())
words = []
for _ in range(n):
    words.append(sys.stdin.readline().strip().split())
key_words = []

for i, word in enumerate(words):

    flag = True
    # 첫 단어 비교
    for j, w in enumerate(word):
        if w[0].lower() not in key_words:
            key_words.append(w[0].lower())
            nw = w[0:0] + '[' + w[0:0 + 1] + ']' + w[0 + 1::]
            words[i][j] = nw
            flag = False
            break
        else:
            continue

    # 하나씩 비교
    index = 0
    if flag:
        for j, w in enumerate(word):
            for k, v in enumerate(w):
                if v.lower() not in key_words:
                    key_words.append(v.lower())
                    nw = w[0:k] + '[' + w[k:k + 1] + ']' + w[k + 1::]
                    words[i][j] = nw
                    flag = False
                    break
            if not flag:
                break

for word in words:
    print(*word)