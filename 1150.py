from collections import defaultdict, deque
import math

def bfs(graph, parent, depth):
    parent[1] = 0
    depth[1] = 0
    queue = deque([1])
    while queue:
        curr = queue.popleft()
        for neighbor in graph[curr]:
            if parent[neighbor] == -1:
                parent[neighbor] = curr
                depth[neighbor] = depth[curr] + 1
                queue.append(neighbor)

def preprocess(n, parent):
    max_log = int(math.log2(n)) + 1
    up = [[0 for _ in range(max_log)] for _ in range(n+1)]
    
    for i in range(1, n+1):
        up[i][0] = parent[i]

    for j in range(1, max_log):
        for i in range(1, n+1):
            up[i][j] = up[up[i][j-1]][j-1]
    
    return up

def lca(u, v, up, depth):
    if depth[u] < depth[v]:
        u, v = v, u

    max_log = len(up[0])
    for i in range(max_log - 1, -1, -1):
        if depth[u] - (1 << i) >= depth[v]:
            u = up[u][i]
    
    if u == v:
        return u

    for i in range(max_log - 1, -1, -1):
        if up[u][i] != up[v][i]:
            u = up[u][i]
            v = up[v][i]
    
    return parent[u]

n, k = map(int, input().split())
x, y = map(int, input().split())
tasks = list(map(int, input().split()))

graph = defaultdict(list)
for _ in range(n-1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

parent = [-1] * (n + 1)
depth = [-1] * (n + 1)
bfs(graph, parent, depth)

up = preprocess(n, parent)

total_distance = 0
current_location = x

for task in tasks:
    total_distance += depth[current_location] + depth[task] - 2 * depth[lca(current_location, task, up, depth)]
    current_location = task

total_distance += depth[current_location] + depth[y] - 2 * depth[lca(current_location, y, up, depth)]
print(total_distance)
