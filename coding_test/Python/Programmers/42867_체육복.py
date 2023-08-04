def solution(n, lost, reserve):
    losts = set(lost) - set(reserve)
    reserves = set(reserve) - set(lost)
    m = len(losts)
    for i, l in enumerate(losts):
        if (l - 1) in reserves:
            reserves.remove(l - 1)
        elif (l + 1) in reserves:
            reserves.remove(l + 1)
        else :
            n -= 1
    answer = n
    return answer