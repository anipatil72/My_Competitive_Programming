from collections import deque

def is_valid(x, y, n, m):
    return 0 <= x < n and 0 <= y < m

def find_path(n, m, maze):
    start_x, start_y = None, None
    monster_positions = []
    for i in range(n):
        for j in range(m):
            if maze[i][j] == 'A':
                start_x, start_y = i, j
            elif maze[i][j] == 'M':
                monster_positions.append((i, j))

    moves = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    directions = ['R', 'D', 'L', 'U']

    visited = [[False] * m for _ in range(n)]
    queue = deque([(start_x, start_y, [])])

    while queue:
        x, y, path = queue.popleft()
        visited[x][y] = True

        for (dx, dy), direction in zip(moves, directions):
            new_x, new_y = x + dx, y + dy
            if is_valid(new_x, new_y, n, m) and maze[new_x][new_y] != '#' and not visited[new_x][new_y]:
                if all((new_x, new_y) != monster for monster in monster_positions):
                    if new_x == 0 or new_x == n - 1 or new_y == 0 or new_y == m - 1:
                        return "YES\n{}\n{}".format(len(path) + 1, ''.join(path + [direction]))
                    queue.append((new_x, new_y, path + [direction]))

    return "NO"

n, m = map(int, input().split())
maze = [input() for _ in range(n)]

result = find_path(n, m, maze)
print(result)
