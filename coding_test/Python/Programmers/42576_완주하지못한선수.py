def solution(participant, completion):
    dict = {}
    hashSum = 0

    for i, v in enumerate(participant):
        dict[hash(v)] = v
        hashSum += hash(v)
    for i, v in enumerate(completion):
        hashSum -= hash(v)
        
    answer = dict[hashSum]
    return answer