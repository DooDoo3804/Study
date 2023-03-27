def factorial(i):
    if i == 1 or i == 0:
        return 1
    else:
        return i * factorial(i-1)


n, k = map(int, input().split())

mother = factorial(n)
son = factorial(k) * factorial(n-k)
print(int(mother/son))