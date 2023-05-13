import sys
n = int(sys.stdin.readline().strip())
w_list = sys.stdin.readline().strip()
dksh_list = []
for w in w_list:
    if w == "D" or w == "K" or w == "S" or w == "H":
        dksh_list.append(w)
result = 0
dksh = [0, 0, 0, 0]
for w in dksh_list:
    if w == "D":
        dksh[0] += 1
    elif w == "K":
        dksh[1] += dksh[0]
    elif w == "S":
        dksh[2] += dksh[1]
    elif w == "H":
        dksh[3] += dksh[2]
print(dksh[3])
