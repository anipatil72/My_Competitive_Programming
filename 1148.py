from collections import defaultdict

class BITree:
    def __init__(self, n):
        self.bit = [0] * (n + 1)
        
    def update(self, idx, val):
        while idx <= len(self.bit) - 1:
            self.bit[idx] += val
            idx += idx & -idx
            
    def query(self, idx):
        s = 0
        while idx:
            s += self.bit[idx]
            idx -= idx & -idx
        return s

def dfs(v, parent):
    global time
    parents[v] = parent
    entry[v] = time
    time += 1
    for u in tree[v]:
        if u != parent:
            dfs(u, v)
    exit[v] = time
    time += 1

n = int(input())
tree = defaultdict(list)

for _ in range(n-1):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)

entry, exit, parents = {}, {}, {1: None}
time = 1
dfs(1, -1)

bit_active = BITree(2 * n)
bit_ancestors = BITree(2 * n)

q = int(input())
for _ in range(q):
    c, v = map(int, input().split())
    if c == 1:
        bit_active.update(entry[v], 1)
        bit_active.update(exit[v] + 1, -1)
        bit_ancestors.update(v, 1)
    elif c == 2:
        node = v
        while node:
            if bit_ancestors.query(node) > 0:
                bit_ancestors.update(node, -1)
                bit_active.update(entry[node], -1)
                bit_active.update(exit[node] + 1, 1)
            node = parents[node]
    else:
        print(1 if bit_active.query(entry[v]) > 0 else 0)
