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
    global direction
    direction -= 1
    if direction == -1:
        direction =3

count = 0
turn_count = 0

while True:
    turn_left()
    nx = x + move_list[direction][1]
    ny = y + move_list[direction][0]
    turn_count += 1
    if player_map[nx][ny] != 1 and init_map[nx][ny] != 1 :
        x = nx
        y = ny
        count += 1
        print(count)
    elif turn_count >= 4:
        x += move_list[direction-2][1]
        y += move_list[direction-2][0]
    player_map[x][y] = 1
    pass