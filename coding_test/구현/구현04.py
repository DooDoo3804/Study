n, m = map(int, input().split())
player_map = []
for _ in range(n):
    player_map.append([0]*m)
x, y, direction = map(int, input().split())
player_map[x][y] = 1
init_map = []
for _ in range(n):
    init_map.append(list(map(int, input().split())))
move_list = [[-1, 0], [0, 1], [1, 0], [0, -1]]

def turn_left():
    direction -= 1
    if direction == -1:
        direction =3

count = 0
turn_count = 0

while True:
    pass