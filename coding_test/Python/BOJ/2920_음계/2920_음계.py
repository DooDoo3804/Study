notes = list(map(int, input().split()))

if (notes == [i+1 for i in range(8)]):
    print("ascending")
elif (notes == [8-i for i in range(8)]):
    print("descending")
else : print("mixed")