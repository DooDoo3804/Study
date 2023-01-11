import math


def solution(fees, records):
    cars = []
    time = []
    for record in records:
        t, n, s = map(str, record.split())
        if n not in cars:
            cars.append(n)
            time.append([[t, s]])
        else:
            time[cars.index(n)].append([t, s])

    def cal_fee(stack):
        sub_stack = []
        result = 0
        sub_time = 0
        while stack:
            a = stack.pop(0)
            if a[-1] == "IN" and stack:
                sub_stack.append([int(a[0][0]) * 10 + int(a[0][1]), int(a[0][3]) * 10 + int(a[0][4])])
                continue
            elif a[-1] == "OUT" and sub_stack:
                b = sub_stack.pop()
                sub_time += ((int(a[0][0]) * 10 + int(a[0][1])) * 60 + int(a[0][3]) * 10 + int(a[0][4])) - (
                            (b[0]) * 60 + int(b[1]))
            elif a[-1] == "IN":
                sub_time += 1439 - ((int(a[0][0]) * 10 + int(a[0][1])) * 60 + int(a[0][3]) * 10 + int(a[0][4]))

        if sub_time <= fees[0]:
            result += fees[1]
        elif sub_time > fees[0]:
            result += fees[1] + math.ceil((sub_time - fees[0]) / fees[2]) * fees[3]
        return result

    answer = []
    sorted_car = sorted(cars)
    for car in sorted_car:
        answer.append(cal_fee(time[cars.index(car)]))

    return answer